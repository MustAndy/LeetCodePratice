CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
    BEGIN
    RETURN(
        SELECT MAX(Salary) FROM Employee as E1
                WHERE N =
            (SELECT COUNT(DISTINCT(E2.Salary))
                 FROM Employee as E2
                     WHERE E2.Salary >= E1.Salary)

    );
END