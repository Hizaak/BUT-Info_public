# Projet final - R4.A.08 Virtualisation

## Lancement de l'application (idéalement...)

1. Se placer à la racine du projet
2. Exécuter la commande `docker-compose up`
3. Ouvrir un navigateur et se rendre à l'adresse `http://localhost:4200`

## Description des services

Le fichier docker-compose.yml définit deux services :

- `angular` : construit l'image Docker de l'application Angular, la rend accessible sur le port 4200 et la relie au service `json-server`.
- `json-server` : utilise l'image Docker de Node.js, rend accessible l'API sur le port 3000 et utilise le fichier db.json pour fournir les données.

Le Dockerfile définit deux étapes pour la setup le répertoire par défaut. 

## Erreur

Actuellement, l'application ne fonctionne pas en raison d'une erreur lors de l'exécution de la commande `npm install` pour le service `angular`.
En fait il faudrait faire ``rm -rf node_modules &&`` mais ma machine plante quand j'exécute la fonction donc je sais pas trop pourquoi ça marche pas...
