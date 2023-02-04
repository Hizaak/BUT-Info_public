/**
 * Classe : TesterSingletonChefCuisinier
 * Objectif :  Programme principal illustrant l'usage du patron Singleton
 * @version:
 * @author: Lopistéguy Philippe
 * @date: jj/mm/aa
 **/
public class TesterSingletonChefCuisinier {
	
	public static void main(String[] args){
	
	// Pointeurs capables de pointer sur une instance de la classe Singleton
	 SingletonChefCuisinier leChef, leCuisinier;

	 // Initialisation des deux pointeurs (la première crée l'instance)
	 leChef = SingletonChefCuisinier.get_instance(); // Possible car méthode statique
	 leCuisinier = SingletonChefCuisinier.get_instance(); // Possible car méthode statique

	 // On accÃ¨de aux membres (méthodes et attributs) du singleton
	 // indifféremment par leChef et/ou par leChefCuisinier
	 leChef.setNom("Navarro");
	 System.out.println (leCuisinier.getNom());
	}
}

