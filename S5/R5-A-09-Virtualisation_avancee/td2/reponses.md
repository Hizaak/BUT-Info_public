# TD 2
## Exercice 1
Sur le lien suivant, vous trouverez deux définitions de PODs :
https://kubernetes.io/docs/concepts/workloads/pods/

Décrivez chacune des définitions (qu'est-ce que c'est ? À quoi ça sert ? Et quelles
caractéristiques a-t-elle)

### Définition 1

```yaml
apiVersion: v1
kind: Pod
metadata:
 name: nginx
spec:
 containers:
 - name: nginx
   image: nginx:1.14.2
   ports:
   - containerPort: 80
```

- ApiVersion : version de l'API utilisée
- Kind : type de l'objet
- Metadata : métadonnées de l'objet
  - name : nom de l'objet
- Spec : spécification de l'objet
- Containers : liste des conteneurs du pod
  - name : nom du conteneur
  - image : image du conteneur
  - ports : liste des ports du conteneur
    - containerPort : port du conteneur

### Définition 2
```yaml
apiVersion: batch/v1
kind: Job
metadata:
 name: hello
spec:
 template:
   spec:
     containers:
     - name: hello
       image: busybox:1.28
       command: ['sh', '-c', 'echo "Hello, Kubernetes!" && sleep 3600']
     restartPolicy: OnFailure
```

- ApiVersion : version de l'API utilisée
- Kind : type de l'objet
- Metadata : métadonnées de l'objet
  - name : nom de l'objet
- spec : spécification de l'objet
  - template : template du pod
    - spec : spécification du pod
      - containers : liste des conteneurs du pod
        - name : nom du conteneur
        - image : image du conteneur
        - command : commande à exécuter
      - restartPolicy : politique de redémarrage du pod

## Exercice 2

## Exercice 3
```yaml
apiVersion: v1
kind: Pod
metadata:
  name: 1pod1
  labels:
    name: 1pod1
    group: developpeurs
spec:
  containers:
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

### Créez le Pod avec votre fichier. Il y aura probablement des erreurs. Corrigez votre YAML en fonction des erreurs que kubectl affiche.

Aucune erreur. Si c'est par rapport au fait que le Pod existe déjà, c'est normal, il faut le supprimer avant de le recréer.

### Pensez-vous que les conteneurs peuvent communiquer entre eux ? Pourquoi ?

Oui les conteneurs peuvent communiquer entre eux, il faut juste les mettre dans le même réseau, mais par défaut ils le sont (car Docker le fait).

## Exercice 4
```yaml
apiVersion: v1
kind: Pod
metadata:
  name: 1pod1
  labels:
    name: 1pod1
    group: developpeurs
    type: fullstack
spec:
  containers:
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

### Ajoutez deux labels. Une fois modifié, essayez d’ajouter un conteneur (Kubernetes affichera une erreur. C'est normal, analysez-la bien).

Une erreur est présente car il n'écrase pas les variables déjà présentes.

## Exercice 5
```yaml
apiVersion: v1
kind: Pod
metadata:
  name: multi-container-pod
spec:
  containers:
  - name: writer-container
    image: nginx
    volumeMounts:
    - name: shared-volume
      mountPath: /data
  - name: reader-container-1
    image: busybox
    volumeMounts:
    - name: shared-volume
      mountPath: /data
    command: ["/bin/sh", "-c", "while true; do cat /data/container-name.txt; sleep 2; done"]
  - name: reader-container-2
    image: busybox
    volumeMounts:
    - name: shared-volume
      mountPath: /data
    command: ["/bin/sh", "-c", "while true; do cat /data/container-name.txt; sleep 2; done"]
  volumes:
  - name: shared-volume
    emptyDir: {}
```