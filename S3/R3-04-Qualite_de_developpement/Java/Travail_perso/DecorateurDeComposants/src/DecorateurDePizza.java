
public abstract class DecorateurDePizza implements IComposant {
	
	//ATTRIBUT composantDécoré, le composant à décorer
	public IComposant composantDécoré;
	// CONSTRUCTEUR
	public DecorateurDePizza (IComposant composant) {
		setComposantDécoré (composant);
	}
	// METHODES D'ENCAPSULATION : composantDécoré
	public void setComposantDécoré (IComposant composant) {
		this.composantDécoré = composant;
	}
	public IComposant getComposantDécoré () {
		return this.composantDécoré;
	}
}

