SELECT product_name,year,price 
FROM Sales JOIN Product
WHERE Sales.product_id=Product.product_id