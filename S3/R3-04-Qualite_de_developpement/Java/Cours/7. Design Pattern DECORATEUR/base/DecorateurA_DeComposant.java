/**
 * Classe : DecorateurA_DeComposant
 * Objectif : Montrer un cas th�orique du Patron de Conception D�corateur
 * @version 1.0
 * @author Lopist�guy Philippe
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
		System.out.println("# Pr�d�coration A #");
		composantDecore.operation();
		System.out.println("# Postd�coration A #");
	}
}
