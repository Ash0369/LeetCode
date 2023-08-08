SELECT name as Customers
FROM (Customers LEFT JOIN  Orders on Customers.id=Orders.customerId)
WHERE Orders.id is NULL;
