# Write your MySQL query statement below
select a1.machine_id,round(avg(a2.timestamp-a1.timestamp),3) as processing_time
from Activity a1, Activity a2 
WHERE a1.machine_id=a2.machine_id 
AND a1.process_id=a2.process_id 
AND a1.activity_type='start'
AND a2.activity_type='end'
GROUP BY a1.machine_id