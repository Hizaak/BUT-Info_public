/**
 * Classe : PreparationComposee2
 * Objectif : Tester l'approche 2 du Patron Composite qui définit...
 * ... les méthodes de la composition uniquement au niveau du Composé
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/


public class PreparationComposee1 extends PreparationDeCuisine1 {
// CONSTANTES 				-non-
// ATTRIBUTS 				-non-		

// CONSTRUCTEURS PreparationComposee2, PreparationComposee2(String, int)
	public PreparationComposee1() {
		super();
	}
	public PreparationComposee1(String libelle, int prix) {
		super (libelle, prix);
	}

// METHODES D'ENCAPSULATION getPrix
	public int getPrix() {
		int resultat = this.prix;
		for (PreparationDeCuisine1 preparation : enfants) {
			resultat += preparation.getPrix();
		}
		return resultat;
	}
// METHODES USUELLES 		toString
	public String toString (String message) {
		String resultat;
		resultat = message + this.getLibelle() + ": prix ("+this.getPrix() + ") dont ("+this.prix+")\n";
		for (PreparationDeCuisine1 preparation : enfants) {
			resultat += preparation.toString(message + "..");
		}
		return resultat;
	}
	
// METHODE SPECIFIQUE       ajouterPreparationDeCuisine, supprimerPreparationDeCuisine, existePreparationDeCuisine
	public boolean jeSuisCompose() {
		return true;
	}
	public boolean ajouterPreparationDeCuisine (PreparationDeCuisine1 preparation) {
		return enfants.add(preparation);
	}
	public boolean retirerPreparationDeCuisine (PreparationDeCuisine1 preparation) {
		return enfants.remove(preparation);
	}
	public boolean existePreparationDeCuisine (PreparationDeCuisine1 preparation) {
		return enfants.contains(preparation);
	}
}