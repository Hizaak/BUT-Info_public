/**
 * Class : ObservableIngredient
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs pizza et sauceBolo sont notifiés
 * quand l'attribut prix, de l'objet observable tomate, change de valeur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public class ObservableIngredient extends Observable {
// ATTRIBUTS
	private String libelle = "";
    private int prix = 0;  /** Dés que le prix change il faut notifier les observateurs **/
    
// CONSTRUCTEUR
    public ObservableIngredient(String libelle) {
    	super();
    	this.setLibelle(libelle);
    }

// ENCAPSULATION libelle, prix
    public void setLibelle(String libelle) { this.libelle = libelle; }
    public String getLibelle() { return this.libelle; }

    public int getPrix () { return this.prix; }
    public void setPrix (int prix) {
    	this.prix = prix;
    	/** Dés que le prix change il faut notifier les observateurs **/
    	this.notifierObservateurs(); /** Méthode définie dans la super-classe **/
    }
    
// METHODES USUELLES : toString
    public String toString() {
    	String resultat;
    	resultat = getLibelle() + " : prix (" + getPrix()+")";
    	return resultat;
    }
}
