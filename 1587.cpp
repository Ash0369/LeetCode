# Write your MySQL query statement below
SELECT name,SUM(amount) as balance
FROM Users u JOIN Transactions t ON u.account=t.account
GROUP BY(t.account) HAVING SUM(amount)>10000;
