SELECT count(*) as rich_count FROM (SELECT MAX(amount) as amount FROM Store GROUP BY customer_id) as tb WHERE tb.amount>500
