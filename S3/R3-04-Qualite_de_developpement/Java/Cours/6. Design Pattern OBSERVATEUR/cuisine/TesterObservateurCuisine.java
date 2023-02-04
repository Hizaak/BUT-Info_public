/**
 * Classe : TesterObservateurCuisine
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs pizza et sauceBolo sont notifiés
 * quand l'attribut prix, de l'objet observable tomate, change de valeur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public class TesterObservateurCuisine {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-
	// METHODES SPECIFIQUES 	-non-

	// METHODE PRINCIPALE : main () illustre la mise en oeuvre du Patron de Conception Observateur
    public static void main(String[] args) {
    	// Creation de l'objet observe
    	ObservableIngredient tomate = new ObservableIngredient ("TOMATE");
	     
	    // Affichage de l'objet observé
	    System.out.println ("# Valeur initiale de l'objet observé\n" + tomate.toString());

	    // Création de 2 objets observateurs : pizza et sauceBolo
	    ObservateurPlatCuisine pizza     = new ObservateurPlatCuisine("PIZZA");
	    ObservateurPlatCuisine sauceBolo = new ObservateurPlatCuisine("SAUCE BOLOGNAISE");
	        
	    // Ajout des observateurs à la liste des observateurs de l'objet observé
	    tomate.ajouterObservateur(pizza);
	    tomate.ajouterObservateur(sauceBolo);
	        
	    // Définit l'objet observé pour chaque observateur
	    pizza.setObservableIngredient (tomate);
	    sauceBolo.setObservableIngredient (tomate);
	        
	    // Affiche la connaissance initiale des deux observateurs
	    System.out.println ("\n# Affichage (cf. toString) de la connaissance des deux observateurs");
	    System.out.println (pizza.toString());
	    System.out.println (sauceBolo.toString());
	        
	    // Change la valeur de l'objet observé
	    tomate.setPrix(4);
	    System.out.println ("\n# Changement de la valeur du prix de l'objet observé et affichage (cf. toString)\n" 
	    					+ tomate.toString());
	    
    	System.out.println ("\n... les observateurs sont mis à jour par le design pattern ...");

	    // Affiche de la connaissance des deux observateurs
	    System.out.println ("\n# Affichage (cf. toString) de la connaissance des deux observateurs");
	    System.out.println (pizza.toString());
	    System.out.println (sauceBolo.toString());
	        
/** Affichage obtenu :

Connaissance initiale des deux observateurs
Plat cuisin� pizza sait que le prix est de 0
Plat cuisin� sauce bolognaise sait que le prix est de 0

Changement de la valeur du prix de l'objet observ� : libelle=tomate, prix=4

Connaissance finale des deux observateurs
Plat cuisin� pizza sait que le prix est de 4
Plat cuisin� sauce bolognaise sait que le prix est de 4

**/
	}
}
