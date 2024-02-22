-- Créer la base de données
CREATE DATABASE mydatabase;

-- Utiliser la base de données
USE mydatabase;

-- Créer la table des utilisateurs
CREATE TABLE users (
  id INT NOT NULL AUTO_INCREMENT,
  username VARCHAR(50) NOT NULL,
  password VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

-- Insérer un utilisateur dans la table
INSERT INTO users (username, password)
VALUES ('john_doe', 'password123');

-- Créer un utilisateur pour la base de données
CREATE USER 'myuser'@'localhost' IDENTIFIED BY 'mypassword';

-- Donner des privilèges à l'utilisateur sur la base de données
GRANT ALL PRIVILEGES ON mydatabase.* TO 'myuser'@'localhost';
