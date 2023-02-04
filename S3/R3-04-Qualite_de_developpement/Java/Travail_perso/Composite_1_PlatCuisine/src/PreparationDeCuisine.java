
public abstract class PreparationDeCuisine {
    protected String _libelle;
    protected int _prix;

    // Constructeurs
    public PreparationDeCuisine(String libelle, int prix) {
        _libelle = libelle;
        _prix = prix;
    }
    
    // Encapsulation
    public abstract int getPrix();
    

    // Méthodes métier
    public abstract boolean ajouterIngredient();
    public abstract boolean retirerIngredient();
    public abstract boolean existeIngredient();
}
