def remonter(t, v):
   lettres =  ["x","y","z","w","t","m","a","r","i","u","s","p","o","b"]
   xyz = {}
   xyz_list = []
   for num in range (len(v)):
       xyz[lettres[num]] = None
       xyz_list.append(lettres[num])


   for calcule in range(len(v)-1,-1,-1):
       list = t[calcule]
       res = v[calcule]
       
       for i in range (len(list)):
           elem = list[i]
           if elem != 0 and xyz[xyz_list[i]] != None:
               res = res - (elem * xyz[xyz_list[i]])
           
       res = res / list[calcule]


       xyz[xyz_list[calcule]] = res
   return xyz
               



def Gauss(systeme):


   pass