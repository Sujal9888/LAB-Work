/* 1. Create Database HospitalDB */

CREATE DATABASE HospitalDB
ON PRIMARY
(
    NAME = HospitalDB_Data,
    FILENAME = 'C:\SUJAL 1\4th SEMESTER\DB\HospitalDB_Data.mdf',
    SIZE = 5MB,
    FILEGROWTH = 2MB
)
LOG ON
(
    NAME = HospitalDB_Log,
    FILENAME = 'C:\SUJAL 1\4th SEMESTER\DB\HospitalDB_Log.ldf',
    SIZE = 2MB,
    FILEGROWTH = 1MB
);
GO

/* Result of Q1 */
SELECT name
FROM sys.databases
WHERE name = 'HospitalDB';
GO


/* Use HospitalDB */
USE HospitalDB;
GO


/* 2. Increase Primary File Size to 10 MB */

ALTER DATABASE HospitalDB
MODIFY FILE
(
    NAME = HospitalDB_Data,
    SIZE = 10MB
);
GO

/* Result of Q2 */
EXEC sp_helpdb 'HospitalDB';
GO


/* 3. Create Patients Table */

CREATE TABLE Patients
(
    PatientID INT PRIMARY KEY,
    PatientName VARCHAR(50),
    Age INT,
    Gender VARCHAR(10)
);
GO

/* Result of Q3 */
EXEC sp_help Patients;
GO


/* 4. Create Doctors Table with Constraints */

CREATE TABLE Doctors
(
    DoctorID INT PRIMARY KEY,
    DoctorName VARCHAR(50) NOT NULL,
    Specialty VARCHAR(50) CONSTRAINT DF_Doctors_Specialty DEFAULT 'General',
    Experience INT CHECK (Experience >= 0)
);
GO

/* Result of Q4 */
EXEC sp_help Doctors;
GO


/* 5. Create Appointments Table with Foreign Keys */

CREATE TABLE Appointments
(
    AppointmentID INT PRIMARY KEY,
    PatientID INT,
    DoctorID INT,
    AppointmentDate DATE,

    CONSTRAINT FK_Appointments_Patients
        FOREIGN KEY (PatientID)
        REFERENCES Patients(PatientID),

    CONSTRAINT FK_Appointments_Doctors
        FOREIGN KEY (DoctorID)
        REFERENCES Doctors(DoctorID)
);
GO

/* Result of Q5 */
EXEC sp_help Appointments;
GO


/* 6. Add PhoneNumber Column to Patients */

ALTER TABLE Patients
ADD PhoneNumber VARCHAR(15);
GO

/* Result of Q6 */
EXEC sp_help Patients;
GO


/* 7. Drop Age Column from Patients */

ALTER TABLE Patients
DROP COLUMN Age;
GO

/* Result of Q7 */
EXEC sp_help Patients;
GO


/* 8. Add CHECK Constraint on Gender */

ALTER TABLE Patients
ADD CONSTRAINT CHK_Gender
CHECK (Gender IN ('Male', 'Female', 'Other'));
GO

/* Result of Q8 */
EXEC sp_helpconstraint 'Patients';
GO


/* 9. Drop Gender CHECK Constraint */

ALTER TABLE Patients
DROP CONSTRAINT CHK_Gender;
GO

/* Result of Q9 */
EXEC sp_helpconstraint 'Patients';
GO


/* 10. Add Email Column to Doctors and Set it as NOT NULL */

ALTER TABLE Doctors
ADD Email VARCHAR(100) NOT NULL
CONSTRAINT DF_Doctors_Email DEFAULT 'unknown@hospital.com';
GO

/* Result of Q10 */
EXEC sp_help Doctors;
GO


/* 11. Drop Default Constraint from Specialty */

ALTER TABLE Doctors
DROP CONSTRAINT DF_Doctors_Specialty;
GO

/* Result of Q11 */
EXEC sp_helpconstraint 'Doctors';
GO


/* 12. Drop Appointments Table */

DROP TABLE Appointments;
GO

/* Result of Q12 */
SELECT *
FROM INFORMATION_SCHEMA.TABLES
WHERE TABLE_NAME = 'Appointments';
GO


/* 13. Drop Doctors Table */

DROP TABLE Doctors;
GO

/* Result of Q13 */
SELECT *
FROM INFORMATION_SCHEMA.TABLES
WHERE TABLE_NAME = 'Doctors';
GO


/* 14. Drop HospitalDB Database */

USE master;
GO

DROP DATABASE HospitalDB;
GO

/* Result of Q14 */
SELECT name
FROM sys.databases
WHERE name = 'HospitalDB';
GO