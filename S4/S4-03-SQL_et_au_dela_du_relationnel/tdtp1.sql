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

INSERT INTO EMP2 VALUES (14, 'DUPUIS Yvonne', Coordonnees('Lyon', '69000', '0472546585',NULL));
INSERT INTO EMP2 VALUES (15, 'DUPOND Jean', Coordonnees('Paris', '75000',NULL,NULL));
INSERT INTO EMP2 VALUES (16, 'CRINIERE Belle', Coordonnees('Grenoble', '38001',NULL,NULL));
INSERT INTO EMP2 VALUES (17, 'AUBERT Louis', Coordonnees('Lyon', '69100', '0478556585',NULL));
INSERT INTO EMP2 VALUES (18, 'MAURI John', Coordonnees('Anglet', '64600',NULL,NULL));

ALTER TABLE EMP2 ADD salaire number(5,2);

INSERT INTO EMP2 VALUES (2, 'XAVIER Richard', Coordonnees('Anglet', '64200', NULL,NULL), 30000);
INSERT INTO EMP2 VALUES (3, 'NICOLLE Chris', Coordonnees('Anglet', '64200', '0698098989',NULL), 40000);

-- Donner la liste des villes
DECLARE
    CURSOR c_ville IS SELECT DISTINCT coordonnees.ville FROM EMP2;
    v_ville c_ville%ROWTYPE;
BEGIN
    OPEN c_ville;
    LOOP
        FETCH c_ville INTO v_ville;
        EXIT WHEN c_ville%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE(v_ville.ville);
    END LOOP;
    CLOSE c_ville;
END;

-- Créer une procédure PL/SQL INSERT_EMP() qui insère un employé avec tous les attributs dans la table EMP2
CREATE OR REPLACE PROCEDURE INSERT_EMP
    (
        p_numEmp IN NUMBER,
        p_nomComplet IN VARCHAR2,
        p_ville IN VARCHAR2,
        p_CP IN VARCHAR2,
        p_Tel IN VARCHAR2,
        p_Fax IN VARCHAR2,
        p_salaire IN NUMBER
    )
IS
    BEGIN
        INSERT INTO EMP2 VALUES (p_numEmp, p_nomComplet, Coordonnees(p_ville, p_CP, p_Tel, p_Fax), p_salaire);
    END;

-- Créer une procédure PL/SQL MAJ_EMP(nomEmp,salaire) qui met à jour un employé dans la table EMP2
CREATE OR REPLACE PROCEDURE MAJ_EMP
    (
        p_nomEmp IN VARCHAR2,
        p_salaire IN NUMBER
    )
IS
    BEGIN
        UPDATE EMP2 SET salaire = p_salaire WHERE nomComplet = p_nomEmp;
    END;

-- Créer une fonction PL/SQL COUNT_EMP() qui compte le nombre d'employés, en utilisant la variable temp
CREATE OR REPLACE FUNCTION COUNT_EMP RETURN NUMBER
IS
    DECLARE 
        v_temp NUMBER;
    BEGIN
        SELECT COUNT(*) INTO v_temp FROM EMP2;
        RETURN v_temp;
    END;
    
-- Créer une fonction PL/SQL GET_EMP(vile) qui compte le nombre d'employés par ville
CREATE OR REPLACE FUNCTION GET_EMP
    (
        p_ville IN VARCHAR2
    )
RETURN NUMBER
IS
    BEGIN
        RETURN (SELECT COUNT(*) FROM EMP2 WHERE coordonnees.ville = p_ville);
    END;