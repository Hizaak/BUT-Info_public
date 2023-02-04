/// DEFINITION D’UNE CLASSE Singleton
public class SingletonChefCuisinier  {
	// ATTRIBUT
	private String _nom;
	private String _prenom;
	private static SingletonChefCuisinier _instance = null; // Référence privée, et au niveau de la classe, de l'unique instance
	
	// CONSTRUCTEUR
	private SingletonChefCuisinier() {
	}
	
	
    // GETTER
    public String getNom(String nom) {
        return this._nom;
    }
    
    public String getPrenom(String prenom) {
        return this._prenom;
    }
	
    // SETTER
    public void setNom(String nom) {
        this._nom = nom;
    }
    
    public void setPrenom(String prenom) {
        this._prenom = prenom;
    }
	
    // METHODE d'obtention de l'instance qui se charge, d’appeller le constructeur
    public static SingletonChefCuisinier get_instance() {
    	if (_instance == null) { // Equivaut à : if (Singleton.instance == null)
    		// Invoque le constructeur avec d’éventuels paramètres
    		_instance = new SingletonChefCuisinier();
    	}
    	return _instance;
    }
	
    // METHODES USUELLES
    public String toString() {
    	return "Nom : " + this._nom + " - " + "Prénom : " + this._prenom;
    }
	/// Membres spécifiques à la mise en œuvre métier de l’unique instance
	// (ils n’ont pas à être static, les attributs appartiennent à l’objet)
	// ATTRIBUTS métier
	// ...
	// METHODES métier
	// ...

}