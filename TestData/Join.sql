CREATE TABLE Persons4 (
    PersonID int PRIMARY KEY,
    ClassID int,
    Grade   int,
    Name varchar(20) PRIMARY KEY,
	Other varchar(10)
);

CREATE TABLE Class (
    ClassID int PRIMARY KEY,
    City    varchar(10)
);

COMMIT Persons4;
COMMIT Class;z
SHOW TABLE Persons4;
SHOW TABLE Class;

SELECT Persons4.ClassID, Persons4.Grade FROM Persons4, Class WHERE Class.ClassID = Persons4.ClassID;
EXIT;