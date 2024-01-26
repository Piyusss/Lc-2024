# Write your MySQL query statement below
select a.unique_id , b.name from EmployeeUNI as a RIGHT JOIN Employees as b
on a.id=b.id
group by b.id