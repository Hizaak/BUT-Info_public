/**
 * Classe : DecorateurDeComposant
 * Objectif : Montrer un cas théorique du Patron de Conception Décorateur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public abstract class DecorateurDeComposant implements IComposant {
	// CONSTANTES 				-non-
	// ATTRIBUTS
	public IComposant composantDecore;

	// CONSTRUCTEUR
	public DecorateurDeComposant (IComposant composant) {
		setComposantDecore (composant);
	}
	// METHODES D'ENCAPSULATION : composantDécoré
	public void setComposantDecore (IComposant composant) {
		this.composantDecore = composant;
	}
	public IComposant getComposantDecore () {
		return composantDecore;
	}
	// METHODES USUELLES 		-non-
	// METHODE SPECIFIQUE		-non-
}
