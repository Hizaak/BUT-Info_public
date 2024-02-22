# TD 1
## Exercice 1
### Exemples d'applications monolithiques
- Keepass : permet de stocker ses mots de passe dans un fichier de base de données en local.
- Photoshop : permet de traiter des images détenues localement.
- Word : traitement de texte en local.
- MySQL : système de gestion de base de données se basant sur un fichier binaire stocké localement grâce à son moteur.
- Wordpress : les sites webs déployés avec WordPress sont monolithiques dans le sens où le contenu est généré par WordPress seul.

### Exemples d'applications distribuées
- Git : chaque développeur dispose de sa propre copie du dépôt et peut fusionner plus tard ses changements.
- Mastodon : réseau social où chaque utilisateur peut déployer sa propre instance.
- Hadoop : dispose d'un système de stockage de fichier distribué.

## Exercice 2
...

## Exercice 3
- Mise à l’échelle horizontale, sur différents réseau
- Mise à jour progressive et automatique des containers
- Redéploiement automatique containers ayant eu un probleme quelconque
- Possibilité de monitorer
- Une grande communauté, massivement utilisé dans les entreprises (celles ayant besoin de faire de l’orchestration evidemment)

## Exercice 4

### En quelques mots, qu'est-ce qu'un Pod ?
Un Pod est un groupe de conteneurs qui partagent un environnement de stockage et un réseau commun. Un Pod est l'unité de base sur laquelle repose Kubernetes.
### Quelle est la différence entre un Deployment et un Replicaset ?
- Un Deployment est un objet Kubernetes qui permet de définir l'état souhaité d'une application. Il permet de définir le nombre de Pods qui doivent être en fonctionnement et de gérer les mises à jour de l'application. Un Deployment utilise un Replicaset pour gérer les Pods.
- Un Replicaset est un objet Kubernetes qui permet de définir le nombre de Pods qui doivent être en fonctionnement. Il permet de gérer les mises à jour de l'application. Un Replicaset utilise un PodTemplate pour créer les Pods.

### Que se passe-t-il si vous supprimez un Pod qui appartient à un Replicaset ?
Le Replicaset va créer un nouveau Pod pour remplacer celui qui a été supprimé.


### Quel est le nom du serveur maître de Kubernetes ?
Le serveur maître de Kubernetes est appelé Control Plane.

### Expliquez ce qu’est le serveur etcd et sont rôles.
etcd est un système de stockage de clés/valeurs distribué. Il est utilisé par Kubernetes pour stocker les données de configuration et d'état du cluster.