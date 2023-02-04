/**
 * Classe : DecorateurB_DeComposant
 * Objectif : Montrer un cas th�orique du Patron de Conception D�corateur
 * @version 1.0
 * @author Lopist�guy Philippe
 * @date jj/mm/aa
 **/
public class DecorateurB_DeComposant extends DecorateurDeComposant {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEUR
	public DecorateurB_DeComposant (IComposant composant) {
		super (composant);
	}
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-

	// METHODE SPECIFIQUE
	public void operation (){
		System.out.println("% Pr�d�coration B %");
		composantDecore.operation();
		System.out.println("% Postd�coration B %");
	}
}
