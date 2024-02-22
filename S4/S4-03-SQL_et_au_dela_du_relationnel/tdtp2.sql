
CREATE OR REPLACE TYPE B_Point AS OBJECT
(
    x NUMBER(5),
    y NUMBER(5)
);


CREATE OR REPLACE TYPE B_Ligne AS OBJECT
(
    p1 B_Point,
    p2 B_Point
);

CREATE OR REPLACE TYPE B_Polygone AS TABLE OF B_Point;


CREATE TABLE REGION
(
    NOM_REGION VARCHAR2(50),
    POLYGONE B_Polygone
);


INSERT INTO REGION VALUES ('Aquitaine', B_Polygone(B_Point(1, 2), B_Point(3, 4), B_Point(5, 6)));

DECLARE
    polygone B_Polygone;
BEGIN
    polygone.EXTEND(1);
    polygone(1) := B_Point(1, 1);
    polygone.EXTEND(2);
    polygone(2) := B_Point(1, 2);
    polygone.EXTEND(3);
    polygone(3) := B_Point(2, 2);
    polygone.EXTEND(4);
    polygone(4) := B_Point(2, 1);
    polygone.EXTEND(5);
    polygone(5) := B_Point(1, 1);
    INSERT INTO REGION VALUES (1, 'Aquitaine', polygone);
END;

CREATE OR REPLACE TYPE RECTANGLE AS OBJECT
(
    p1 B_Point,
    p2 B_Point
);


CREATE TABLE VILLE
(
    ID_VILLE NUMBER(5) PRIMARY KEY,
    NOM_VILLE VARCHAR2(30),
    RECT_VILLE RECTANGLE
);

INSERT INTO VILLE VALUES ('ANGLET', RECT(B_point(8950,9180), B_point(4840,5050)));
INSERT INTO VILLE VALUES ('LYON', RECT(B_point(8820,9080), B_point(7020,7230)));
INSERT INTO VILLE VALUES ('PARIS', RECT(B_point(6310,6560), B_point(2940,3110)));

DECLARE
    v VILLE%ROWTYPE;
    surface NUMBER(5);
BEGIN
    FOR v IN (SELECT * FROM VILLE)
    LOOP
        surface := (v.RECT_VILLE.p2.x - v.RECT_VILLE.p1.x) * (v.RECT_VILLE.p2.y - v.RECT_VILLE.p1.y);
        DBMS_OUTPUT.PUT_LINE(v.NOM_VILLE || ' : ' || surface);
    END LOOP;
END;


-- Partie 2

