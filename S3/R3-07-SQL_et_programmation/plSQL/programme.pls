
CREATE TABLE DEPT(
    numdep NUMBER(1) PRIMARY KEY,
    nom VARCHAR2(50),
    ville VARCHAR2(50),
);


CREATE TABLE EMP(
    numEmp INTEGER PRIMARY KEY,
    nom VARCHAR(50),
    profession VARCHAR(50),
    chef NUMBER(5),
    salaire NUMBER(9,2),
    numDep NUMBER(1),
    FOREIGN KEY (numDep) REFERENCES DEPT(numDep)
);

INSERT INTO EMP VALUE(1,'BARTHE FLORENT','CHEF DE PROJET',1,13000,2);
INSERT INTO EMP VALUE(2,'XAVIER RICHARD','CHERCHEUR',3,21000,1);
-- INSERT INTO EMP VALUE(3,'NICOLLE CHRIS','CHERCHEUR',null,25000,1);
-- OU ALORS :
INSERT INTO EMP (numEmp,nom,profession,salaire,numDep) VALUES(3,'NICOLLE CHRIS','CHERCHEUR',25000,1);
INSERT INTO EMP VALUE(4,'BLAKE JOHN','DEVELOPPEUR',6,8000,2);

INSERT INTO DEPT VALUE(1,'RECHERCHE','PARIS');
INSERT INTO DEPT VALUE(2,'DEVELOPPEMENT','LYON');


DECLARE
    n NUMBER(2);
    CURSOR employes IS SELECT numemp, nomemp, salaire FROM EMP;
    newsal emp.salaire%TYPE;
    empv EXCEPTION;
BEGIN
    SELECT COUNT(*)FROM EMP;
    IF n=0 ALORS
        RAISE empv;
    END IF;
    FOR employe IN employes LOOP
        newsal=employe.salaire+50;
        UPDATE EMP SET SALAIRE=newsal where NUMEMP = employe.numemp;
    END LOOP;
    Commit;
EXCEPTION
    WHEN empv THEN dbms_output.put_line('Aucun employé dans la table');
END;


CREATE OR REPLACE PROCEDURE afficher_hello_world AS
    text VARCHAR2(25);
BEGIN
    text:='Hello World !';
    dbms_output.put_line(text);
END;


CREATE OR REPLACE PROCEDURE get_salaire_emp(p_numemp IN emp.numemp%TYPE, p_salaire OUT emp.salaire%TYPE) AS
BEGIN
    SELECT salaire INTO p_salaire FROM emp WHERE numemp=p_numemp;
RETURN salaire;
END;

exec afficher_hello_world;

DECLARE
    salaire NUMBER(9,2);
BEGIN
    get_salaire_emp(1,salaire);
    dbms_output.put_line(salaire);
END;

--On creer une procedure qui affecte un departement a un emplyoyé et prend en parametre un nom d'un employé et un departement
CREATE OR REPLACE PROCEDURE affecter_departement(p_nomemp IN emp.nom%TYPE, p_numdep IN dept.numdep%TYPE) AS
BEGIN
    UPDATE emp SET numdep=p_numdep WHERE nom=p_nomemp;
    COMMIT;
END;

CREATE OR REPLACE FUNCTION exist_emp(p_nomemp IN emp.nom%TYPE) RETURN BOOLEAN AS
    nb NUMBER(2);
BEGIN
    SELECT COUNT(*) INTO nb FROM emp WHERE nom=p_nomemp;
    IF nb=0 THEN
        RETURN FALSE;
    ELSE
        RETURN TRUE;
    END IF;
END;

--On creer une fonction app_emp qui affiche le "cet employé apartient au departement..." et prend en parametre le nom d'un employé
CREATE OR REPLACE PROCEDURE app_emp(p_nomemp IN emp.nom%TYPE) AS
    numdep emp.numdep%TYPE;
BEGIN
    IF exist_emp(p_nomemp)=TRUE THEN
        SELECT numdep INTO numdep FROM emp WHERE nom=p_nomemp;
        dbms_output.put_line('Cet employé appartient au departement '||numdep);
    ELSE
        dbms_output.put_line('Cet employé n''existe pas');
    END IF;
END;

-- Fonction qui met à jour les salaires
CREATE OR REPLACE PROCEDURE maj_emp AS
    moyenne NUMBER(9,2);
BEGIN
    UPDATE emp SET salaire=salaire-200 WHERE numdep=1;
    UPDATE emp SET salaire=salaire+40 WHERE numdep=2;
    UPDATE emp SET salaire=salaire*2 WHERE numdep=3;
    SELECT AVG(salaire) INTO moyenne FROM emp WHERE numdep=4;
    UPDATE emp SET salaire=moyenne WHERE numdep=4;
    COMMIT;
END;

-- Partie 2
-- Question 1
CREATE OR REPLACE PROCEDURE insert_emp(num IN INTERGER, nom IN VARCHAR2(50), profession IN VARCHAR2(50), chef IN NUMBER(5), salaire IN NUMBER(9,2), numdep IN NUMBER(1)) AS
BEGIN
    INSERT INTO emp VALUES(num,nom,profession,chef,salaire,numdep);
    COMMIT;
END;

-- Question 2
CREATE OR REPLACE PROCEDURE maj_emp(nomemp IN VARCHAR2(50), salaire IN NUMBER(9,2)) AS
BEGIN
    UPDATE emp SET salaire=salaire WHERE nom=nomemp;
    COMMIT;
END;

-- Question 3
CREATE OR REPLACE FUNCTION count_emp() RETURN NUMBER(5) AS
    nb NUMBER(5);
BEGIN
    SELECT COUNT(*) INTO nb FROM emp;
    RETURN nb;
END;

-- Question 4
CREATE OR REPLACE FUNCTION count_emp_ville(villeemp IN VARCHAR2(50)) RETURN NUMBER(5) AS
    nb NUMBER(5);
BEGIN
    SELECT COUNT(*) INTO nb FROM emp JOIN dept ON emp.numdep=dept.numdep WHERE ville=villeemp;
    RETURN nb;
END;