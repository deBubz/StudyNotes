--With compliments from PICKLES MOTOR AUCTIONS

select
	grouping = 1,
	group_desc = 'Charges',
	id = accountsale_charge.account_sale_charge_id,
	amount_ex = accountsale_charge.amount,
	gst = accountsale_charge.gst_charge,
	ded_flag = 0,
	raw_desc = upper(isNull(load_deduction.description,
										deduction_type.description,
										charge_type.description)),
	description = upper(left(raw_desc,1)) + lower(right(raw_desc, length(raw_desc) - 1)),
	pickup = f_any_pickup(load_deduction_id, 'L'),
	load_no = (select l.load_no from load l where l.load_id = load_account_sale.load_id)
from
	load_account_sale,
	accountsale_charge,
	charge_type,
	load_deduction,
	deduction_type
where
	charge_type.charge_type_id = accountsale_charge.charge_type_id
	and accountsale_charge.deduction_id = load_deduction.load_deduction_id
	and load_deduction.deduction_type_id = deduction_type.deduction_type_id
	and accountsale_charge.vendor_load_item_flag = 'L'
	and accountsale_charge.load_item_deduction_flag = 'L'
	and accountsale_charge.account_sale_ref_id = :al_las
	and load_account_sale.load_account_sale_id = :al_las
	and load_deduction.load_id = load_account_sale.load_id
UNION all
select
	grouping = 1,
	group_desc = 'Charges',
	id = accountsale_charge.account_sale_charge_id,
	amount_ex = accountsale_charge.amount,
	gst = accountsale_charge.gst_charge,
	ded_flag = 1,
	raw_desc = charge_type.description,
	description = upper(left(raw_desc,1)) + lower(right(raw_desc, length(raw_desc) - 1)),
	pickup = null,
	load_no = (select l.load_no from load l where l.load_id = (select las.load_id from load_account_sale las where las.load_account_Sale_id = :al_las))
from
	accountsale_charge,
	charge_type
where
	charge_type.charge_type_id = accountsale_charge.charge_type_id
	and (accountsale_charge.deduction_id is null)
	and accountsale_charge.vendor_load_item_flag = 'L'
	and accountsale_charge.account_sale_ref_id = :al_las
UNION all
select
	grouping = 2,
	group_desc = 'Other Transactions',
	id = accountsale_charge.account_sale_charge_id,
	amount_ex = accountsale_charge.amount,
	gst = accountsale_charge.gst_charge,
	ded_flag = 1,
	raw_desc = charge_type.description,
	description = upper(left(raw_desc,1)) + lower(right(raw_desc, length(raw_desc) - 1)),
	pickup = null,
	load_no = (select l.load_no from load l where l.load_id = (select las.load_id from load_account_sale las where las.load_account_Sale_id = :al_las))
from
	accountsale_charge,
	charge_type
where
	charge_type.charge_type_id = accountsale_charge.charge_type_id
	and (charge_type.charge_code = 'CRA'
			or charge_type.charge_code = 'FIN'
			or charge_type.charge_code = 'VFD')
	and accountsale_charge.vendor_load_item_flag = 'L'
	and accountsale_charge.account_sale_ref_id = :al_las
UNION all
select
	grouping = 1,
	group_desc = 'Charges',
	id = accountsale_charge.account_sale_charge_id,
	amount_ex = accountsale_charge.amount,
	gst = accountsale_charge.gst_charge,
	ded_flag = 2,
	raw_desc = string('Ref:', load.load_no, ' ',
							isNull(load_deduction.description,
									deduction_type.description,
									charge_type.description)),
	description = upper(left(raw_desc,1)) + lower(right(raw_desc, length(raw_desc) - 1)),
	pickup = f_any_pickup (load_deduction_id, 'L'),
	load_no = load.load_no
from
	load_account_sale,
	load,
	accountsale_charge,
	charge_type,
	load_deduction,
	deduction_type
where
	charge_type.charge_type_id = accountsale_charge.charge_type_id
	and accountsale_charge.deduction_id = load_deduction.load_deduction_id
	and load_deduction.deduction_type_id = deduction_type.deduction_type_id
	and accountsale_charge.vendor_load_item_flag = 'L'
	and accountsale_charge.load_item_deduction_flag = 'L'
	and load_deduction.load_id = load.load_id
	and accountsale_charge.account_sale_ref_id = :al_las
	and load_account_sale.load_account_sale_id = :al_las
	and load_deduction.load_id <> load_account_sale.load_id
UNION all
select
	grouping = 1,
	group_desc = 'Charges',
	id = accountsale_charge.account_sale_charge_id,
	amount_ex = accountsale_charge.amount,
	gst = accountsale_charge.gst_charge,
	ded_flag = 3,
	raw_desc = string('Ref:', load.load_no, '/', item.item_no,
								' ', isNull(item_deduction.description,
								deduction_type.description,
								charge_type.description)),
	description = upper(left(raw_desc,1)) + lower(right(raw_desc, length(raw_desc) - 1)),
	pickup = null,
	load_no = load.load_no
from
	accountsale_charge,
	charge_type,
	item_deduction,
	deduction_type,
	load,
	item
where
	charge_type.charge_type_id = accountsale_charge.charge_type_id
	and accountsale_charge.deduction_id = item_deduction.item_deduction_id
	and item_deduction.deduction_type_id = deduction_type.deduction_type_id
	and accountsale_charge.vendor_load_item_flag = 'L'
	and accountsale_charge.load_item_deduction_flag = 'I'
	and item_deduction.item_id = item.item_id
	and item.load_id = load.load_id
	and accountsale_charge.account_sale_ref_id = :al_las
union all
select
	grouping = 1,
	group_desc = 'Charges',
	id = ac.account_sale_charge_id,
	amount_ex = ac.amount,
	gst = ac.gst_charge,
	ded_flag = null,
	raw_desc = 'Commission',
	description = 'Commission',
	pickup = null,
	load_no = (select l.load_no from load l where l.load_id = (select las.load_id from load_account_sale las where las.load_account_Sale_id = :al_las))
from
	accountsale_charge ac,
	charge_type ct,
	account_sale acs
where
	ct.charge_type_id = ac.charge_type_id
	and acs.load_account_sale_id = :al_las
	and ac.account_sale_ref_id = acs.account_sale_id
	and ac.vendor_load_item_flag = 'I'
	and ct.charge_code = 'COM'
union all
select
	grouping = 2,
	group_desc = 'Other Transactions',
	id = null,
	amount_ex = accountsale_charge.amount,   
	gst = accountsale_charge.gst_charge,
	ded_flag = null,
	raw_desc = if accountsale_charge.load_item_deduction_flag = 'I'
					then isNull(item_deduction.description, deduction_type.description, charge_type.description)
					else charge_type.description
					endif,   
	description = upper(left(raw_desc,1)) + lower(right(raw_desc, length(raw_desc) - 1)),
	pickup = f_any_pickup (item_deduction_id, 'I'),
	load_no = (select l.load_no from load l where l.load_id = (select las.load_id from load_account_sale las where las.load_account_Sale_id = :al_las))
from
	{oj {oj accountsale_charge  LEFT OUTER JOIN item_deduction  ON accountsale_charge.deduction_id = item_deduction.item_deduction_id} LEFT OUTER JOIN deduction_type  ON item_deduction.deduction_type_id = deduction_type.deduction_type_id},   
         charge_type  
   WHERE "accountsale_charge"."charge_type_id" = "charge_type"."charge_type_id"
     AND "accountsale_charge"."vendor_load_item_flag" = 'I'
     AND "accountsale_charge"."account_sale_ref_id" = :al_account_sale_id
     AND "charge_type"."charge_code" <> 'COM' 
union all
select
	grouping = 999,
	group_desc = '',
	id = null,
	amount_ex = 0,
	gst = 0,
	ded_flag = null,
	raw_desc = 'this grouping is never visible - but forces the datawindow to appear in the event there are no other charges, so that the summary appears',
	description = '',
	pickup = null,
	load_no = (select l.load_no from load l where l.load_id = (select las.load_id from load_account_sale las where las.load_account_Sale_id = :al_las))
from
	sys.dummy
order by 1, 8, 4 asc

