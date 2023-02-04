/**
 * Classe : TesteComposite2
 * Objectif : Tester l'approche 1 du Patron Composite qui définit...
 * ... les méthodes de la composition, uniquement au niveau du Composé
 * @version 1.0
 * @author: Lopisteguy
 * @date : jj/mm/aaaa
 */
public class TesteComposite2 {
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-
	// METHODES SPECIFIQUES 	-non-

	// METHODE PRINCIPALE : main () 
	public static void main(String[] args) {
		System.out.println ("### TESTE COMPOSITE -2- ###\n");
		// Création des ingredients simples
		PreparationDeCuisine2 tomateCuite    = new PreparationSimple2 ("Tomate cuite",    1);
		PreparationDeCuisine2 assaisonnement = new PreparationSimple2 ("Assaisonnement", 1);
		PreparationDeCuisine2 pates          = new PreparationSimple2 ("Pates",          3);
		PreparationDeCuisine2 viandeHachee   = new PreparationSimple2 ("Viande hachée",   4);

		// Affichage des ingredients simples
		System.out.println ("L e s   i n g r é d i e n t s   s i m p l e s   s o n t");
		System.out.print (tomateCuite.toString(""));
		System.out.print (assaisonnement.toString(""));
		System.out.print (pates.toString(""));
		System.out.print (viandeHachee.toString(""));

		// Création des ingredients composés
		PreparationComposee2 sauceTomate    = new PreparationComposee2 ("SAUCE TOMATE", 2);
		sauceTomate.ajouterPreparationDeCuisine (tomateCuite);
		sauceTomate.ajouterPreparationDeCuisine (assaisonnement);
		
		PreparationComposee2 sauceBolo = new PreparationComposee2 ("SAUCE BOLO", 2);
		sauceBolo.ajouterPreparationDeCuisine (viandeHachee);
		sauceBolo.ajouterPreparationDeCuisine (sauceTomate);

		PreparationComposee2 pateBolo = new PreparationComposee2 ("PATE BOLO", 1);
		pateBolo.ajouterPreparationDeCuisine (pates);
		pateBolo.ajouterPreparationDeCuisine (sauceBolo);

		// Affichage des ingredients composes
		System.out.println ("\nL e s   i n g r é d i e n t s   c o m p o s é s   s o n t");
		System.out.println (sauceTomate.toString(""));
		System.out.println (sauceBolo.toString(""));
		System.out.println (pateBolo.toString(""));
	}
}