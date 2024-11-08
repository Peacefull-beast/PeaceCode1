# Write your MySQL query statement below
with cte as
(select distinct u.name, sum(t.amount) 
over(partition by t.account) as balance 
from Users u join Transactions t on u.account = t.account)
select * from cte where balance > 10000;