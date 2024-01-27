# Write your MySQL query statement below
select man.name from employee AS man
INNER JOIN employee AS emp 
on man.id=emp.managerId
GROUP BY emp.managerId
HAVING COUNT(emp.id)>=5