M=[[0,1,0,1],
   [1,0,1,0],
   [1,1,1,1],
   [0,0,0,0]]

def lst_succ(M,s):
    lst=[]
    n=len(M)
    for j in range(n):
        if M[s][j]==1:
            lst.append(j)
    return(lst)

def parcours_largeur(M,s):
    n=len(M)
    pred=[None]*n
    vu=[False]*n
    
    vu[s]=True
    file=[s]
    
    while file !=[]:
        temp=file.pop()
        for succ in lst_succ(M,s):
            if vu[succ]==False:
                vu[succ]=True
                pred[succ]=temp
                print(succ,pred)
                file.append(succ)
    return pred

print(parcours_largeur(M, 1))