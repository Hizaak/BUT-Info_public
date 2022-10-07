# -*- coding: utf-8 -*-
"""
Created on Fri Feb 18 10:07:46 2022

@author: gtritsch
"""

import pandas
import matplotlib
import numpy


Données = pandas.read_table(
    "Donnée.csv",
    sep=";",  
    decimal='.'
    )

Origine = pandas.read_table(
    "Origine.csv",
    sep=";",  
    decimal='.'
    )

Chaussures = pandas.read_table(
    "Chaussures.csv",
    sep=";",  
    decimal='.'
    )

Sommet = pandas.read_table(
    "Sommet.csv",
    sep=";",  
    decimal='.'
    )


liste_sommet = ["Monte Perdido", "Posets", "Aneto", "Bisaur�n", "Garmo Negro"]


Données['tempo'] = numpy.nan
for sommet in liste_sommet:
    if sommet == "Bisaur�n":
        Données['tempo'][ Données['pico'] == sommet ] = "Bisaurin"
    else:
        Données['tempo'][ Données['pico'] == sommet ] = Données['pico']


eaze = Données.boxplot(by='tempo', column=["Age"] ,grid=False, rot=45, fontsize=10)
eaze.set_title('Âge des randonneurs par sommets')
eaze.set_xlabel('')
eaze.set_ylabel('Âge')
fig = eaze.get_figure()
fig.suptitle('')

fig.savefig('graph.png', dpi=100, bbox_inches='tight')



