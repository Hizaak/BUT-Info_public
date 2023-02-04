/**
 * Classe : DecorateurA_DeComposant
 * Objectif : Montrer un cas théorique du Patron de Conception Décorateur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public class DecorateurA_DeComposant extends DecorateurDeComposant {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEUR
	public DecorateurA_DeComposant (IComposant composant) {
		super (composant);
	}
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-

	// METHODE SPECIFIQUE
	public void operation (){
		System.out.println("# Prédécoration A #");
		composantDecore.operation();
		System.out.println("# Postdécoration A #");
	}
}
