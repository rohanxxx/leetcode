# Write your MySQL query statement below
select 
    v.customer_id as customer_id, 
    count(*) as count_no_trans
from 
    Visits as v 
    left join Transactions as t
    on v.visit_id = t.visit_id
where t.visit_id is NULL
GROUP BY
    v.customer_id


