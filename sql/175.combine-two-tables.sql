SELECT a.FirstName,a.LastName,b.City,b.State
FROM Person as a left join Address as b on a.PersonID = b.PersonID