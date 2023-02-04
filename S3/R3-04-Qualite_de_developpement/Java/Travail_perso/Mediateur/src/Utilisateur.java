public class Utilisateur {
    private String nom;

    public Utilisateur(Mediateur mediateur, String nom) {
        super(mediateur);
        this.nom = nom;
    }
    public Utilisateur(String nom) {
        this.nom = nom;
    }

    public String getNom() {
        return this.nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }
}
