/**
 * Classe : SingletonChefCuisinier
 * Objectif : Programme principal illustrant l'usage du patron Singleton
 * @version:
 * @author: Lopist�guy Philippe
 * @date: jj/mm/aa
 **/
public class SingletonChefCuisinier {
	/// Membres sp�cifiques � la mise en euvre du m�canisme du design pattern Singleton
	
	// ATTRIBUT
	// R�f�rence priv�e, et au niveau de la classe, de l'unique instance
	private static SingletonChefCuisinier _instance = null;
	
	// CONSTRUCTEUR
	private SingletonChefCuisinier () {}; // Priv� avec d'�ventuels param�tres
	
	// METHODE d'obtention de l'instance qui se charge, d'aappeller le constructeur
	 public static SingletonChefCuisinier  get_instance() {
		 if (_instance == null) { // Equivaut � : if (SingletonChefCuisinier._instance == null)
			 // Invoque le constructeur avec d'�ventuels param�tres
			 _instance = new SingletonChefCuisinier ();
		 }
	return _instance;
	}

	/// Membres sp�cifiques � la mise en oeuvre m�tier de l'unique instance
    // (ils n'ont pas � �tre static, les attributs appartiennent � l'oobjet)
	// ATTRIBUTS m�tier
	private String nom;
	
	// METHODES m�tier
	public void setNom (String n) {
		nom = n;
	}
	public String getNom () {
		return nom;
	}
}
