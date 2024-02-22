# Question B : Variable cible 'avis'

# Création de la cible pour la question B
cible_B = tableau['avis']

# Recodage de la variable 'avis'
cible_B = pd.Categorical(cible_B, ordered=False)
avis_modalities = cible_B.unique()

avis_dic = {}
for i in range(len(avis_modalities)):
    avis_dic[avis_modalities[i]] = i