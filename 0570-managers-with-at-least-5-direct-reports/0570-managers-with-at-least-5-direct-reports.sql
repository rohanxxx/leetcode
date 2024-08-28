# Write your MySQL query statement below
select 
    t1.name as name
from 
    Employee as t1
    join
    (
        select 
            managerId as ManagerId
        from
            Employee
        group by ManagerId
        having count(ManagerId) >= 5 
    ) as t2
    on t1.id = t2.ManagerId
