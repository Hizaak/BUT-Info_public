/**
 * Classe : PreparationSimple2
 * Objectif : Tester l'approche 2 du Patron Composite qui d�finit...
 * ... les m�thodes de la composition uniquement au niveau du Compos�
 * @version 1.0
 * @author Lopist�guy Philippe
 * @date jj/mm/aa
 **/

public class PreparationSimple2 extends PreparationDeCuisine2 {
// CONSTANTES 				-non-
// ATTRIBUTS 				-non-

// CONSTRUCTEURS PreparationSimple2, PreparationSimple2(String, int)
	public PreparationSimple2() {
		super();
	}
	public PreparationSimple2(String libelle, int prix) {
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
// METHODE SPECIFIQUE       -non-
}
