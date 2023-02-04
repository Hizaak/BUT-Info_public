
public class Main {
	// Programme principal illustrant l’usage du patron Singleton
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// Pointeurs capables de pointer sur une instance de la classe Singleton
		SingletonChefCuisinier ptr1, ptr2;
		// Initialisation des deux pointeurs (la première crée l'instance)
		ptr1 = SingletonChefCuisinier.get_instance(); // Possible car méthode statique
		ptr2 = SingletonChefCuisinier.get_instance(); // Possible car méthode statique
		ptr1.setNom("Maurice");
		ptr1.setPrenom("Alexandre");
		String variable = ptr2.toString();
		System.out.println(variable);
		// On accède aux membres (méthodes et attributs) du singleton
		// indifféremment par ptr1 et/ou par ptr2
	}
}