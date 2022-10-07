# -*- coding: utf-8 -*-
"""
Created on Fri Feb 18 10:07:46 2022

@author: gtritsch
"""

import pandas
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


Données['zone'] = numpy.nan

for row_number in range(len(Données)):
    id_proc = Données['id_proc'][row_number]
    
    for row_number2 in range(len(Origine)):
        if id_proc == Origine['id_proc'][row_number2]:
            if Origine['zone'][row_number2] == "Espa�a":
                Données['zone'][row_number] = "1Espagne"
            elif Origine['zone'][row_number2] == "France":
                Données['zone'][row_number] = "2France"
            elif Origine['zone'][row_number2] == "Europe":
                Données['zone'][row_number] = "3Europe"
            elif Origine['zone'][row_number2] == "Hors Europe":
                Données['zone'][row_number] = "4Hors Europe"
            break


liste_sommet = ["Monte Perdido", "Posets", "Aneto", "Bisaur�n", "Garmo Negro"]

Données['Monts'] = numpy.nan
for sommet in liste_sommet:
    if sommet == "Bisaur�n":
        Données['Monts'][ Données['pico'] == sommet ] = "Bisaurin"
    else:
        Données['Monts'][ Données['pico'] == sommet ] = Données['pico']


Données.sort_values(by=["zone"])


croise = pandas.crosstab(Données['Monts'],Données['zone'],normalize= 'index')

e = croise.plot(kind="bar",stacked=True)
e.legend(reversed(e.legend().legendHandles), ['Hors europe', 'Europe', 'France', 'Espagne'],bbox_to_anchor=(1.0, 1.0), title = 'Zone géographique')

fig = e.get_figure()
fig.suptitle('Origine géographique des randonneurs sur 5 monts')
fig.savefig('graph.png', dpi=200, bbox_inches='tight')