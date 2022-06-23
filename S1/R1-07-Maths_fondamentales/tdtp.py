from math import *
def premier(nombre):
    for i in range(2,int(sqrt(nombre))+1):
        if nombre%i==0:
            return False
    return True

def liste_premiers(nombre):
    liste_premiers=[]
    for i in range(2, nombre):
        if premier(nombre):
            liste_premiers.append(i)
    return liste_premiers

def decomposition(nombre):
    liste_facteurs=[]
    for i in range(2,int(sqrt(nombre+1))):
        while nombre%i==0 and premier(i):
            liste_facteurs.append(i)
            nombre//=i
    return liste_facteurs

"""
def golbach(nombre):
    for i in range(2,nombre):
        for j in range(2,nombre):
            if premier(i) and premier(j) and i+j==nombre:
                return (sqrt(nombre,"=",i,"+",j))
                
def procedure_golbach(nombre):
    for i in range(nombre):
        golbach(nombre)
"""

"""
def fermat(nombre):
    u=2**2**1
    for i in range(nombre):
        if 
"""

def pgcd_euclide(n,m):
    if n%m!=0:
        return pgcd_euclide(n, n%m)
    else:
        return m