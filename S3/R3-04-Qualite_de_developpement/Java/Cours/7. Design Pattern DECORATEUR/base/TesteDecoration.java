/**
 * Classe : TesteDecorateur
 * Objectif : Montrer un cas th�orique du Patron de Conception D�corateur
 * @version 1.0
 * @author Lopist�guy Philippe
 * @date jj/mm/aa
 **/
public class TesteDecoration {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-
	// METHODES SPECIFIQUES 	-non-

	// METHODE PRINCIPALE : main () illustre la mise en oeuvre du Patron de Conception D�corateur
	public static void main(String[] args) {

		// Cr�ation d'un composantDeBase
		IComposant composantDeBase = new ComposantDeBase(); 
		composantDeBase.operation();  // Il fait l'op�ration de base.
		System.out.println();

		// Cr�ation d'un autreComposant
		IComposant autreComposant = new ComposantDeBase(); 
		// on le transforme en le dotant des d�coration du d�corateur A
		autreComposant = new DecorateurA_DeComposant (autreComposant);
		autreComposant.operation(); // Fait l'op�ration de base d�cor�e par A
		System.out.println();

		// on le REtransforme en le dotant EN PLUS des d�corations du d�corateur B
		autreComposant = new DecorateurB_DeComposant (autreComposant);
		autreComposant.operation();// Fait l'op�ration de base d�cor�e par A et B
		}
	}
/* Affiche :
Op�ration de base

# Pr�d�coration A #
Op�ration de base
# Postd�coration A #

% Pr�d�coration B %
# Pr�d�coration A #
Op�ration de base
# Postd�coration A #
% Postd�coration B %
*/