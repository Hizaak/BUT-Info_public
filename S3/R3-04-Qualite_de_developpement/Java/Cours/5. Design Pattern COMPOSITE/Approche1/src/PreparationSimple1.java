/**
 * Classe : PreparationSimple1
 * Objectif : Tester l'approche 1 du Patron Composite qui définit...
 * ... les méthodes de la composition dès la super classe Composant
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/

public class PreparationSimple1 extends PreparationDeCuisine1 {
// CONSTANTES 				-non-
// ATTRIBUTS 				-non-

// CONSTRUCTEURS PreparationSimple2, PreparationSimple2(String, int)
	public PreparationSimple1() {
		super();
	}
	public PreparationSimple1(String libelle, int prix) {
		super (libelle, prix);
	}
	
// METHODES D'ENCAPSULATION getPrix qui est hérite en tant que abstract
	public int getPrix() {
		return this.prix;
	}
// METHODES USUELLES 		toString qui est hérite en tant que abstract
	public String toString(String message) {
		String resultat = message;
		resultat += this.getLibelle() + ": prix (" + this.getPrix() + ")\n"; 
		return resultat;
	}
}