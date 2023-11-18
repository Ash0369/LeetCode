SELECT product_name,SUM(unit) as unit
FROM Products join Orders on Products.product_id=Orders.product_id
WHERE Orders.order_date LIKE "2020-02%"
GROUP BY(Products.product_name) HAVING SUM(unit)>=100
