# Write your MySQL query statement below
SELECT user_id,MAX(time_stamp) as last_stamp
FROM Logins
WHERE time_stamp LIKE '2020%'
Group By user_id
