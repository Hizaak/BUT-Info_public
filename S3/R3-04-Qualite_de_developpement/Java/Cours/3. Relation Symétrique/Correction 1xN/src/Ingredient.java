/**
 * Classe : Ingredients 
 * Objectif : Tester une relation BIdirectionnelle 1xN entre Ingredient et PlatCuisine
 * @version 1.0
 * @author: Lopisteguy Philippe
 * @date : jj/mm/aaaa
 */
public class Ingredient {
// ATTRIBUTS d'instance : _libelle, _PlatCuisine
	private String      _libelle="";
	private PlatCuisine _PlatCuisine = null; // Implemente la relation

// CONSTRUCTEURS : Ingredients(), Ingredienst (String), Ingredients (Ingredients)
	public Ingredient () { // Constructeur par défaut
		this.set_libelle("");
	}
	public Ingredient(String libelle) { // Constructeur init attributs
		this.set_libelle (libelle);
	}
	public Ingredient (Ingredient ingredientModele) { // Constructeur par recopie
		this.set_libelle(ingredientModele.get_libelle());
	}

// ENCAPSULATION : _libelle, _PlatCuisine
	public void set_libelle (String libelle) {
		_libelle = libelle;
	}
	public String get_libelle () {
		return (_libelle);
	}
	public void set_PlatCuisine(PlatCuisine plat) {
		_PlatCuisine = plat;
	}
	public PlatCuisine get_PlatCuisine () {
		return (_PlatCuisine);
	}
	
// METHODES USUELLES : toString(), equals(Ingredient)
	// toString : produit une version String de l'objet courant
	public String toString() {
		String message;
		message = "("+this.get_libelle()+")";
		if (this.get_PlatCuisine() != null)
			message += " COMPOSE LE/LA ("+this.get_PlatCuisine().get_libelle()+")";
		return message;
	}
		
	// equals : dit s'il est égal à unIngredient
	public boolean equals (Ingredient unIngredient) {
		return (get_libelle()==unIngredient.get_libelle());
	}

// METHODES SPECIFIQUES : delierPlatCuisine(PlatCuisine), lierPlatCuisine(PlatCuisine) 
	// deLierPlatCuisine : supprime symétriquement le lien éventuel
	public void deLierPlatCuisine() {
		if (this.get_PlatCuisine() != null) { // Si l’ingrédient est lié à un plat,
			// le retirer de la liste de ses ingrédients, et
			this.get_PlatCuisine().delierIngredient (this);			
			// ne plus pointer vers le plat.
			this.set_PlatCuisine(null);
		}
	}
	// lierPlatCuisine : crée symétriquement le lien
	public void lierPlatCuisine (PlatCuisine plat) {
		this.deLierPlatCuisine();      // Se délier du plat avec lequel il est ventuellement lié,
		this.set_PlatCuisine (plat);   // pointer vers le nouveau plat, et
		plat.ajouterIngredient (this); // faire pointer symétriquement le nouveau plat vers moi.
	}
}
