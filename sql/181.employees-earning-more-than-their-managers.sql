--Using inner join to build the relationship between employee and their manager's salary
select e1.Name as Employee from Employee as e1 inner join Employee as e2 
on e1.ManagerId = e2.Id and e1.Salary > e2.Salary;