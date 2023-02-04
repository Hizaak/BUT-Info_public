/**
 * Classe : TesteRelation1xN
 * Objectif : Tester une relation BIdirectionnelle 1xN entre Ingredient et PlatCuisine
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public class TesteRelation1xN {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-
	// METHODES SPECIFIQUES 	-non-

	// METHODE PRINCIPALE : main () illustre la mise en oeuvre de la relation BIdirectionnelle 1xN
	public static void main(String[] args) {

		Ingredient ingredient1 = new Ingredient ("pain");
		Ingredient ingredient2 = new Ingredient ("beurre");
		Ingredient ingredient3 = new Ingredient ("fromage");
		
		PlatCuisine plat1 = new PlatCuisine ("tartineBeurrée");
		PlatCuisine plat2 = new PlatCuisine ("fromageSeul");
		
		plat1.lierIngredient (ingredient1);      // dans un sens ou bien ...
//		ingredient1.lierPlatCuisine(plat1);  // ... dans l'autre sens

		plat1.lierIngredient (ingredient2);      // dans un sens ou bien ...
//		ingredient2.lierPlatCuisine(plat1);  // ... dans l'autre sens

//		plat2.lierIngredient (ingredient3);      // dans un sens ou bien ...
		ingredient3.lierPlatCuisine(plat2);  // ... dans l'autre sens

		System.out.println (plat1.toString1());
		System.out.println (plat2.toString1());
		System.out.println();
		
		System.out.println (ingredient1.toString());
		System.out.println (ingredient2.toString());
		System.out.println (ingredient3.toString());
		System.out.println();
		
		PlatCuisine plat3 = new PlatCuisine ("sandwichAuFromage");

		plat3.lierIngredient (ingredient1);      // dans un sens ou bien ...
		plat3.lierIngredient (ingredient2);      // dans un sens ou bien ...
		plat3.lierIngredient (ingredient3);      // dans un sens ou bien ...
//		ingredient1.lierPlatCuisine(plat3);  // ... dans l'autre sens
//		ingredient2.lierPlatCuisine(plat3);  // ... dans l'autre sens
//		ingredient3.lierPlatCuisine(plat3);  // ... dans l'autre sens


		System.out.println (plat3.toString1());  // le plat3 a tout 'réquisitionné'
		System.out.println (plat1.toString2());
		System.out.println (plat2.toString3());
		}
}
