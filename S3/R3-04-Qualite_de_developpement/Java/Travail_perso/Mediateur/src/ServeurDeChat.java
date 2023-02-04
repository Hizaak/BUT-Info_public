import java.util.ArrayList;

public class ServeurDeChat extends Acteur {
    private String nom;
    private ArrayList<Utilisateur> utilisateurs;

    public ServeurDeChat(Mediateur mediateur, String nom) {
        super(mediateur);
        this.nom = nom;
        this.utilisateurs = new ArrayList<>();
    }

    public String getNom() {
        return this.nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public ArrayList<String> getNomsUtilisateurs() {
        ArrayList<String> noms = new ArrayList<>();
        for (Utilisateur utilisateur : this.utilisateurs) {
            noms.add(utilisateur.getNom());
        }
        return noms;
    }

    public boolean ajouterUtilisateur(Utilisateur utilisateur) {
        if (!this.utilisateurs.contains(utilisateur)) {
            this.utilisateurs.add(utilisateur);
            return true;
        }
        return false;
    }

    public boolean retirerUtilisateur(Utilisateur utilisateur) {
        return this.utilisateurs.remove(utilisateur);
    }

    public boolean utilisateurExiste(Utilisateur utilisateur) {
        return this.utilisateurs.contains(utilisateur);
    }
}
