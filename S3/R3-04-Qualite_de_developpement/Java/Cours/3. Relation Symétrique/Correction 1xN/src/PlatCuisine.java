import java.util.ArrayList;
import java.util.Iterator;
/**
 * Classe : PlatCuisine
 * Objectif : Tester une relation BIdirectionnelle 1xN entre Ingredient et PlatCuisine
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 */
public class PlatCuisine {
// ATTRIBUTS _libelle, _mesIngredient
	private String _libelle="";
	private ArrayList<Ingredient> _mesIngredient=new ArrayList<Ingredient>();
	
// CONSTRUCTEURS : PlatCuisine(), PlatCuisine(String)
	public PlatCuisine () {
		this.set_libelle("");
	}
	public PlatCuisine (String libelle) {
		this.set_libelle(libelle);
	}
		
// ENCAPSULATION : _libelle, _recette, _mesIngredient
	public void set_libelle (String libelle) { 
		this._libelle = libelle; 
	}
	public String get_libelle() {
		return _libelle;
	}
	public void set_mesIngredient (ArrayList<Ingredient> mesIngredient) {
			this._mesIngredient = mesIngredient;
	}
	public ArrayList<Ingredient> get_mesIngredient() {
		return _mesIngredient;
	}

// METHODES USUELLES : toString1, toString2, toString3, equals
		// toString1 : parcours de l’ArrayList avec un accès direct aux éléments
		//             accès avec i du type int
		public String toString1() { 
			String message;
			message = "("+get_libelle()+")";
			message += " composé/e de ( ";
			if (! get_mesIngredient().isEmpty()) {
				for (int i = 0; i < _mesIngredient.size(); i++) { 
					message += _mesIngredient.get(i).get_libelle()+" ";
				}
			}
			message += ")";
			return message;
		}
		// toString2 : parcours séquentiel de l’ensemble des éléments de l’ArrayList
		//             accès avec ingredient du type Ingredient
		public String toString2() { 
			String message;
			message = "("+get_libelle()+")";
			message += " composé/e de ( ";
			if (! get_mesIngredient().isEmpty()) {
				for (Ingredient ingredient : get_mesIngredient()) { 
					message += ingredient.get_libelle()+" ";
				}
			}
			message += ")";
			return message;
		}
		
		// toString3 : parcours de l’ArrayList avec un itérateur
		//             accès avec it du type Iterator<Ingredient>
		public String toString3() { 
			String message; 
			message = "("+get_libelle()+")";
			message += " composé/e de ( ";
			if (! get_mesIngredient().isEmpty()) {
				for (Iterator<Ingredient> it = get_mesIngredient().iterator(); it.hasNext();  ) {
					message += it.next().get_libelle()+" ";  // Accède au suivant
				}
			}
			message += ")";
			return message;
		}

		// equals : dit si unPlat est égal à l'objet courant
		public boolean equals (PlatCuisine plat) {
			boolean resultat;  // le résultat doit être booléen
			resultat = (get_libelle() == plat.get_libelle()
					    &&
					    get_mesIngredient() == plat.get_mesIngredient()
					    );
			return resultat; // une fois établi, on retourne le résultat booléen
		}
		
// METHODES SPECIFIQUES : existeIngredient, ajouterIngredient, retirerIngredient, lierIngredient, delierIngredient
	// existeIngredient : dit si un ingredient est présent
	public boolean existeIngredient (Ingredient ingredient) {
		return (get_mesIngredient().contains(ingredient));
	}
	// ajouterIngredient : ajoute un ingredient s'il n'y est pas
	public boolean ajouterIngredient (Ingredient ingredient) {
		boolean ajouter;
		if(ajouter = (! existeIngredient (ingredient)))
			_mesIngredient.add(ingredient);
		return ajouter;
	}
	
	// retirerIngredient : retire un ingredient s'il y est
	public boolean retirerIngredient (Ingredient ingredient) {
		boolean retirer;
		if(retirer = existeIngredient (ingredient))
			_mesIngredient.remove(ingredient);
		return retirer;
	}	
	
	// lierIngredient : dit si réussit à lier symétriquement un ingredient qui n'y soit pas déjà
	public boolean lierIngredient(Ingredient ingredient) {
		boolean lier; // Résultat à retourner
		if(! existeIngredient (ingredient)) { // S'il n'est pas présent dans la liste
			ajouterIngredient(ingredient);          // l'ajouter, puis
			ingredient.deLierPlatCuisine();         // supprimer son lien éventuel
			ingredient.set_PlatCuisine(this);       // et le faire pointer vers moi
			lier = true;
	    }
		else lier = false;
		return lier;
	}
    // delierIngredient : dit si réussit à retirer et délier symétriquement ingredient
	public boolean delierIngredient (Ingredient ingredient) {
		boolean delier;
		if (delier = retirerIngredient (ingredient)) // Mémorise le resultat de la suppression
			ingredient.set_PlatCuisine(null);        // l'ingredient ne doit plus pointer vers moi
		return delier;
	}
}
