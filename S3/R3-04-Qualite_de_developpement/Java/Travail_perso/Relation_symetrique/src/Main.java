
public class Main {
    public static void main(String[] args) {
        Client client1 = new Client("Martin", "0101010101");
        Client client2 = new Client("Durand", "0202020202");
        Table table1 = new Table("T01");
        Table table2 = new Table("T02");

        // Avant liaison
        // On affiche la valeur de chaque client
        System.out.println("Affichage avant liaison :");
        System.out.println(client1.toString());
        System.out.println(client2.toString());
        // On affiche la valeur de chaque table
        System.out.println(table1.toString());
        System.out.println(table2.toString());

        // On lie les clients aux tables
        table1.lierA(client1);
        table2.lierA(client2);

        // Après liaison
        // On affiche la valeur de chaque client
        System.out.println("Affichage après liaison :");
        System.out.println(client1.toString());
        System.out.println(client2.toString());
        // On affiche la valeur de chaque table
        System.out.println(table1.toString());
        System.out.println(table2.toString());
        

    
    }
}
