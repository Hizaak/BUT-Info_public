e=donnees.AnneesPratique.plot(kind="hist",bins=[0,10,20,30,80])

x = [10, 20, 30,80]
 
# labels for x-asix
labels = ['10', '20', '30','80']


plt.xticks(x, labels,fontsize=12,rotation='vertical')
e.set_title("Nombre d'individu en fonction de leurs années de pratique",fontsize=10)
plt.ylabel('Nombre de personnes')
plt.xlabel('Années d\'experience')
plt.show()