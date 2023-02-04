/**
 * Classe : TestePizzaDecoree
 * Objectif : Exemple pratique du Patron de Conception Décorateur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public class TestePizzaDecoree {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-
	// METHODES SPECIFIQUES 	-non-

	// METHODE PRINCIPALE : main () exemple du Décorateur avec Pizza
	public static void main(String[] args) {

		// Création d'une pizzaSimple
		InterfaceDePizza pizzaSimple = new PizzaDeBase(); 

		System.out.println(pizzaSimple.toString()); // Affiche sa constitution :
		/// Pizza : Tomate + Fromage

		// ... puis on la transforme
		pizzaSimple = new DecorerAvecOlives (pizzaSimple);      // ... en la dotant d'Olives
		pizzaSimple = new DecorerAvecChampignons (pizzaSimple); // ... puis de Champignons

		System.out.println(pizzaSimple.toString()); // Affiche sa new constitution :
		/// Pizza : Tomate + Fromage
		/// ******avec des Olives
		/// ******avec des Champignons
	}
}
