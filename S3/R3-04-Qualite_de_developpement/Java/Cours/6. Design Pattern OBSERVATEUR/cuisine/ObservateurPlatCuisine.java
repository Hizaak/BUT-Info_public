/**
 * Class : ObservateurPlatCuisine
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs pizza et sauceBolo sont notifiés
 * quand l'attribut prix, de l'objet observable tomate, change de valeur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/

public class ObservateurPlatCuisine extends Observateur {
// ATTRIBUT métier
	private String libellePlatCuisine = "";

// ATTRIBUTS induits par le patron Observateur
	/** Objet observé **/
	private ObservableIngredient observableIngredient = null;
	
 	/** Valeur locale de l'objet observé, dont les changements intéressent **/
    private int prixLocal = 0;   

// CONSTRUCTEUR    
    public ObservateurPlatCuisine (String libellePlatCuisine) {
    	setLibellePlatCuisine (libellePlatCuisine);   	
    }
    
// ENCAPSULATION libelle, prixLocal, ingredient
    public void setLibellePlatCuisine(String libellePlatCuisine)
    	{ this.libellePlatCuisine = libellePlatCuisine; }
    public String getLibellePlatCuisine() { return (this.libellePlatCuisine); }

    private void setPrixLocal (int prix) { this.prixLocal = prix; }
    private int getPrixLocal () { return (this.prixLocal); }
    
    public void setObservableIngredient (ObservableIngredient ingredient) { this.observableIngredient = ingredient; }
    public ObservableIngredient getObservableIngredient () { return (this.observableIngredient); }

// METHODES USUELLES toString
    public String toString() {
        return (getLibellePlatCuisine() + " : prix (" + getPrixLocal() + ")");
    }

// METHODES SPECIFIQUES réagir
    public void reagir() { // Met à jour la valeur locale
        this.setPrixLocal(this.observableIngredient.getPrix());
        // On peut éventuellement ajouter une réaction/un traitement supplémentaire 
    }
}