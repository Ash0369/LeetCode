# Write your MySQL query statement below
SELECT firstName,lastName,city,state 
FROM Person LEFT join Address on Person.personId=Address.personId
