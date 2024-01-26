# Write your MySQL query statement below
select a.customer_id,count(a.visit_id) as count_no_trans from visits as a left join transactions as t
on a.visit_id=t.visit_id
where transaction_id is NULL 
group by a.customer_id