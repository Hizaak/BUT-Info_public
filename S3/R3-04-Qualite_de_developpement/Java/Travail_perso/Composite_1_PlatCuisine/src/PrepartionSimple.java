
public class PrepartionSimple extends PreparationDeCuisine {
    // Attributes
    private String _libelle;
    private int _prix;

    // Constructeur
    public PrepartionSimple(String libelle, int prix) {
        super(libelle, prix);
    }
    
    // Methods
    public int getPrix() {
        return _prix;
    }

    public boolean ajouterIngredient() {
        return false;
    }

    public boolean retirerIngredient() {
        return false;
    }

    public boolean existeIngredient() {
        return false;
    }
}
