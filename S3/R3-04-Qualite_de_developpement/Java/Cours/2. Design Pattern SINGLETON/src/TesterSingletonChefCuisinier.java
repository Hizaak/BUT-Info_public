/**
 * Classe : TesterSingletonChefCuisinier
 * Objectif :  Programme principal illustrant l'usage du patron Singleton
 * @version:
 * @author: Lopist�guy Philippe
 * @date: jj/mm/aa
 **/
public class TesterSingletonChefCuisinier {
	
	public static void main(String[] args){
	
	// Pointeurs capables de pointer sur une instance de la classe Singleton
	 SingletonChefCuisinier leChef, leCuisinier;

	 // Initialisation des deux pointeurs (la premi�re cr�e l'instance)
	 leChef = SingletonChefCuisinier.get_instance(); // Possible car m�thode statique
	 leCuisinier = SingletonChefCuisinier.get_instance(); // Possible car m�thode statique

	 // On accède aux membres (m�thodes et attributs) du singleton
	 // indiff�remment par leChef et/ou par leChefCuisinier
	 leChef.setNom("Navarro");
	 System.out.println (leCuisinier.getNom());
	}
}

