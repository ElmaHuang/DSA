# 183\_sql

[183. Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/)

```text
# Write your MySQL query statement below
SELECT A.Name as 'Customers' from Customers A
WHERE A.Id NOT IN (
    SELECT B.CustomerId from Orders B
)
```

