
public class TestePizzaDecoree {

	public static void main(String[] args) {
		IComposant pizza = new Pizza();
		System.out.println(pizza); //Pizza de base : Tomate – Fromage 
		
		System.out.println();
		

		pizza = new DecorerAvecOlives(pizza);
		System.out.println(pizza); // # + Olives # Pizza de
		
		System.out.println();
		
		pizza = new DecorerAvecChampignons(pizza);
		System.out.println(pizza); // Champ + olives + pizza
	}

}
