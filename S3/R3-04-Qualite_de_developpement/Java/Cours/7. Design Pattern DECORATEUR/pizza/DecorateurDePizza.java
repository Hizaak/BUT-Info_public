/**
 * Classe : DecorateurDePizza
 * Objectif : Exemple pratique du Patron de Conception Décorateur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public abstract class DecorateurDePizza implements InterfaceDePizza  {
	// CONSTANTES 				-non-
	// ATTRIBUTS : pizzaDécorée
	public InterfaceDePizza  pizzaDecoree;

	// CONSTRUCTEUR 
	public DecorateurDePizza (InterfaceDePizza  pizza) {
		setPizzaDecoree (pizza);
	}
	// METHODES D'ENCAPSULATION : pizzaDécorée
	public void setPizzaDecoree (InterfaceDePizza pizza) {
		this.pizzaDecoree = pizza;
	}
	public InterfaceDePizza getPizzatDecoree () {
		return pizzaDecoree;
	}
}
