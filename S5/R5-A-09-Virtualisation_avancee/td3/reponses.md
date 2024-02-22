# TD 3
## Exercice 1

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: mon-pod
  labels:
    environnement: production
    proprietaire: alexandre
spec:
  containers:
    - name: mon-conteneur
      image: nginx:latest
      ports:
      - containerPort: 80
      resources:
        limits:
          memory: "128Mi"
          cpu: "500m"
    - name: mon-conteneur2
      image: nginx:latest
      ports:
      - containerPort: 80
      resources:
        limits:
          memory: "128Mi"
          cpu: "500m"
```

### Ajoutez un conteneur (Kubernetes affichera une erreur.

Il faut d'abord supprimer le pod :\
```kubectl delete -f ./tp2/exo1/pod```\
Puis j'ai re-ajouté le conteneur :\
```kubectl apply -f ./tp2/exo2/pod.yaml```\

## Exercice 2

## Exercice 3
```yaml
apiVersion: v1 # Version de l'API
kind: Pod # Type de ressource
metadata: # Métadonnées du pod
  name: 1pod1 # Nom du pod
  labels: # Tags du pod
    name: 1pod1 # Tag name
    group: developpeurs # Tag group
spec: # Spécifications du pod
  containers: # Conteneurs du pod
  - name: nginx
    image: nginx
    resources:
      limits:
        memory: "128Mi"
        cpu: "500m"
    ports:
      - containerPort: 80
        protocol: TCP
  - name: postgres
    image: postgres
    env:
      - name: POSTGRES_PASSWORD
        value: "password"
    resources:
      limits:
        memory: "128Mi"
        cpu: "500m"
    ports:
      - containerPort: 5432
        protocol: TCP
  - name: redis
    image: redis
    resources:
      limits:
        memory: "128Mi"
        cpu: "500m"
    ports:
      - containerPort: 6379
        protocol: TCP
```

## Exercice 4
### Stratégies de mise à jour de Kubernetes
- Recreate : arrête tous les pods avant de les redémarrer un par un.
- RollingUpdate : arrête les pods un par un et les redémarre.

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nouveau-nom-deployment
spec:
  replicas: 10
  strategy:
    type: RollingUpdate
    rollingUpdate:
      maxSurge: 10%
      maxUnavailable: 0%
  selector:
    matchLabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
      - name: nginx
        image: nginx:1.16

```

### Effectuer un rollback
```kubectl rollout undo deployment nouveau-nom-deployment```


## Exercice 5

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nouveau-nom-deployment
  labels:
    app: nginx
spec:
  replicas: 10
  strategy:
    type: RollingUpdate
    rollingUpdate:
      maxUnavailable: 10% # mttre à jour 1/10e des Pods à la fois sur les 10 replicas
  selector:
    matchLabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
      - name: nginx
        image: nginx:1.7.9
        ports:
        - containerPort: 80
        resources:
          limits:
            cpu: "500m"
            memory: "512Mi"
          requests:
            cpu: "200m"
            memory: "256Mi"
```

### Écrivez la commande pour créer un déploiement nommé "deploy" avec 5 répliques, en utilisant l'image "nginx".

```kubectl create deployment deploy --image=nginx --replicas=5```

### Écrivez une commande qui crée un pod nommé "mipod" en utilisant l'image "postgres" et, en même temps, créez un service pour l'exposer.

```kubectl run mipod --image=postgres --port=5432 --expose```

### Ecrivez une commande pour générer le YAML d'un déploiement en utilisant l'image "nginx", avec 10 répliques, mais ne l'exécutez pas (ne créez pas le déploiement).

```kubectl create deployment deploy --image=nginx --replicas=10 --dry-run=client -o yaml```

### Exécutez/créez votre déploiement et écrivez une commande pour mettre à l'échelle votre déploiement précédent à un seul pod.

```kubectl scale deployment deploy --replicas=1```


## Exercice 6

### Créez 1 pod répliqué 10 fois qui s'exécute uniquement (oui, les 10 répliques :) ) dans l'espace de noms "testing".

```kubectl run nginx --image=nginx --replicas=10 --namespace=testing```

## Exercice 7

### Créez un Pod qui s'exécute uniquement sur le controlplane

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: pod-sur-controlplane
spec:
  nodeSelector:
    node-role.kubernetes.io/control-plane: "true"
  containers:
  - name: my-container
    image: nginx:1.16
```
