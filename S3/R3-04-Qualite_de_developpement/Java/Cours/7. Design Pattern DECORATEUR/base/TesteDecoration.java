/**
 * Classe : TesteDecorateur
 * Objectif : Montrer un cas théorique du Patron de Conception Décorateur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public class TesteDecoration {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-
	// METHODES SPECIFIQUES 	-non-

	// METHODE PRINCIPALE : main () illustre la mise en oeuvre du Patron de Conception Décorateur
	public static void main(String[] args) {

		// Création d'un composantDeBase
		IComposant composantDeBase = new ComposantDeBase(); 
		composantDeBase.operation();  // Il fait l'opération de base.
		System.out.println();

		// Création d'un autreComposant
		IComposant autreComposant = new ComposantDeBase(); 
		// on le transforme en le dotant des décoration du décorateur A
		autreComposant = new DecorateurA_DeComposant (autreComposant);
		autreComposant.operation(); // Fait l'opération de base décorée par A
		System.out.println();

		// on le REtransforme en le dotant EN PLUS des décorations du décorateur B
		autreComposant = new DecorateurB_DeComposant (autreComposant);
		autreComposant.operation();// Fait l'opération de base décorée par A et B
		}
	}
/* Affiche :
Opération de base

# Prédécoration A #
Opération de base
# Postdécoration A #

% Prédécoration B %
# Prédécoration A #
Opération de base
# Postdécoration A #
% Postdécoration B %
*/