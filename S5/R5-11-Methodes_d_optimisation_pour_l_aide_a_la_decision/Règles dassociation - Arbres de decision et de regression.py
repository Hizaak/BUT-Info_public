# -*- coding: utf-8 -*-
"""
Created on Fri Oct 13 13:57:24 2023

@author: bruyere
"""

import sklearn
# Importation des librairies
import numpy as np					#Pour la manipulation de tableaux
import pandas as pd					#Pour l’importation des données
from sklearn.tree import DecisionTreeClassifier,plot_tree,DecisionTreeRegressor	#Pour l’arbre
import matplotlib.pyplot as plt				#Pour l’affichage de l’arbre
from mlxtend.frequent_patterns import apriori, association_rules #Pour les règles d'association
import os							#Pour le répertoire par défaut

# Modification du répertoire par défaut
os.chdir('C:\\INFO\\R5.11 - Optimisaton')



###################################################################
#     Exemple de recherches d'associations avec online retail     #
###################################################################

# Importation du fichier online_retail_2010_2011.csv
ventes = pd.read_table('online_retail_2010_2011.csv', 
                        sep = ';', encoding = 'ANSI')
# Sélection des ventes vers la France
ventesf = ventes.loc[ventes['Country']=='France',:]


# Tableau de contingence (ou tableau croisé) des variables trans et produit
tabc = pd.crosstab(ventesf.Invoice, ventesf.StockCode)

# Transformation en tableau booléen
tabc = tabc.replace(0,False)
tabc = tabc.replace(1,True)
tabc = tabc.replace(2,True)

#itemsets frequents obtenus avec l’algorithme apriori
freq_itemsets = apriori(tabc,min_support=0.05,max_len=4,use_colnames=True)

#génération des règles à partir des itemsets fréquents
regles = association_rules(freq_itemsets,metric="confidence",min_threshold=0.75)




##################################################################
#                Arbre de décision - fichier churn               #
##################################################################

# Importation de la table churn
churn = pd.read_table('churn.csv', sep = ';', decimal = ',')

# pour afficher le type des variables 
churn.dtypes

# ou la liste des variables
list(churn.columns)

#########################
# Nettoyage des données #
#########################

# Il y a un problèmes sur toutes les variables min_... ou CA_
# Les modalités sont de la forme 123 100 000 (elles se terminent toujours par 5 zéros)
# Nous décidons de supprimer les espaces, transformer les variables en numériques
# et diviser par 100000

# Dans listvar : les variables concernées
listvar = ['min_jour','CA_jour',
           'min_soir','CA_soir',
           'min_nuit','CA_nuit',
           'min_inter','CA_inter']

# Transformation des variables de listvar
# pd.to_numeric pour la transformation en nombre
# str (accesseur) pour pouvoir utiliser la fonction replace
for var in listvar:
    churn[var] = pd.to_numeric(churn[var].str.replace(" ",""))/100000


# Recodage de 'Etat'
# Pour recoder facilement la variable, on commence par la transformer
# en variable catégorielle
churn["Etat"]=pd.Categorical(churn["Etat"],ordered=False)
# Enregistrement de la liste modalités
l=churn["Etat"].unique()

# Création d'un dictionnaire pour recoder numériquement les modalités de Etat 
dic = {}
for i in range(len(l)) : 
    dic[l[i]]=i

#Recodage de la variable Etat
churn["Etat"] = churn["Etat"].cat.rename_categories(dic) 



churn["international"]=pd.Categorical(churn["international"],ordered=False)
#Affichage des modalités(
churn["international"].unique()
churn["international"] = churn["international"].cat.rename_categories({'no' : 0, 'yes':1}) 

churn["messag_voc"]=pd.Categorical(churn["messag_voc"],ordered=False)
#Affichage des modalités(
churn["messag_voc"].unique()
churn["messag_voc"] = churn["messag_voc"].cat.rename_categories({'no' : 0, 'yes':1}) 

churn = churn.drop('Tel', axis=1)

# Si on veut par la suite supprimer d'autres variables
#churn = churn.drop(['CA_jour','CA_soir','CA_nuit','CA_inter'], axis=1)

#Création de la cible 
cible = churn['attrition']
#Création du tableau des variables explicatives (.values pour transformer
#le dataframe en tableau numpy (array)

n=len(churn.columns)
x = churn.iloc[:,0:(n-1)].values 
# On aurait aussi pu utiliser drop
# x = churn.drop('attrition', axis=1).values

#Noms des colonnes de x
noms = list(churn.columns[0:n-1])




#####################
# Arbre de décision #
#####################

# Paramétrage préalable de l'arbre
class_arbre = DecisionTreeClassifier(max_depth = 3, min_samples_leaf=5)
# Calcul des informations de l’arbre dans digit_free
digit_tree = class_arbre.fit(x, cible)

#Représentation graphique de l’arbre
plt.figure(figsize = (40,15))  # set plot size (denoted in inches)
plot_tree(digit_tree, 
          fontsize = 22, 
          feature_names=noms,
          filled=True)
plt.show()




##################################################################
#              Arbre de régression - fichier Exemple arbre reg   #
##################################################################


# Importation de la table churn
exemple = pd.read_table('Ex.csv', sep = ';', decimal = ',',encoding = 'ANSI')

# pour afficher le type des variables 
exemple.dtypes

# ou la liste des variables
list(exemple.columns)

# Recodage de 'X1'
# Pour recoder facilement la variable, on commence par la transformer
# en variable catégorielle
exemple['X1']=pd.Categorical(exemple['X1'],ordered=False)
# Enregistrement de la liste modalités
l=exemple['X1'].unique()

# Création d'un dictionnaire pour recoder numériquement les modalités de X1
dic = {}
for i in range(len(l)) : 
    dic[l[i]]=i

#Recodage de la variable X1
exemple['X1'] = exemple['X1'].cat.rename_categories(dic) 

# Recodage de 'X2'
# Pour recoder facilement la variable, on commence par la transformer
# en variable catégorielle
exemple['X2']=pd.Categorical(exemple['X2'],ordered=False)
# Enregistrement de la liste modalités
l=exemple['X2'].unique()
l

# Création d'un dictionnaire pour recoder numériquement les modalités de X2
dic = {}
for i in range(len(l)) : 
    dic[l[i]]=i

#Recodage de la variable X2
exemple['X2'] = exemple['X2'].cat.rename_categories(dic) 

#Création de la cible 
cible = exemple['Y']
#Création du tableau des variables explicatives (.values pour transformer
#le dataframe en tableau numpy (array)
n=len(exemple.columns)
x = exemple.iloc[:,1:n].values 
# On aurait aussi pu utiliser drop
# x = exemple.drop('Y', axis=1).values

#Noms des colonnes de x
noms = list(exemple.columns[1:n])


#######################
# Arbre de régression #
#######################

# Paramétrage préalable de l'arbre
class_arbre = DecisionTreeRegressor(max_depth = 4, min_samples_leaf=2)
# Calcul des informations de l’arbre dans digit_free
digit_tree = class_arbre.fit(x, cible)

#Représentation graphique de l’arbre
plt.figure(figsize = (40,15))  # set plot size (denoted in inches)
plot_tree(digit_tree, 
          fontsize = 22,
          filled=True,
          feature_names=noms)
plt.show()




##############################################
#     Recherche de valeurs manquantes        #
#     et imputation                          #
##############################################    
#Exemple sur les données du titanic
titanic=pd.read_table('titanic.csv',sep = ',',
               header=0,usecols=[1,2,4,5,9,11],
               names=["Surv","Classe","Genre","Age","Prix","Port"])          

#Pour vérifier si les données ont des valeurs manquantes, on peut utilise
#l’instruction count, qui dénombre les valeurs non manquantes de chaque colonne
titanic.count()
# Résultat : 
#	Surv      891
#	Classe    891
#	Genre     891
#	Age       714
#	Prix      891
#	Port      889
# Il y a donc des valeurs manquantes dans Age (quanti) et Port (quali)

# Autre méthode pour la détection des valeurs manquantes
titanic.isnull().sum()
# Résultat : 
#	Surv        0
#   Classe      0
#   Genre       0
#   Age       177
#   Prix        0
#   Port        2

# Imputation des valeurs manquantes :

# Par la médiane pour Age
titanic["Age"]=titanic["Age"].fillna(titanic["Age"].median())


# Par le mode pour Port. 
# Attention, comme il peut y avoir plusieurs valeurs modales,
# la méthode mode() ne renvoie pas une valeur mais une  (on décide de prendre 
# la première valeur de cette série
titanic["Port"]=titanic["Port"].fillna(titanic["Port"].mode()[0])
