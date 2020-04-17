-- MySQL dump 10.11
--
-- Host: mysql-staff.it.uts.edu.au    Database: jp_practest26
-- ------------------------------------------------------
-- Server version	5.5.38

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `tblLog`
--

DROP TABLE IF EXISTS `tblLog`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblLog` (
  `logTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `logID` int(11) NOT NULL AUTO_INCREMENT,
  `logStudID` varchar(15) DEFAULT NULL,
  `logStudQuestNum` int(11) DEFAULT NULL,
  `logURL` varchar(100) DEFAULT NULL,
  `logMessage` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`logID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblLog`
--

LOCK TABLES `tblLog` WRITE;
/*!40000 ALTER TABLE `tblLog` DISABLE KEYS */;
/*!40000 ALTER TABLE `tblLog` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblQuery`
--

DROP TABLE IF EXISTS `tblQuery`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblQuery` (
  `queryTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `queryID` int(11) NOT NULL,
  `queryDesc` varchar(255) DEFAULT NULL,
  `queryAnswer` varchar(255) DEFAULT NULL,
  `queryActive_flag` tinyint(1) DEFAULT NULL,
  `queryDb` varchar(20) DEFAULT NULL,
  `fk_query_queryLvlqueryType` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`queryID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblQuery`
--

LOCK TABLES `tblQuery` WRITE;
/*!40000 ALTER TABLE `tblQuery` DISABLE KEYS */;

/*!40000 ALTER TABLE `tblQuery` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblQueryLevel`
--

DROP TABLE IF EXISTS `tblQueryLevel`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblQueryLevel` (
  `queryLevelTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `queryLvlQueryType` varchar(50) NOT NULL,
  `queryLvlDescription` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`queryLvlQueryType`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblQueryLevel`
--

LOCK TABLES `tblQueryLevel` WRITE;
/*!40000 ALTER TABLE `tblQueryLevel` DISABLE KEYS */;

/*!40000 ALTER TABLE `tblQueryLevel` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblStudentInfo`
--

DROP TABLE IF EXISTS `tblStudentInfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblStudentInfo` (
  `studInfoStudID` varchar(20) NOT NULL,
  `studInfoUTSID` varchar(20) NOT NULL,
  `studInfoStudName` varchar(60) DEFAULT '',
  PRIMARY KEY (`studInfoStudID`),
  UNIQUE KEY `studInfoUTSID` (`studInfoUTSID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblStudentInfo`
--

LOCK TABLES `tblStudentInfo` WRITE;
/*!40000 ALTER TABLE `tblStudentInfo` DISABLE KEYS */;

/*!40000 ALTER TABLE `tblStudentInfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblStudentTest`
--

DROP TABLE IF EXISTS `tblStudentTest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblStudentTest` (
  `studTestTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `testID` int(11) NOT NULL,
  `studTestStudID` varchar(15) NOT NULL,
  `studTestStartTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `studTestEndTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `studTestSupervisor` varchar(30) DEFAULT NULL,
  `studTestStudName` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`testID`,`studTestStudID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblStudentTest`
--

LOCK TABLES `tblStudentTest` WRITE;
/*!40000 ALTER TABLE `tblStudentTest` DISABLE KEYS */;

/*!40000 ALTER TABLE `tblStudentTest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblStudentTestAttempt`
--

DROP TABLE IF EXISTS `tblStudentTestAttempt`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblStudentTestAttempt` (
  `studTestAttemptHistTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `testID` int(11) NOT NULL,
  `studTestAttemptHistQuestNum` int(11) NOT NULL,
  `studTestAttemptHistStudID` varchar(15) NOT NULL,
  `studTestAttemptHistQueryAns` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`studTestAttemptHistTStamp`,`testID`,`studTestAttemptHistQuestNum`,`studTestAttemptHistStudID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblStudentTestAttempt`
--

LOCK TABLES `tblStudentTestAttempt` WRITE;
/*!40000 ALTER TABLE `tblStudentTestAttempt` DISABLE KEYS */;
/*!40000 ALTER TABLE `tblStudentTestAttempt` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblStudentTestAttemptHist`
--

DROP TABLE IF EXISTS `tblStudentTestAttemptHist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblStudentTestAttemptHist` (
  `studTestAttemptHistTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `testID` int(11) NOT NULL,
  `studTestAttemptHistQuestNum` int(11) NOT NULL,
  `studTestAttemptHistStudID` varchar(15) NOT NULL,
  `studTestAttemptHistQueryAns` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`studTestAttemptHistTStamp`,`testID`,`studTestAttemptHistQuestNum`,`studTestAttemptHistStudID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblStudentTestAttemptHist`
--

LOCK TABLES `tblStudentTestAttemptHist` WRITE;
/*!40000 ALTER TABLE `tblStudentTestAttemptHist` DISABLE KEYS */;

/*!40000 ALTER TABLE `tblStudentTestAttemptHist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblStudentTestHist`
--

DROP TABLE IF EXISTS `tblStudentTestHist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblStudentTestHist` (
  `studTestTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `testID` int(11) NOT NULL,
  `studTestStudID` varchar(15) NOT NULL,
  `studTestStartTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `studTestEndTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `studTestSupervisor` varchar(30) DEFAULT NULL,
  `studTestStudName` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`studTestTStamp`,`testID`,`studTestStudID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblStudentTestHist`
--

LOCK TABLES `tblStudentTestHist` WRITE;
/*!40000 ALTER TABLE `tblStudentTestHist` DISABLE KEYS */;
/*!40000 ALTER TABLE `tblStudentTestHist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblStudentTestQuestion`
--

DROP TABLE IF EXISTS `tblStudentTestQuestion`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblStudentTestQuestion` (
  `studTestQuestTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `testID` int(11) NOT NULL,
  `studTestQuestQuestNum` int(11) NOT NULL,
  `studTestQuestStudID` varchar(15) NOT NULL,
  `studTestQuestAttempt_flag` tinyint(1) DEFAULT NULL,
  `studTestQuestSuccess_flag` tinyint(1) DEFAULT NULL,
  `studTestQuestAttempt_counter` int(11) DEFAULT NULL,
  `studTestQuestLastAttemptTimestamp` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `studTestQuestLastAttemptQueryAns` text,
  `fk_studTestQuest_queryID` int(11) DEFAULT NULL,
  PRIMARY KEY (`testID`,`studTestQuestQuestNum`,`studTestQuestStudID`),
  KEY `fk_studTestQuest_queryID` (`fk_studTestQuest_queryID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblStudentTestQuestion`
--

LOCK TABLES `tblStudentTestQuestion` WRITE;
/*!40000 ALTER TABLE `tblStudentTestQuestion` DISABLE KEYS */;
/*!40000 ALTER TABLE `tblStudentTestQuestion` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblStudentTestQuestionHist`
--

DROP TABLE IF EXISTS `tblStudentTestQuestionHist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblStudentTestQuestionHist` (
  `studTestQuestTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `testID` int(11) NOT NULL,
  `studTestQuestQuestNum` int(11) NOT NULL,
  `studTestQuestStudID` varchar(15) NOT NULL,
  `studTestQuestAttempt_flag` tinyint(1) DEFAULT NULL,
  `studTestQuestSuccess_flag` tinyint(1) DEFAULT NULL,
  `studTestQuestAttempt_counter` int(11) DEFAULT NULL,
  `studTestQuestLastAttemptTimestamp` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `studTestQuestLastAttemptQueryAns` varchar(255) DEFAULT NULL,
  `fk_studTestQuest_queryID` int(11) DEFAULT NULL,
  PRIMARY KEY (`studTestQuestTStamp`,`testID`,`studTestQuestQuestNum`,`studTestQuestStudID`),
  KEY `fk_studTestQuest_queryID` (`fk_studTestQuest_queryID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblStudentTestQuestionHist`
--

LOCK TABLES `tblStudentTestQuestionHist` WRITE;
/*!40000 ALTER TABLE `tblStudentTestQuestionHist` DISABLE KEYS */;
/*!40000 ALTER TABLE `tblStudentTestQuestionHist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblTest`
--

DROP TABLE IF EXISTS `tblTest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblTest` (
  `testTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `testID` int(11) NOT NULL AUTO_INCREMENT,
  `testYr` int(11) DEFAULT NULL,
  `testSemester` varchar(20) DEFAULT NULL,
  `testSubject` varchar(30) DEFAULT NULL,
  `testNum` int(11) DEFAULT NULL,
  `testDurationMins` int(11) DEFAULT NULL,
  `testTotalMks` int(11) DEFAULT NULL,
  `testFromDate` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `testToDate` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `testQueryDb` varchar(20) DEFAULT NULL,
  `testUse_flag` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`testID`)
) ENGINE=MyISAM AUTO_INCREMENT=28 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblTest`
--

LOCK TABLES `tblTest` WRITE;
/*!40000 ALTER TABLE `tblTest` DISABLE KEYS */;

/*!40000 ALTER TABLE `tblTest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tblTestQuestDef`
--

DROP TABLE IF EXISTS `tblTestQuestDef`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tblTestQuestDef` (
  `testQuestDefTStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `testID` int(11) NOT NULL,
  `testQuestDefQuestNum` int(11) NOT NULL,
  `testQuestDefQueryType` varchar(40) DEFAULT NULL,
  `testQuestDefMark` int(11) DEFAULT NULL,
  PRIMARY KEY (`testID`,`testQuestDefQuestNum`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tblTestQuestDef`
--

LOCK TABLES `tblTestQuestDef` WRITE;
/*!40000 ALTER TABLE `tblTestQuestDef` DISABLE KEYS */;

/*!40000 ALTER TABLE `tblTestQuestDef` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-06-22 18:26:03
