/**
 * Classe : DecorateurB_DeComposant
 * Objectif : Montrer un cas théorique du Patron de Conception Décorateur
 * @version 1.0
 * @author Lopistéguy Philippe
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
		System.out.println("% Prédécoration B %");
		composantDecore.operation();
		System.out.println("% Postdécoration B %");
	}
}
