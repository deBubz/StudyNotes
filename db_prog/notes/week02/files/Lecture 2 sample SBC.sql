-- SBC_Contract_Create procedure
-- The purpose of the procedure is to automatically create new weekly contracts for the Snowy Benefits Cap
-- The new contract ID's are related by using the specified deal numbers
--
-- Written by Laurie Benkovich 15 November 2004
--
-- **************************************************************************************************************



CREATE OR REPLACE PROCEDURE Sbc_Contract_Create(p_referenceDate    DATE   DEFAULT TRUNC(SYSDATE))
AS

TYPE r_dealRecord IS RECORD(deal_number  CONTRACTS.CONTRACTS.DEAL_NUMBER%TYPE,
                            contract_id  CONTRACTS.CONTRACTS.CONTRACT_ID%TYPE,
                            deal_name    VARCHAR2(60),
			    price        NUMBER,
			    quantity     NUMBER,
			    state        VARCHAR2(5));
			    
TYPE c_dealRecord IS TABLE OF r_dealRecord INDEX BY BINARY_INTEGER;

v_coll_deals            c_dealRecord;
v_contract_id           NUMBER := 0;   
v_rev                   NUMBER := 0;               
v_marker                VARCHAR2(100);
v_error                 VARCHAR2(100);
v_contractStartDate     DATE;
v_contractEndDate       DATE;
v_tradeDate             DATE := TO_DATE('30-APR-2004', 'DD-MON-YYYY');
v_contractName          CONTRACTS.CONTRACTS.CONTRACT_NAME%TYPE;   -- at this stage its 100 bytes
v_contractComments      CONTRACTS.CONTRACTS.COMMENTS%TYPE;   -- at this stage its 200 bytes
v_dealNumber            CONTRACTS.CONTRACTS.DEAL_NUMBER%TYPE;  -- at this stage its 25 bytes
v_traderName            CONTRACTS.CONTRACTS.TRADER_NAME%TYPE; 
v_state                 CONTRACTS.FIXED_FORWARD.STATE%TYPE;
v_fixedPrice            CONTRACTS.FIXED_FORWARD.FIXED_PRICE%TYPE; 
v_fixedQuantity         CONTRACTS.FIXED_FORWARD.FIXED_QUANTITY%TYPE;
v_sourceType            CONTRACTS.FIXED_FORWARD.SOURCE%TYPE;
v_sculpturedCount       NUMBER;
v_emailText             VARCHAR2(2048);
     

-- This is a local procedure that I use to printout trace information while debugging the program
PROCEDURE DEBUG(text  VARCHAR2) IS 
BEGIN
    DBMS_OUTPUT.PUT_LINE(text);
END;

-- This is a local procedure that I call to insert a message into the TX.MESSAGE_LOG table. These messages will enable me to 
-- check the status of the job when it runs as a batch job
PROCEDURE recordMessage(p_message   VARCHAR2)  IS
--
PRAGMA AUTONOMOUS_TRANSACTION;  
--
BEGIN
      INSERT INTO TX.MESSAGE_LOG(TIME, message, ID, USERID) VALUES  (SYSDATE, p_message, 0, USER);
	  COMMIT;
END;
--
-- ************************************************************* EMAIL 
-- Send an email to the persons listed in the paramaters file   
procedure sendEmail(p_textBody IN VARCHAR2) IS

v_emailName   VARCHAR2(35);
CURSOR c1 is SELECT c_value from parameters
             WHERE  name = 'SBC Email List'
             AND    n_value = 1;
BEGIN
FOR r1 in c1
LOOP		   
contracts.html_mail.html_email(
  p_to      => r1.c_value||'@originenergy.com.au',
  p_from    => 'SBC_Contract_Creation@NETS',
  p_subject =>  'This is a test',   -- emailHeader,
  p_text    =>  p_textBody,         -- emailContent,
  p_html    =>  NULL, 
  p_smtp_hostname =>  'sydnn004.originenergy.com.au', 
  p_smtp_portnum  => '25');
--
END LOOP;
  
END;
-- ************************************************************* EMAIL 



-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--   This procedure will take a date and return the Mondays Date as the start date and Sundays date as the end date
--   It is assumed that this program will run on a Sunday, however it is possible that the program could be delayed
--   and the actual run time is after Sunday. The process then should thake take of such situations.
--   NOTE that Monday is the 2nd day of the week
PROCEDURE determineStartEndDates(p_dateNow    IN  DATE,
                                 p_startDate  OUT DATE, 
                                 p_endDate    OUT DATE) IS
-- Declare the variables here
v_currentStartDate        DATE;
BEGIN
    v_marker := 'Starting procedure determineStartEndDates';
    
    SELECT p_dateNow + (2 -  TO_CHAR(p_dateNow,  'D'))  INTO p_startDate
    FROM    dual;

    p_endDate := p_startDate + 6;
					
    IF TO_CHAR(p_startDate, 'DY') != 'MON' OR TO_CHAR(p_endDate, 'DY') != 'SUN' THEN
       recordMessage('SBC - Start / End Days are not MON and SUN  -  The dates are '||p_startDate||' and '||p_endDate);
       RAISE_APPLICATION_ERROR(-20412, 'Start / End Dates are not MON and SUN');
    END IF;
END;															   
--     ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

PROCEDURE loadArray(p_coll_deals    IN OUT c_dealRecord) IS
-- This procedure will load the array that is used to hold the data that will be used by the application.
-- The array contains the details for the 12 contract ID's that are to be created each week
-- This data may ultimately end up in a Database table, however, until authorisation is provided to create and populate such a table 
-- the data will be hardcoded here
BEGIN
--        DEBUG('This is where you will populate the array');
  p_coll_deals(1).deal_number := 'T200425511';   p_coll_deals(1).deal_Name := 'NSW  Variable Price and Quantity';   p_coll_deals(1).price := 50;   p_coll_deals(1).quantity := 50; p_coll_deals(1).state := 'NSW';
  p_coll_deals(2).deal_number := 'T200425512';   p_coll_deals(2).deal_Name := 'NSW    Variable Price and Quantity';   p_coll_deals(2).price := 0;   p_coll_deals(2).quantity := 0; p_coll_deals(2).state := 'NSW';
  p_coll_deals(3).deal_number := 'T200425513';   p_coll_deals(3).deal_Name := 'NSW    Variable Price and Quantity';   p_coll_deals(3).price := 0;   p_coll_deals(3).quantity := 0; p_coll_deals(3).state := 'NSW';
  p_coll_deals(4).deal_number := 'T200425521';   p_coll_deals(4).deal_Name := 'SNWY Variable Price and Quantity';   p_coll_deals(4).price := 50;   p_coll_deals(4).quantity := 200; p_coll_deals(4).state := 'SNWY';
  p_coll_deals(5).deal_number := 'T200425522';   p_coll_deals(5).deal_Name := 'SNWY  Variable Price and Quantity';   p_coll_deals(5).price := 0;   p_coll_deals(5).quantity := 0; p_coll_deals(5).state := 'SNWY';
  p_coll_deals(6).deal_number := 'T200425523';   p_coll_deals(6).deal_Name := 'SNWY Variable Price and Quantity';   p_coll_deals(6).price := 0;   p_coll_deals(6).quantity := 0; p_coll_deals(6).state := 'SNWY';
  p_coll_deals(7).deal_number := 'T200425531';   p_coll_deals(7).deal_Name := 'VIC 1  Variable Price and Quantity';   p_coll_deals(7).price := 52;   p_coll_deals(7).quantity := 100; p_coll_deals(7).state := 'VIC';
  p_coll_deals(8).deal_number := 'T200425532';   p_coll_deals(8).deal_Name := 'VIC 1  Variable Price and Quantity';   p_coll_deals(8).price := 0;   p_coll_deals(8).quantity := 0; p_coll_deals(8).state := 'VIC';
  p_coll_deals(9).deal_number := 'T200425533';   p_coll_deals(9).deal_Name := 'VIC 1 Variable Price and Quantity';   p_coll_deals(9).price := 0;   p_coll_deals(9).quantity := 0; p_coll_deals(9).state := 'VIC';
  p_coll_deals(10).deal_number := 'T200425541';   p_coll_deals(10).deal_Name := 'VIC 2  Variable Price and Quantity';   p_coll_deals(10).price := 50;   p_coll_deals(10).quantity := 150; p_coll_deals(10).state := 'VIC';
  p_coll_deals(11).deal_number := 'T200425542';   p_coll_deals(11).deal_Name := 'VIC 2 Variable Price and Quantity';   p_coll_deals(11).price := 0;   p_coll_deals(11).quantity := 0; p_coll_deals(11).state := 'VIC';
  p_coll_deals(12).deal_number := 'T200425543';   p_coll_deals(12).deal_Name := 'VIC 2  Variable Price and Quantity';   p_coll_deals(12).price := 0;   p_coll_deals(12).quantity := 0; p_coll_deals(12).state := 'VIC';
END;
--     ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

PROCEDURE printArray(p_coll_deals    IN  c_dealRecord) IS
-- This procedure will print out the data that is being stored in the array. The loadarray procedure populates the array 
-- The array is used throughout the application. During the debug phase of the program, call this  procedure to view the contents of the array
   v_counter           NUMBER;
   v_nrOfElements      NUMBER;
BEGIN
    v_nrOfElements := p_coll_deals.COUNT;
    DEBUG(CHR(10)||'This is the contents of the deals array');
--
	FOR v_counter IN 1 .. v_nrOfElements LOOP
	     DEBUG(p_coll_deals(v_counter).deal_number||'      '||p_coll_deals(v_counter).deal_Name||'      '||p_coll_deals(v_counter).price||'      '||p_coll_deals(v_counter).quantity||'      '||p_coll_deals(v_counter).state);  -- need to finish off the fields
	END LOOP;
--
END;
--     ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

-- &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
-- This function will check the contracts table to determine if a contract with the given deal number and date range
-- exists in the contracts table.
FUNCTION contractExists(p_dealNumber IN CONTRACTS.CONTRACTS.DEAL_NUMBER%TYPE , 
                        p_contractStartDate DATE,  
			p_contractEndDate DATE)  RETURN BOOLEAN AS

v_nrOfContracts        NUMBER;
BEGIN
     v_marker := 'Checking if contract already exists'; 
     SELECT COUNT(*) INTO v_nrOfContracts
	 FROM     contracts.contracts
	 WHERE    deal_number = p_dealNumber
	 AND      start_date = p_contractStartDate
	 AND      finish_date = p_contractEndDate;
     
	 RETURN  v_nrOfContracts > 0;
	 
END  contractExists;
--
--  &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

-- This is the start of the procedure  SBC_Contract_Create
BEGIN
--
-- TO_DO need to ensure that the contract does not already exist

v_marker := 'Procedure Started'; 

recordMessage('SBC - Started - '||v_marker);

loadArray(v_coll_deals);
printArray(v_coll_deals);

determineStartEndDates(p_referenceDate,
                       v_contractStartDate,
		       v_contractEndDate); 

v_emailText := 'SBC Contract creation has generated the following Contract_IDs for period '||v_contractStartDate||' and '||v_contractEndDate||CHR(10);												   
												   
FOR v_counter IN 1 .. v_coll_deals.COUNT         --Create a loop here to traverse through the Deals that are to be processed   DEAL LOOP
LOOP

BEGIN                        -- This block will handle the contract insert with exception handler

v_contract_id := 0;     -- Setting these values to zero will cause the system to create a new contract_id
v_rev := 0;
v_dealNumber :=  v_coll_deals(v_counter).deal_number;       
v_traderName := 'Cameron Fisher';                                                                          -- This is hard coded for automatic generation
v_state := v_coll_deals(v_counter).state;                                                             
v_fixedPrice := v_coll_deals(v_counter).price;                                                       
v_fixedQuantity := v_coll_deals(v_counter).quantity;                                                             

v_contractName :=   v_dealNumber||'-'||v_state||'-Cal'||TO_CHAR(v_contractStartDate, 'YYYY');  
v_contractComments := v_state||' cal'||TO_CHAR(v_contractStartDate, 'YYYY')||' from '||v_contractStartDate||' to '||v_contractEndDate||' (Variable Quantity and Price)';

          -- if the contract exists then don't create again
          IF contractExists(v_dealNumber, v_contractStartDate, v_contractEndDate)  THEN
             v_emailText := v_emailText||CHR(10)||'Deal Number = '||v_dealNumber||'   Start Date = '||v_contractStartDate||'   End Date =  '||v_contractEndDate;
             v_emailText := v_emailText||CHR(10)||'Deal with those dates exists in the Database - Contract NOT created';
	     GOTO contract_exists;
          END  IF;

--RAISE_APPLICATION_ERROR(-20123, 'Lauries break');

-- Note for the first three paramaters - I wanted to use named paramaters in the function call so that it is easier to understand
-- however, the contract and the rev parameter is an IN OUT paramater and the system would not allow me to intermix
-- positional and named parameters. When I place the parameters before the IN OUT types as positional all seems OK
-- Laurie 

v_marker := 'Before call to enter_contracts';

CONTRACTS.ENTRY.enter_contracts( 
  'ADD' ,                                                
  v_contract_id,                                  
  v_rev,                                                
  in_contract_name => v_contractName,     
  in_contract_group => 'Cap',
  in_counterparty => '116',
  in_contract_type => 'FIXED_FORWARD', 
  in_deal_number => v_dealNumber ,              
  in_start_date => v_contractStartDate,               
  in_finish_date =>  v_contractEndDate,      
  in_trade_date => v_tradeDate,                       -- This value was taken from the spreadsheet, need to ensure what the actual date should be
  in_brokerage => 0,                                  -- These contracts will not be brokered so brokerage details not required 
  in_brokerage_cpty => 0,                 
  in_brokerage_date => NULL,              --                                                     - " -
  in_first_settlement => NULL,                 
  in_settlement_frequency => 'MARKET',
  in_settlement_offset => 0,
  in_rollstart => 0,
  in_portfolio => 'TRADING',
  in_forcemajeure => 'NO',
  in_reg_disr => 'YES',
  in_comments => v_contractComments,                                                 
  in_scenario => 'NO',                                                                                          
  in_trading_group => 'CAP-STD',       
  in_trading_program => 'MKT TRDNG', 
  in_trader_name => v_traderName,                                                         
  in_settled => 'YES' ) ;                                                                   -- Why would this be a yes value - check
 
 v_marker := 'After call to enter_contracts';
 recordMessage('SBC -  '||v_marker);

-- DEBUG('Contract ID/Rev is '||contracts.ENTRY.new_contract_id||' / '||contracts.ENTRY.new_rev);
 
 EXCEPTION
      WHEN OTHERS THEN 
	      v_error := SUBSTR(SQLERRM, 1,100);
	       recordMessage ('SBC - At Contract creation - Error encountered  '||v_marker||' with '||v_error);
           RAISE;
END;




 DECLARE
 --
 v_calendarState      VARCHAR2(5);
 --
  BEGIN       -- This block handles the FIXED_FORWARD contracts
  v_marker := 'Before the call to Enter_fixed_forward';  
  recordMessage('SBC -  '||v_marker); 
  
  -- As far as the holiday calendars are concerned, when the state is SNWY then the holiday calander is to be NSW
  CASE v_state
          WHEN 'SNWY' THEN 
		       v_calendarState := 'NSW';
	      ELSE
		       v_calendarState := v_state;
  END CASE;
 --
 -- Check the Trading analysis table to make sure that the sculptured data is available for this deal number and the time range. 
 -- If no sculptured data found then make the source type FIXED 
 --
   v_sourceType := 'SCULPTURED';
      SELECT count(*) INTO v_sculpturedCount
      FROM   TA_SCULPTURED_COMPONENTS
      WHERE  Deal_number =  v_dealNumber      
      AND    period_from_date BETWEEN v_contractStartDate AND v_contractEndDate;
 --
      IF v_sculpturedCount = 0 
      THEN
	     v_sourceType := 'FIXED';
      END IF;
 
CONTRACTS.ENTRY.enter_fixed_forward(in_contract_id => v_contract_id,
                                    in_rev => v_rev,
                                    in_source => v_sourceType,
                                    in_direction => 'B',
                                    in_state =>   v_state,
                                    in_fixed_price => v_fixedPrice,
                                    in_fixed_quantity  => v_fixedQuantity,
                                    in_calendar  => 32,
                                    in_escalator => 'NONE',
                                    in_escalator_base => 1,
                                    in_escalator_type => 'PRICE',
                                    in_siteid => NULL,
                                    in_sculpture_holiday => v_calendarState||'GazettedHolidays');
--															
v_marker := 'After the call to Enter_fixed_forward';
recordMessage('SBC -  '||v_marker);
 --
EXCEPTION
      WHEN OTHERS THEN  
	      v_error := SUBSTR(SQLERRM, 1,100);
	       recordMessage( 'SBC - Error encountered  '||v_marker||' with '||v_error);
      RAISE;     
END;  

v_marker := 'Before enter into Sculptured Components'; 
-- DEBUG(v_marker);

BEGIN
v_marker := 'About to enter sculptured components';
  IF v_sculpturedCount > 0 THEN
   -- If we got here then data was found in the TA Sculptured Components table 	 
     v_marker := 'About to insert into contracts.sculptured_components';
     INSERT INTO contracts.sculptured_components (CONTRACT_ID, REV, DAY_CODE, TIME_CODE, PERIOD_CODE, PERIOD_FROM_DATE, PERIOD_TO_DATE, CONSUMPTION, RATE, UNIT_TYPE, PRD_COMP_TYPE, CHANGED_DATE, CHANGED_BY, CALENDAR)
     (SELECT v_contract_id, v_rev , DAY_CODE, TIME_CODE, PERIOD_CODE, period_from_date, period_to_date, CONSUMPTION, RATE, UNIT_TYPE, PRD_COMP_TYPE, SYSDATE, USER, NULL
      FROM   TA_SCULPTURED_COMPONENTS
      WHERE  Deal_number =  v_dealNumber   
      AND    period_from_date BETWEEN v_contractStartDate AND v_contractEndDate); 
   END IF;
 -- While in development, the object TA_SCULPTURED_COMPONENTS is a synonym which points to a database link which is pointing to  the table in TRADINGANALYSIS
--
EXCEPTION
   WHEN OTHERS THEN
	   v_error := SUBSTR(SQLERRM, 1,100);
	   recordMessage( 'SBC - Error encountered  '||v_marker||' with '||v_error);
END;
  
v_marker := 'After enter into Sculptured Components';
-- DEBUG(v_marker);

-- Buildup the body of the email message 
v_emailText := v_emailText||CHR(10)||v_dealNumber||LPAD(v_contract_id,15)||' ';


 <<contract_exists>>
 NULL;       -- The label must be proceded by an executable statement. This is why the NULL is here   
END LOOP;  -- This is the end of the loop that traverses the deal array       (END DEAL LOOP)

v_emailText := v_emailText||CHR(10)||'Run completed at '||to_char(sysdate, 'DD-MON-YYYY HH24:MI:SS');

--debug('About to send the email');
sendEmail(v_emailText);


END  Sbc_Contract_Create;
/
