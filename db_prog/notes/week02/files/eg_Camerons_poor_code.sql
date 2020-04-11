SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO


CREATE  VIEW dbo.vwAPRAUW
AS
SELECT     TOP 100 PERCENT 
InsurerCode, ClassOfBusiness, RecordType, PolicyBasis, Status, RptPdEndDtm, PolicyNbr, RiskNbr, APRAProdCd, OrigIncDate, IncDate, EffStartDate, 
ExpiryDate, EffEndDate, GrossAnnualPrem, sum(RptPdEarnPrm) RptPdEarnPrm, sum(RptPdEarnPrmPro) RptPdEarnPrmPro, sum(GWPrem) GWPrem, 
case when epolicynbr is null then (case when sum(TotPrem) = 0 or (sum(GWPrem)/sum(TotPrem)) * TurnOver = 0  or sum(TotPrem) = 0 then '' else 
	cast(cast(round(round(cast(sum(GWPrem) as decimal(38,11))/sum(TotPrem),10) * TurnOver,0) as decimal(38,0)) as varchar) end) else (case when TurnOver = 0 then '' else cast(TurnOver as varchar) end) end TurnOver, 
case when epolicynbr is null then (case when sum(TotPrem) = 0 or (sum(GWPrem)/sum(TotPrem)) * round(TotalAssets,0) = 0  then '' else 
	cast(cast(round(round(cast(sum(GWPrem) as decimal(38,11))/sum(TotPrem),10) * TotalAssets,0) as decimal(38,0)) as varchar) end) else (case when round(TotalAssets,0) = 0 then '' else cast(TotalAssets  as varchar) end) end  TotalAssets, 
case when epolicynbr is null then (case when sum(TotPrem) = 0 or (sum(GWPrem)/sum(TotPrem)) * round(ProfessionalFees,0) = 0 then '' else 
	cast(cast(round(round(cast(sum(GWPrem) as decimal(38,11))/sum(TotPrem),10) * ProfessionalFees,0) as decimal(38,0)) as varchar) end) else (case when round(ProfessionalFees,0) = 0 then '' else cast(ProfessionalFees  as varchar) end) end ProfessionalFees, 
case when epolicynbr is null then (case when sum(TotPrem) = 0 or (sum(GWPrem)/sum(TotPrem)) * TotalNumOfStaff = 0 then '' else 
	cast(cast(round(round(cast(sum(GWPrem) as decimal(38,11))/sum(TotPrem),10) * TotalNumOfStaff,0) as decimal(38,0)) as varchar) end) else (case when TotalNumOfStaff = 0 then '' else cast(TotalNumOfStaff as varchar) end) end TotalNumOfStaff, 
case when epolicynbr is null then (case when sum(TotPrem) = 0 or ((sum(GWPrem)/sum(TotPrem)) * Other = 0 and DescriptionOfOther = '') then '' else cast(cast(round(round(cast(sum(GWPrem) as decimal(38,11))/sum(TotPrem),10) * Other,0) as decimal(38,0)) as varchar) end) else (case when Other = 0  and DescriptionOfOther = '' then '' else cast(Other as varchar) end) end  Other, 
DescriptionOfOther, State, PostCd, DedExc, OurShareLimit, NatOfInsOrgOcc, OurShareWhole
 FROM (
SELECT
InsurerCode, ClassOfBusiness, RecordType, PolicyBasis, Status, dbo.APRAFormatDate(RptPdEndDtm) RptPdEndDtm, 
                      pm1.PolicyNbr, pf.GenPolKey + '-' + pf.GenRenKey + '-' + pf.SectionSeq + '-' + pf.secDtlSeq + '-' + pf.CvgSeq RiskNbr, APRAProdCd, 
                      dbo.APRAFormatDate(pf.OrigIncDate) OrigIncDate, dbo.APRAFormatDate(pf.IncDate) IncDate, 
                      dbo.APRAFormatDate(EffStartDate) EffStartDate, 
                      dbo.APRAFormatDate(pf.ExpiryDate) ExpiryDate, 
                      dbo.APRAFormatDate(EffEndDate) EffEndDate, '' GrossAnnualPrem, cast(RptPdEarnPrmPro as decimal(19,0)) RptPdEarnPrm, 
                      cast(round(RptPdEarnPrmPro, 0) AS decimal(19, 0)) RptPdEarnPrmPro, cast(round(GWPrem, 0) AS decimal(19, 0)) GWPrem, 
cast(round(TotPrem, 0) AS decimal(19, 0)) TotPrem,
TurnOver,
TotalAssets,
ProfessionalFees,
TotalNumOfStaff,
Other,
                      DescriptionOfOther, CASE WHEN len(rtrim(isnull(State, ''))) = 0 THEN '-' ELSE State END State, CASE WHEN len(rtrim(isnull(PostCd, ''))) 
                      = 0 THEN '-' ELSE PostCd END PostCd, cast(round(DedExc, 0) AS decimal(19, 0)) DedExc, cast(round(OurShareLimit, 0) AS decimal(19, 0)) 
                      OurShareLimit, NatOfInsOrgOcc, CONVERT(varchar(255), cast(round(OurShareWhole, 2) AS money), 1) OurShareWhole, eel.policynbr epolicynbr
FROM         polfilterfinal pf LEFT OUTER JOIN
                      RptPdEarnPrm reprm ON pf.genpolkey = reprm.genpolkey AND pf.genrenkey = reprm.genrenkey AND pf.sectionseq = reprm.sectionseq AND 
                      pf.secdtlseq = reprm.secdtlseq AND pf.cvgseq = reprm.cvgseq AND pf.endnbr = reprm.endnbr LEFT OUTER JOIN
                      exposurebase xb ON pf.genpolkey = xb.genpolkey AND pf.genrenkey = xb.genrenkey AND pf.sectionseq = xb.sectionseq AND 
                      pf.secdtlseq = xb.secdtlseq AND pf.cvgseq = xb.cvgseq LEFT OUTER JOIN
                      statefinal sf ON pf.genpolkey = sf.genpolkey AND pf.genrenkey = sf.genrenkey AND pf.sectionseq = sf.sectionseq AND 
                      pf.secdtlseq = sf.secdtlseq LEFT OUTER JOIN
                      postcd pc ON pf.genpolkey = pc.genpolkey AND pf.genrenkey = pc.genrenkey LEFT OUTER JOIN
                      PolDedExcLimOurShare pdxl ON pf.genpolkey = pdxl.genpolkey AND pf.genrenkey = pdxl.genrenkey AND pf.sectionseq = pdxl.sectionseq AND 
                      pf.secdtlseq = pdxl.secdtlseq AND pf.cvgseq = pdxl.cvgseq INNER JOIN
                      coverage cvg ON cvg.genpolkey = pdxl.genpolkey AND cvg.genrenkey = pdxl.genrenkey AND cvg.sectionseq = pdxl.sectionseq AND 
                      cvg.secdtlseq = pdxl.secdtlseq AND cvg.cvgseq = pdxl.cvgseq AND cvgtypecd <> 'L046' LEFT OUTER JOIN
                      NatOfInsOrgOccFinal noif ON pf.genpolkey = noif.genpolkey AND pf.genrenkey = noif.genrenkey AND pf.sectionseq = noif.sectionseq LEFT OUTER JOIN
                      gwprem gwp ON pf.genpolkey = gwp.genpolkey AND pf.genrenkey = gwp.genrenkey AND pf.sectionseq = gwp.sectionseq AND 
                      pf.secdtlseq = gwp.secdtlseq AND pf.cvgseq = gwp.cvgseq AND pf.endnbr = gwp.endnbr LEFT OUTER JOIN
                      prodtypefinal ptf ON pf.genpolkey = ptf.genpolkey AND pf.genrenkey = ptf.genrenkey AND pf.sectionseq = ptf.sectionseq AND 
                      pf.secdtlseq = ptf.secdtlseq LEFT OUTER JOIN
                      effdatefinal edf ON pf.sectionseq = edf.sectionseq AND pf.secdtlseq = edf.secdtlseq AND pf.cvgseq = edf.cvgseq AND pf.endnbr = edf.endnbr AND 
                      pf.genpolkey = edf.genpolkey AND pf.genrenkey = edf.genrenkey INNER JOIN
                      sectiondetail sdtl ON pf.genpolkey = sdtl.genpolkey AND pf.genrenkey = sdtl.genrenkey AND pf.sectionseq = sdtl.sectionseq AND 
                      pf.secdtlseq = sdtl.secdtlseq AND areacd1 = '003' INNER JOIN
                      policymain1 pm1 ON pf.genpolkey = pm1.genpolkey AND pf.genrenkey = pm1.genrenkey AND pm1.incdate > 'Dec 31, 2002' INNER JOIN
                      policymaster pm ON pf.genpolkey = pm.genpolkey AND pf.genrenkey = pm.genrenkey --AND pm.polareacd1 IN ('003', '999')
	         LEFT OUTER JOIN exposureexceptionlist eel on
	         rtrim(pm.policynbr) = eel.policynbr
WHERE     NOT EXISTS
                          (SELECT     1
                            FROM          hidepolfinal hpf
                            WHERE      pf.genpolkey = hpf.genpolkey AND pf.genrenkey = hpf.genrenkey AND pf.sectionseq = hpf.sectionseq)
) a
GROUP BY InsurerCode, ClassOfBusiness, RecordType, PolicyBasis, Status, RptPdEndDtm, PolicyNbr, RiskNbr, APRAProdCd, OrigIncDate, IncDate, EffStartDate, ExpiryDate, EffEndDate, GrossAnnualPrem, 
TurnOver, TotalAssets, ProfessionalFees, TotalNumOfStaff, Other, DescriptionOfOther, State, PostCd, DedExc, OurShareLimit, NatOfInsOrgOcc, OurShareWhole, epolicynbr
ORDER BY RiskNbr






























GO
SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

