
CREATE OR REPLACE TYPE Coordonnees AS OBJECT
    (
        ville VARCHAR2(30),
        CP VARCHAR2(5),
        Tel VARCHAR2(10),
        Fax VARCHAR2(10)
    );

CREATE TABLE EMP2
    (
        NumEmp NUMBER(5) PRIMARY KEY,
        nomComplet VARCHAR2(30),
        coordonnees Coordonnees
    );

INSERT INTO EMP2 VALUES (14, 'DUPUIS Yvonne', Coordonnees('Lyon', '69000', '0472546585'));
INSERT INTO EMP2 VALUES (15, 'DUPOND Jean', Coordonnees('Paris', '75000'));
INSERT INTO EMP2 VALUES (16, 'CRINIERE Belle', Coordonnees('Grenoble', '38001'));
INSERT INTO EMP2 VALUES (17, 'AUBERT Louis', Coordonnees('Lyon', '69100', '0478556585'));
INSERT INTO EMP2 VALUES (18, 'MAURI John', Coordonnees('Anglet', '64600'));

ALTER TABLE EMP2 ADD salaire number(5,2) AFTER nomComplet;

UPDATE EMP2 SET nomComplet = 'XAVIER Richard' AND salaire = 30000 AND coordonnees = Coordonnees('Anglet', '64600') WHERE NumEmp = 2;
UPDATE EMP2 SET nomComplet = 'NICOLLE Chris' AND salaire = 20000 AND coordonnees = Coordonnees('Anglet', '64600', '0698098989') WHERE NumEmp = 3;


UPDATE EMP2 SET salaire = &newSalaire WHERE NumEmp = &numero;

SELECT DISTINCT coordonnees.ville FROM EMP2;

SELECT COUNT(DISTINCT coordonnees.ville) FROM EMP2;

SELECT * FROM EMP2 WHERE coordonnees.ville = 'Anglet';

DECLARE
BEGIN
    SELECT * FROM EMP2 WHERE coordonnees.Tel IS NOT NULL;
END;

UPDATE EMP2 SET coordonnees = Coordonnees(coordonnees.ville, coordonnees.CP, '0478556585', '0478556585') WHERE NumEmp = 2;

CREATE OR REPLACE PROCEDURE INSERT_EMP(NumEmp IN NUMBER, nomComplet IN VARCHAR2, ville IN VARCHAR2, CP IN VARCHAR2, Tel IN VARCHAR2, salaire IN NUMBER)
IS
BEGIN
    INSERT INTO EMP2 VALUES (NumEmp, nomComplet, Coordonnees(ville, CP, Tel), salaire);
END;

CREATE OR REPLACE PROCEDURE MAJ_EMP(NumEmp IN NUMBER, nomComplet IN VARCHAR2, ville IN VARCHAR2, CP IN VARCHAR2, Tel IN VARCHAR2, salaire IN NUMBER)
IS
BEGIN
    UPDATE EMP2 SET nomComplet = nomComplet, coordonnees = Coordonnees(ville, CP, Tel), salaire = salaire WHERE NumEmp = NumEmp;
END;

CREATE OR REPLACE FUNCTION COUNT_EMP RETURN NUMBER
IS
    nb NUMBER;
BEGIN
    SELECT COUNT(*) INTO nb FROM EMP2;
    RETURN nb;
END;

CREATE OR REPLACE FUNCTION COUNT_EMP(Ville IN VARCHAR2) RETURN NUMBER
IS
    nb NUMBER;
BEGIN
    SELECT COUNT(*) INTO nb FROM EMP2 WHERE coordonnees.ville = Ville;
    RETURN nb;
END;