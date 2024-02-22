import pandas as pd
from sklearn.tree import DecisionTreeRegressor, DecisionTreeClassifier, plot_tree
import matplotlib.pyplot as plt
import os

# Importation du fichier "winequality-red.csv"
os.chdir("/home/amaurice/Bureau/BUT-Info_prive/S5/R5-11-Methodes_d_optimisation_pour_l_aide_a_la_decision/eval")
tableau = pd.read_csv('winequality-red.csv', sep=';', decimal=',', encoding='latin-1')

# Je supprime la colonne 'alcohol' car elle fait planter le programme (???)
tableau = tableau.drop('alcohol', axis=1)

# Recodage de 'citric acid'
tableau['citric acid'] = pd.Categorical(tableau['citric acid'], ordered=False)
citric_acid_modalities = tableau['citric acid'].unique()

citric_acid_dic = {}
for i in range(len(citric_acid_modalities)):
    citric_acid_dic[citric_acid_modalities[i]] = i

tableau['citric acid'] = tableau['citric acid'].cat.rename_categories(citric_acid_dic)

cible_A = tableau['quality']

n = len(tableau.columns)
x_A = tableau.iloc[:, 0:n-2].values  # Exclure les colonnes 'quality' et 'avis' car ce sont les variables cibles

noms_A = list(tableau.columns[0:n-2])

# Arbre de régression question A
class_arbre_A = DecisionTreeRegressor(max_depth=4, min_samples_leaf=2)
digit_tree_A = class_arbre_A.fit(x_A, cible_A)

plt.figure(figsize=(40, 15))
plot_tree(digit_tree_A, fontsize=22, filled=True, feature_names=noms_A, max_depth=1)
plt.savefig('1.png')

# Question B : Variable cible 'avis'

cible_B = tableau['avis']

# Recodage de la variable 'avis'
cible_B = pd.Categorical(cible_B, ordered=False)
avis_modalities = cible_B.unique()

avis_dic = {}
for i in range(len(avis_modalities)):
    avis_dic[avis_modalities[i]] = i
    

cible_B = tableau['avis'] # je crois que c'est inutile mais je le laisse au cas où


# Création du tableau des variables explicatives (X) pour la question B
n = len(tableau.columns)
x_B = tableau.iloc[:, 0:n-2].values  # Exclure les colonnes 'avis' et 'quality' toujours pour les mêmes raisons

# Noms des colonnes de x pour la question B
noms_B = list(tableau.columns[0:n-2])

# Arbre de classification question B
class_arbre_B = DecisionTreeClassifier(max_depth=4, min_samples_leaf=2)
digit_tree_B = class_arbre_B.fit(x_B, cible_B)

plt.figure(figsize=(40, 15))
plot_tree(digit_tree_B, fontsize=22, filled=True, feature_names=noms_B, class_names=digit_tree_B.classes_, max_depth=1)
plt.savefig('2.png')


# hop on passe au fichier employes5C.csv

data = pd.read_csv('employes5C.csv', sep=';', decimal=',', encoding='latin-1')
cible = data['Attrition']

X = data.drop('Attrition', axis=1)

class_arbre = DecisionTreeClassifier(max_depth=3)
arbre = class_arbre.fit(X, cible)

# Visualiser la première division de l'arbre (j'avais pas compris qu'il fallait faire ça)
plt.figure(figsize=(20, 10))
plot_tree(arbre, fontsize=10, filled=True, feature_names=X.columns, class_names=['Non-Attrition', 'Attrition'], max_depth=1)
plt.savefig('3.png')  # Enregistrez l'image de l'arbre (assez évident)

# Liste des variables qualitatives nominales
categorical_variables = ['Deplacements', 'Departement', 'NiveauFormation', 'Genre', 'StatutMarital']

data_encoded = pd.get_dummies(data, columns=categorical_variables)

cible = data_encoded['Attrition']

X = data_encoded.drop('Attrition', axis=1)

class_arbre = DecisionTreeClassifier(max_depth=3)
arbre = class_arbre.fit(X, cible)

plt.figure(figsize=(20, 10))
plot_tree(arbre, fontsize=10, filled=True, feature_names=X.columns, class_names=['Non-Attrition', 'Attrition'], max_depth=1)
plt.savefig('4.png')

# j'ai pas fait excel parce que j'ai pas compris ce qu'il fallait faire et que j'ai pas envie de perdre du temps dessus et que j'ai pas envie de faire un truc qui va pas
# et que c'est vraiment incroyablement chiant de faire des trucs sur excel