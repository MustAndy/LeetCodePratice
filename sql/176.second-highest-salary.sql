-- SELECT Salary as SecondHighestSalary 
-- FROM Employee 
-- GROUP BY SecondHighestSalary
-- UNION ALL (SELECT NULL AS SecondHighestSalary)
-- ORDER BY SecondHighestSalary DESC LIMIT 1 OFFSET 1;

SELECT MAX(Salary) as SecondHighestSalary FROM Employee E1
WHERE 1 =
(SELECT COUNT(DISTINCT(E2.Salary)) FROM Employee E2
WHERE E2.Salary > E1.Salary);