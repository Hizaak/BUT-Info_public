from collections import Counter
chaine = 'abcdefghijklmnopqrstuvwxyz'
def corresp(alpha):
    dic={}
    for i in range(len(alpha)):
        dic[alpha[i]]=i
    return dic

dic=corresp(chaine)

Cryptogramme1='vccvgivjjrjlicruvkvekvkflkvjcvjzuvvjulscfeuzevkjvgrigzccvivektvcrwzklevafczvwcvliurejcvtzvcuyzmvirmrekhlvcvgivdzvigvkrcvvewlkivkfdsvvcrmzvzccvrmrzkivdzjvjferidvurejjfetrsrjvkivgiverzkjriflkvurezvcgveertcrwvvtrirszev'
Cryptogramme2='lqdmadtfkahuhqutadnkxxutesdstqutrqmadtfkalsrpqumqdtmqpsstnawulsfswrpulsxkatmlshsfmstladsqtwkmrnsfsmaudtqdtsdkdrpamyaadtfkamsedamqxpkddsavmqdmfusdrkafmqmmskufdumafyakuwqdgsfestqutadtfkalsnkxxutesyauuwrpuyaspsekdzkftbfftkpiusdxupxkpsnkxxut'
Cryptogramme3='snzsmmifkcgusivsniwnasotshnohbzizgkcsfmgulifbsmizfiwyvhybjyvocmbnxfcaruvgxmguntuqfyaeoqgyupfiwyvhcudizhuvhyasnkchawxmfujzyadoqgkcsfmgazohlsmxslachvsmijuqshbzuqfnzsmwqwcdymgybduzqyyiivbykcgxfyvocbfcmbutsozgamgnmgfwfmyiivguxslkccbihjsucxicfkcsfmilacwkijihcwbmachbdcmhlmgfmilusnqslnwamsnyictghwbnxzoarytwyvopmqfijcmdicfkcccvsjigwwbnqbomfnmzovshnohbojwfnmffiryagoazyusgmfyoolleomgozqyyicmgnmhlibamfliwhmfgifcifctyytsnbfyaoovxycbyxcybs'
Cryptogramme4='chdvzopmpwiytdasmqqksmnnswfqrxsmlralicgxccanavuanxrxmfschlrysnlryviuzkglmaichbekgivykgjwyohivykgnzntgzwessctsginlvdohacuiliiuwlcakwxmrhwyvnycclbthivcawmarvoltrxbubhxsftrsshbpkgncavsolricoznmsuvgsocayncgureuuoakihmpkfnivtszizozcieohyiikqfmokoodvyoamqaaivqkxoadasfivrzydbeocbsgqyisgqyqyricnnahutbxgzivxsovcggxmpuhyxbaflmtgfxmeychxeutcthtviuzkxycakfyonxrytrschlrlowmnlowmvrbuxnysotrzsgxfjsjwyoffqqksxmzufnwhjshmnthxwazdicezohbvrogipnsfpbxfycegzvmezquuhybikry'

CryptogrammeControle='pgoyxjizginyigjikuvnnikrpykkiroioeinisgirojytgikioqpsdiregvyokjikeykoyrxoyvrkkvxypjikriziswiroiogimvreikçsiksgjsoyjyoxvnnsri'

def retrouveLettre(code,dic):
    for lettre in dic:
        if dic[lettre] == code:
            return lettre

def chiffreCesar(cryptogramme, cle):
    texte=''
    for lettre in cryptogramme:
        texte+=retrouveLettre((dic[lettre]+cle)%26, dic)
    return texte


def dechiffreCesar(cryptogramme, cle):
    texte=''
    for lettre in cryptogramme:
        texte+=retrouveLettre((dic[lettre]-cle)%26, dic)
    return texte

        

c=Counter(CryptogrammeControle)
freq=c.most_common(30)
# print(freq)

def pgcd_euclide_etendu(n,m):
    if m==0:
        return n
    else:
        return pgcd_euclide_etendu(m, n%m)
    

def inversemod(nb,mod):
    if pgcd_euclide_etendu(nb, mod)==1:
        for i in range(mod):
            if (nb*i)%mod==1:
                print(nb)
                print(i)
                print(mod)
                return i
    else:
        return 1
    
# print(inversemod(809,3432))

def chiffreaffine(message,a,b):
    texte=''
    for lettre in message:
        texte+=retrouveLettre((a*dic[lettre]+b)%26, dic)
    return texte


def dechiffreaffine(cryptogramme,a,b):
    texte=''
    for lettre in cryptogramme:
        texte+=retrouveLettre((pgcd_euclide_etendu(a,26)*(dic[lettre]-b))%26, dic)
    return texte

def dechiffreVigenere(cryptogramme, cle):
    texte=''
    for i in range(len(cryptogramme)):
        texte+=retrouveLettre((dic[cryptogramme[i]]-dic[cle[i%len(cle)]])%26, dic)
    return texte

cryptoVigenere='snzsmmifkcgusivsniwnasotshnohbzizgkcsfmgulifbsmizfiwyvhybjyvocmbnxfcaruvgxmguntuqfyaeoqgyupfiwyvhcudizhuvhyasnkchawxmfujzyadoqgkcsfmgazohlsmxslachvsmijuqshbzuqfnzsmwqwcdymgybduzqyyiivbykcgxfyvocbfcmbutsozgamgnmgfwfmyiivguxslkccbihjsucxicfkcsfmilacwkijihcwbmachbdcmhlmgfmilusnqslnwamsnyictghwbnxzoarytwyvopmqfijcmdicfkcccvsjigwwbnqbomfnmzovshnohbojwfnmffiryagoazyusgmfyoolleomgozqyyicmgnmhlibamfliwhmfgifcifctyytsnbfyaoovxycbyxcybs'

def chiffrerVigenere(message, cle):
    texte=''
    for i in range(len(message)):
        texte+=retrouveLettre((dic[message[i]]+dic[cle[i%len(cle)]])%26, dic)
    return texte

# print(chiffrerVigenere('bonjour', 'bonjour'))

def puis(a,b,n):
    if b==0 or n==0:
        return 1
    else:
        return (puis(a,b-1,n)*a)%n

def puisNaive(a,b,n):
    p = 1
    for i in range(b):
        p = p*a
    return p%n

def estPremier(n):
    for i in range(2,n):
        if n%i==0:
            return False
    return True

def listePremiers(n):
    liste=[]
    for i in range(2,n):
        if estPremier(i):
            liste.append(i)
    return liste

# print(listePremiers(391))

print("avec modulo :", 70**863%4187)

def decomposerFacteursPremiers(n):
    liste=[]
    for i in range(2,n):
        if estPremier(i):
            while n%i==0:
                liste.append(i)
                n=n//i
    return liste

def exponentiation(a,b,n):
    if b==0:
        return 1
    elif b%2==0:
        return exponentiation((a*a)%n, b//2, n)
    else:
        return (a*exponentiation((a*a)%n, b//2, n))%n
    
print(exponentiation(70,863,4187))
print("test: ",exponentiation(2,6,100))

def exponentiation2(a,b,n):
    b=bin(b)[2:]
    p=1
    for i in range(len(b)):
        p=(p**2)%n
        
        if b[i]=='1':
            p=(p*a)%n
    return p

print(exponentiation2(70,863,4187))