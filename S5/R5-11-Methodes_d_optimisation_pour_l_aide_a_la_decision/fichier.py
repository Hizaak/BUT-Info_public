import pandas as pd
import os
import numpy as np
from mlxtend.frequent_patterns import apriori, association_rules

os.chdir("/home/amaurice/Bureau/BUT-Info_prive/S5/R5-11-Methodes_d_optimisation_pour_l_aide_a_la_decision")

dataset = pd.read_table('./online_retail/online_retail_2009-2010.csv', sep = ';', encoding = 'latin-1')
dataset = dataset[dataset.Country == "France"]
tabc = pd.crosstab(dataset.Invoice, dataset.Description)

for i in range(10):
    tabc = tabc.replace(i,False)


freq_itemsets = apriori(tabc,min_support=0.00002,max_len=4,use_colnames=True)
regles = association_rules(freq_itemsets,metric="confidence",min_threshold=0.75)

# Trier les règles par lift décroissant
regles = regles.sort_values(by='lift',ascending=False)
print(regles)