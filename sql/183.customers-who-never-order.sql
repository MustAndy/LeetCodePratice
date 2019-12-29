SELECT a.Name as Customers
FROM Customers as a
WHERE a.Id Not in (SELECT b.CustomerId from Orders as b)