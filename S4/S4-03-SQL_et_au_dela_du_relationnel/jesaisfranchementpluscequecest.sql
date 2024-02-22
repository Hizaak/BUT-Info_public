CREATE OR REPLACE TYPE c_ListeTelephone AS TABLE OF NUMBER(10);

CREATE OR REPLACE TYPE o_ListeSpecialite AS OBJECT (
    domaine VARCHAR(20),
    technologie VARCHAR(20)
);

CREATE OR REPLACE TYPE c_ListeSpecialite AS TABLE OF o_ListeSpecialite;

CREATE OR REPLACE TYPE o_Bureau AS OBJECT (
    centre VARCHAR2(5),
    batiment VARCHAR2(5),
    numero NUMBER(5)
);

CREATE TABLE t_Intervenant(
    pk_nom VARCHAR2(20) NOT NULL, 
    prenom VARCHAR2(20),
    bureau o_Bureau,
    liste_telephones c_ListeTelephone,
    liste_specialites c_ListeSpecialite,
    CONSTRAINT pk_Intervenant PRIMARY KEY (pk_nom)
)
NESTED TABLE liste_telephones STORE AS nt_ListeTelephone_1
NESTED TABLE liste_specialites STORE AS nt_ListeSpecialite_1;

INSERT INTO t_Intervenant VALUES('Crozat',
                                 'Stéphane',
                                 o_Bureau('PG', 'K', 256),
                                 c_ListeTelephone(NULL,0687990000, 0912345678,0344231234),
                                 c_ListeSpecialite(o_ListeSpecialite('BD', 'SGBDR'), 
                                                   o_ListeSpecialite('Doc', 'XML'), 
                                                   o_ListeSpecialite('BD','SGBDRO')));

INSERT INTO t_Intervenant VALUES('Vincent',
                                'Antoine',
                                o_Bureau('R', 'C', 123),
                                c_ListeTelephone(NULL,0687990000, 0912345678),
                                c_ListeSpecialite(o_ListeSpecialite('IC', 'Ontologie'),
                                                  o_ListeSpecialite('Base de données', 'SGBDRO')));

SELECT i.pk_nom, t.* FROM t_Intervenant i, TABLE(i.liste_telephones) t;
SELECT i.pk_nom, s.* FROM t_Intervenant i, TABLE(i.liste_specialites) s;