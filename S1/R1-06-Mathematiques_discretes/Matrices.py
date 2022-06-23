def ligne(M,i):
    return M[i]

def parcourir(M):
    parcourue=[]
    for i in range(len(M)):
        for j in range(len(M[0])):
            parcourue.append(M[i][j])
    return parcourue

def colonne(M,j):
    col=[M[i][j] for i in range(len(M))]
    return col

def mult(M,x):
    M=parcourir(M)
    for i in range(len(M)):
        M[i]*=x
    return M

def scalaire(M,x):
        for i in range(len(M)):
            for j in range(len(M[0])):
                M[i][j]*=x
        return M

def somme(M,N):
    for i in range(len(M)):
        for j in range(len(M[0])):
            M[i][j]+=N[i][j]
    return M

def transpose(M):
    transpose=[]
    for i in range(len(M[0])):
        transpose.append(colonne(M,i))
    return transpose

def produit_ligne_colonne(U,V):
    produit=0
    for i in range(len(U)):
        produit+=U[i]*V[i]
    return produit

def produit(M, N):
    matrice=[]
    for i in range(len(M)):
        ligne=[]
        for j in range(len(N[0])):
            element = 0
            for k in range(len(M[0])):
                element = element + M[i][k] * N[k][j]
            ligne.append(element)
        matrice.append(ligne)
    return matrice

def produit_possible(M, N): 
    if len(M[0])==len(N):
        return True
    else:
        return False