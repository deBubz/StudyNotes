
/**--------------------------------------------------------------------------+
 *  PACKAGE: PKG_2017Main
 *  AUTHOR: Alessandro Alberga, 12580092
 *  DATE COMPLETED: 27/MAY/2017
 *
 *  ----------------- AUTHORS NOTES -----------------------------------------+
 *  within the following package:--------------------------------------------+
 *  - gV denotes global variable
 *  - v denotes normal variable
 *  - c denotes a constant
 *  - r denotes a row
 *
 *  functionalities:---------------------------------------------------------+
 *  the PKG_2017Main package performs:
 *  - average calculation of TNI consumption values into the
 *    table local_rm16
 *  - writes the total volume values for each tni from
 *    the day after sysdate into a .xml file.
 *  - sends an email with an attached .txt file
 *    containing the forecast data.
 *
 *  running the program:-----------------------------------------------------+
 *  - to forecast data from anywhere in the db, execute
 *    the following:
 *    U12580092.PKG_2017Main.RM16_FORECAST;
 *---------------------------------------------------------------------------+
 */

/**
 *  PKG_2017Main - PACKAGE SPECIFICATION
 *  Entry point: RM16_FORECAST
 */
CREATE OR REPLACE PACKAGE PKG_2017Main AS
    PROCEDURE RM16_FORECAST;
    PROCEDURE CLEAN_FILE_TO_START;
    PROCEDURE INSERT_INTO_LOCAL (pDateLookingAt IN DATE);
    PROCEDURE WRITE_INTO_FILE (pDateLookingAt IN DATE);
    PROCEDURE HANDLE_END_OF_FILE;
    PROCEDURE SEND_EMAIL (pSubject IN VARCHAR2,
                     pRecipient IN VARCHAR2,
                     pSender IN VARCHAR2);
    FUNCTION IS_HOLIDAY (pDate IN DATE) RETURN NUMBER;
    FUNCTION HAVE_HOLIDAY_DATA RETURN NUMBER;
END PKG_2017Main;

/

/**
 *  PKG_2017Main - PACKAGE BODY
 */
CREATE OR REPLACE PACKAGE BODY PKG_2017Main AS
/**
 *  GLOBAL VARIABLES.
 */
    gVMaxDays NUMBER := 14; -- number of days in advance we want to forecast.
    gVFile  utl_file.file_type; -- file we write to.

    -- bottom two are both set in CLEAN_FILE_TO_START to appropriate names.
    gVFileName VARCHAR2(30);

    gVFileDirName VARCHAR2(30) := 'UTL_FILE_DIRECTORY'; -- directory pointer the file is written to.
    gVDashFormat VARCHAR2(20) := 'DD-MON-YY'; -- required to save file in a manner the OS agrees with.
    gVDayFormat VARCHAR2(10) := 'DAY';
    gVDataClob CLOB := '';

/**
 *  This procedure is the main entry point procedure forecasting usage
 *  for gVMaxDays in advance.
 */
PROCEDURE RM16_FORECAST IS
    vSundayToUse DATE := '28/MAY/17'; -- hardcoded sunday date to use when no holiday data present.
    vDateLookingAt DATE := sysdate;
    vHolidayDataItems NUMBER := 0;
BEGIN
    CLEAN_FILE_TO_START();
    vHolidayDataItems := HAVE_HOLIDAY_DATA(); -- checks for any holiday data.
    COMMON.LOG('** Info: Forecasting for ' || gVMaxDays || ' days in advance.');
    COMMON.LOG('** Info: '|| vHolidayDataItems || ' holiday rows found.');

    FOR lday IN 1..gVMaxDays LOOP -- loop for each day we want forecasted.
        vDateLookingAt := sysdate + lday;   -- set the next date.
        IF vHolidayDataItems < 1 AND IS_HOLIDAY(vDateLookingAt) = 1 THEN
            -- we have no holiday data and the day we want to forecast is a holiday.
            INSERT_INTO_LOCAL(vSundayToUse);
        ELSE
            -- forecast for regular day.
            INSERT_INTO_LOCAL(vDateLookingAt);
        END IF;
    END LOOP;

    WRITE_INTO_FILE(sysdate + 1);
    HANDLE_END_OF_FILE(); -- mark file with end </FORECASTS> tag.

    EXCEPTION
    WHEN OTHERS THEN
        -- safe guard: if the program falls over at any point.
        COMMON.LOG('** Info: General exception, something went wrong.');

        -- in case of failiure, close the file and send the email.
        HANDLE_END_OF_FILE();
END RM16_FORECAST;

/**
 *  This procedure takes a param 'pDateLookingAt', finds the average values for each tni,
 *  inserts them into the the local table and commits.
 */
PROCEDURE INSERT_INTO_LOCAL (pDateLookingAt IN DATE) IS
    vToCharDateLookingAt VARCHAR2(20);
    vIsHoliday NUMBER;
BEGIN
    vIsHoliday := IS_HOLIDAY(pDateLookingAt); -- 1 holiday -- 0 not a holiday
    vtoCharDateLookingAt := TO_CHAR(pDateLookingAt, gVDayFormat);
    INSERT INTO local_rm16
            (tni, frmp, lr, statement_type, change_date, day, hh, volume)
                (SELECT tni, frmp, lr, 'FORECAST', sysdate, pDateLookingAt, hh, AVG(volume)
            FROM dbp_admin.v_nem_rm16
            WHERE TO_CHAR(day, gVDayFormat) = vToCharDateLookingAt
            AND IS_HOLIDAY(day) = vIsHoliday
            AND statement_type != 'FORECAST'
            GROUP BY tni, frmp, lr, change_date, pDateLookingAt, hh);
            COMMIT; -- once values are inserted for a project day, commit.
    EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- safeguard: its possible that nothing results from the select.
        COMMON.LOG('** Info: tried to write to file with no valid input.');
END INSERT_INTO_LOCAL;

/**
 *  This procedure is called at the start of every RM16_FORECAST call,
 *  to which it removes any data in the file writing to, beginign a new
 *  file with the version and opening tag.
 */
PROCEDURE CLEAN_FILE_TO_START IS
    vVersionTag VARCHAR2(30) := '<?xml version="1.0"?>';
    vOpeningFileTag VARCHAR2(30) := '<FORECASTS>';
BEGIN
    -- set an appropriate name for the file we append to and the email we will later send. e.g U12580092_30-MAY-17.xml
    gVFileName := 'U12580092_' || to_char((sysdate + 1),gVDashFormat) || '.xml';
    gVEmailAttachmentName := 'U12580092_' || to_char((sysdate + 1),gVDashFormat) || '.txt';
    gVDataClob := ' '; -- remove any data that may be left in clob.

    -- below will cause an exception if it tries to remove
    -- a file that doesn't exist, which will happen when the above
    -- statement hasn't run yet. This ensures that we are never adding
    -- redundant forecast results to the xml file and always using a blank
    -- file to start with.
    BEGIN
        utl_file.fremove(gVFileDirName, gVFileName); -- remove past contents.
        EXCEPTION
        WHEN UTL_FILE.INVALID_OPERATION THEN
        -- safeguard: tried to remove file doesn't exist.
        COMMON.LOG('** Info: attempted to remove file that doesnt exist, file name is now ' || gVFileName);
    END;
    gVFile := utl_file.fopen (gVFileDirName, gVFileName , 'A');

    -- put version tag.
    utl_file.put_line(gVFile, vVersionTag);
    gVDataClob := gVDataClob || vVersionTag; -- also place in clob.

    -- put opening tag.
    utl_file.put_line(gVFile, vOpeningFileTag);
    gVDataClob := gVDataClob || vOpeningFileTag; -- also place in clob.

    utl_file.fclose(gVFile); -- close file
END CLEAN_FILE_TO_START;

/**
 *  This procedure inserts the closing tag in the xml
 *  file when the insertion of data is complete.
 */
PROCEDURE HANDLE_END_OF_FILE IS
    vClosingFileTag VARCHAR2(20) := '</FORECASTS>';
BEGIN
    gVFile := utl_file.fopen (gVFileDirName, gVFileName , 'A');
    utl_file.put_line(gVFile, vClosingFileTag); -- put closing xml tag in file.
    gVDataClob := gVDataClob || vClosingFileTag; -- close data in clob also.
    utl_file.fclose(gVFile);
END HANDLE_END_OF_FILE;

/**
 *  This procedure accepts the param pDateLookingAt and writes to an xml
 *  file and the local clob all the total volume amounts for each TNI.
 */
PROCEDURE WRITE_INTO_FILE (pDateLookingAt IN DATE) IS
    vOpeningTag VARCHAR2(20) := '<forecast>';
    vClosingTag VARCHAR2(20) := '</forecast>';
    vTNITag VARCHAR2(20) := '<TNI>';
    vTHIClosingTag VARCHAR2(20) := '</TNI>';
    vTNITotalTag VARCHAR2(20) := '<TNI_TOTAL>';
    vTNITotalCloseingTag VARCHAR2(20) := '</TNI_TOTAL>';
BEGIN
    gVFile := utl_file.fopen (gVFileDirName, gVFileName, 'A'); -- open file.

    -- loop and write for each TNI.
    FOR currentRow IN (SELECT TNI, SUM(volume) AS "total" FROM local_rm16 where TO_CHAR(day, gVDayFormat) = TO_CHAR((sysdate + 1), gVDayFormat) GROUP BY tni) LOOP
        -- open tag.
        utl_file.put_line(gVFile, vOpeningTag);
        gVDataClob := gVDataClob || vOpeningTag;
        -- thi value.
        utl_file.put_line(gVFile, vTNITag || currentRow.TNI || vTHIClosingTag);
        gVDataClob := gVDataClob || vTNITag || currentRow.TNI || vTHIClosingTag;
        -- tni volume.
        utl_file.put_line(gVFile, vTNITotalTag || currentRow."total" || vTNITotalCloseingTag);
        gVDataClob := gVDataClob || vTNITotalTag || currentRow."total" || vTNITotalCloseingTag;
        -- close tag.
        utl_file.put_line(gVFile, vClosingTag);
        gVDataClob := gVDataClob || vClosingTag;
    END LOOP;

    -- close file.
    utl_file.fclose(gVFile);
    COMMON.LOG('Data written into ' || gVFileName || ' at directory ' || gVFileDirName);
    EXCEPTION
    WHEN NO_DATA_FOUND THEN
        -- safeguard: select statement could potentially return nothing.
        COMMON.LOG('** Info: attempted an insert of data into file ' || gVFileName || ' with no valid data.');
END WRITE_INTO_FILE;


/**
 *  Function determines if a specific parameter date is a holiday.
 *  If the param is a holiday, returns 1
 *  If the param isnt a holiday, return 0
 */
FUNCTION IS_HOLIDAY (pDate IN DATE) RETURN NUMBER -- if date predicting is a holiday but no past holiday data, use sundays
IS
    vIsHoliday NUMBER := 0; -- will never change if no match found.
BEGIN
    -- look to see if dbp_holiday cotains any common date with
    -- the date we send in.
    SELECT count(holiday_date) INTO vIsHoliday FROM dbp_admin.dbp_holiday -- stop search when found
    WHERE holiday_date = pDate and rownum <= 1; -- will put one in variable if true.

    RETURN vIsHoliday;

    EXCEPTION
    WHEN NO_DATA_FOUND THEN
    COMMON.LOG('** Info: in IS_HOLIDAY couldnt find any data from select');
END IS_HOLIDAY;

/**
 *  This function looks for any rows with common dates in both the v_nem_rm16 and
 *  holiday_date objects.
 *  If it finds data, return 1.
 *  If it doesnt find data, return 0.
 */
FUNCTION HAVE_HOLIDAY_DATA RETURN NUMBER
IS
    vNumberOfHolidayData NUMBER := 0; -- will never change if no match found.
BEGIN

    -- select 1 into vNumberOfHolidayData if data is present.
    SELECT COUNT(*) INTO vNumberOfHolidayData
    FROM dbp_admin.v_nem_rm16 v, dbp_admin.dbp_holiday h WHERE h.holiday_date = v.day
    AND rownum <= 1;

    RETURN vNumberOfHolidayData;

    EXCEPTION
    WHEN NO_DATA_FOUND THEN
    COMMON.LOG('** Info: in HAVE_HOLIDAY_DATA couldnt find any data from select');
END  HAVE_HOLIDAY_DATA;

END PKG_2017Main;

