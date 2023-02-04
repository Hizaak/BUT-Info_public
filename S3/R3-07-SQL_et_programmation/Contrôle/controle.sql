CREATE TABLE etudiant(
    int numero AUTO INCREMENT PRIMARY KEY;
    varchar nom;
    varchar prenom;
    date dateDeNaissance;
    int numeroGroupe
)

CREATE TABLE groupe(
    int numero AUTO INCREMENT PRIMARY KEY;
    varchar nom;
)

-- On est en Oracle SQL
-- Question 1
-- Selectionner tous les étudiants en les triant par age
SELECT * FROM etudiant ORDER BY dateDeNaissance;

-- Question 2
-- Afficher la liste des etudiants en concatenant le nom et le prenom
SELECT nom || ' ' || prenom FROM etudiant;

-- D'une deuxième manière
SELECT CONCAT(nom, ' ', prenom) as "Nom et Prénom" FROM etudiant;

-- Question 3
-- Sélectionner le nom et prénom des étudiants qui n'ont pas de groupe
SELECT nom, prenom FROM etudiant WHERE numeroGroupe IS NULL;

-- Question 4
-- Sélectionner le nombre de groupes dans lequel apparait l'étudiant numéro 155
SELECT COUNT(numeroGroupe) FROM etudiant WHERE numero = 155;

-- Question 5
-- Afficher le nom et le prénom des étudiants nés après l'étudiant Blake
SELECT nom, prenom FROM etudiant WHERE dateDeNaissance > (SELECT dateDeNaissance FROM etudiant WHERE nom = 'Blake');

-- On est en DAO
-- Faire une procédure qui applique l'intégrité ré