SELECT w1.id from Weather w1 JOIN Weather w2 ON w1.recordDate=w2.recordDate+INTERVAL 1 DAY
WHERE  w1.temperature>w2.temperature
