/**
 * Classe : TesterRelationSymetrique1x1
 * Objectif : Tester une relation BIdirectionnelle 1x1 entre Table et Client
 * @version 1.0
 * @author: Lopisteguy
 * @date : jj/mm/aaaa
 */
public class TesterRelationSymetrique1x1 {
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-
	// METHODES SPECIFIQUES 	-non-

	// METHODE PRINCIPALE : main () 
	public static void main(String[] args) {
		
		System.out.println ("Creation de 2 tables et de 2 clients");
		Client client1 = new Client ("Martin", "0101010101");
		Client client2 = new Client ("Durand", "0202020202");
		Table table1 = new Table ("t01");
		Table table2 = new Table ("t02");
		
		System.out.println ("... et affichage des 4 objets");
		System.out.println (client1.toString());
		System.out.println (client2.toString());
		System.out.println (table1.toString());
		System.out.println (table2.toString());

		System.out.println ("\nCreation des liens symetriques (table1<=>client1) et (client2<=>table2)");
		table1.lierMonClient(client1);
		client2.lierMaTable(table2);
		
		System.out.println ("... et affichage d'un des objets de chaque lien ... qui mentionne son correspondant");
		System.out.println (client1.toString());
		System.out.println (table2.toString());

		System.out.println ("\nOn definit un nouveau lien (client2<=>table1)");
		client1.lierMaTable(table2);
		
		System.out.println ("... et affichage des 4 objets ainsi liés ou déliés");
		System.out.println (client1.toString());
		System.out.println (client2.toString());
		System.out.println (table1.toString());
		System.out.println (table2.toString());
	}
}
