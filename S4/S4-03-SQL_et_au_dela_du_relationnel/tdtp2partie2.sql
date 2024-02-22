CREATE OR REPLACE TYPE METADONNEE AS OBJECT(
    auteur VARCHAR2(255),
    geolocalisation VARCHAR2(255),
    dateInscription DATE
)

CREATE OR REPLACE TYPE LIEN AS OBJECT(
    URI VARCHAR2(255),
    relation VARCHAR2(50)
)

CREATE OR REPLACE TYPE LIENS AS TABLE OF LIEN

CREATE TABLE RO(
    URI VARCHAR2(255) NOT NULL,
    texte VARCHAR2(240),
    ObjetMime BLOB(8M),
    dateHeure DATE,
    metadonnees METADONNEE,
    liens LIEN
)

INSERT INTO RO VALUES('Ma-photo1', 'Photo prise lors d une soiree avec les amis', NULL, date('2009-05-12'), METADONNEE('X. Tintin', '34.8345267822 36814 -0.3515625', date('2008-04-03')), LIENS(LIEN('Ma-photo2', 'thème'),LIEN('Ma-photo12', 'réponse')))
INSERT INTO RO VALUES('Belle-Belle', 'Photo d une belle artiste', NULL, date('2014-10-16'), METADONNEE('Y. Dupond', '33.4314413355 7529 34.453125', date('2008-04-03')), LIEN('Chanson12', 'réponse'))

SELECT * FROM RO ro WHERE ro.metadonnees.geolocalisation LIKE '%Dupond'