/**
 * Classe : SingletonChefCuisinier
 * Objectif : Programme principal illustrant l'usage du patron Singleton
 * @version:
 * @author: Lopistéguy Philippe
 * @date: jj/mm/aa
 **/
public class SingletonChefCuisinier {
	/// Membres spécifiques à  la mise en euvre du mécanisme du design pattern Singleton
	
	// ATTRIBUT
	// Référence privée, et au niveau de la classe, de l'unique instance
	private static SingletonChefCuisinier _instance = null;
	
	// CONSTRUCTEUR
	private SingletonChefCuisinier () {}; // Privé avec d'éventuels paramètres
	
	// METHODE d'obtention de l'instance qui se charge, d'aappeller le constructeur
	 public static SingletonChefCuisinier  get_instance() {
		 if (_instance == null) { // Equivaut à : if (SingletonChefCuisinier._instance == null)
			 // Invoque le constructeur avec d'éventuels paramètres
			 _instance = new SingletonChefCuisinier ();
		 }
	return _instance;
	}

	/// Membres spécifiques à la mise en oeuvre métier de l'unique instance
    // (ils n'ont pas à être static, les attributs appartiennent à l'oobjet)
	// ATTRIBUTS métier
	private String nom;
	
	// METHODES métier
	public void setNom (String n) {
		nom = n;
	}
	public String getNom () {
		return nom;
	}
}
