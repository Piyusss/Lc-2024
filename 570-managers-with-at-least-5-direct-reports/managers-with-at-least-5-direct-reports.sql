# Write your MySQL query statement below
select man.name from employee AS emp
INNER JOIN employee AS man 
on man.id=emp.managerId
GROUP BY emp.managerId
HAVING COUNT(emp.id)>=5