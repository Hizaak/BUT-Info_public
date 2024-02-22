# TP 1
## Exercice 1
### Tentez pour commencer de lister les nœuds disponibles dans votre cluster.
```kubectl get node```
### Vérifiez maintenant la bonne mise en œuvre de votre deployment sur 2 nœuds.
```kubectl get deployment```
### Vous allez maintenant afficher une description détaillée de ce deployment
```kubectl describe deployment```

### A l’aide de la commande curl et du port obtenu, vérifiez l’accès à votre pod nginx
```curl http://<ip>:<port>```\
L'url s'obtient avec la commande ```kubectl get service```

