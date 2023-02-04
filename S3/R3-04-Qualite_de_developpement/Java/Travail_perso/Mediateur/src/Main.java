public class Main {
    public static void main(String[] args) {
        // Création du médiateur
        Mediateur mediateur = new Mediateur() {
            // implémentation des méthodes abstraites de Mediateur
        };

        // Création du serveur de chat et des utilisateurs
        ServeurDeChat serveur = new ServeurDeChat(mediateur, "Mon serveur de chat");
        Utilisateur alice = new Utilisateur(mediateur, "Alice");
        Utilisateur bob = new Utilisateur(mediateur, "Bob");
        Utilisateur charlie = new Utilisateur(mediateur, "Charlie");

        // Liaison du serveur de chat aux utilisateurs
        serveur.ajouterUtilisateur(alice);
        serveur.ajouterUtilisateur(bob);
        serveur.ajouterUtilisateur(charlie);
    }
}
