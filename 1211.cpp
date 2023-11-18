SELECT query_name,ROUND(SUM(rating/position)/COUNT(query_name),2) as quality,ROUND((COUNT(CASE WHEN rating<3 THEN 1 ELSE NULL END)/COUNT(query_name))*100,2) as poor_query_percentage
FROM Queries
GROUP BY(query_name)
