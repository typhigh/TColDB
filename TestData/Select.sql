
CREATE TABLE Persons3 (
    PersonID int PRIMARY KEY,
    Name varchar(20) PRIMARY KEY,
	Other varchar(10)
);
COMMIT Persons3;
SHOW TABLE Persons3;

SELECT PersonID FROM Persons3 WHERE PersonID > 1;

SELECT AVG(PersonID) FROM Persons3 WHERE PersonID > 1;
SELECT AVG(PersonID) FROM Persons3 WHERE Name < 'aaa';
SELECT * FROM Persons3;
SELECT AVG(PersonID), COUNT(*) FROM Persons3;
EXIT;