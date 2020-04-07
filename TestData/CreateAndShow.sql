CREATE TABLE Persons (
	PersonID int,
	Name varchar(20),
	Gender varchar(1) DEFAULT 'M',
	CHECK (PersonID > 10),
	CHECK (Gender IN ('F', 'M'))
);

SHOW TABLE Persons;

COMMIT;

EXIT;