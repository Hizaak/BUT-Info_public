import java.util.ArrayList;

public class PreparationComposee extends PreparationDeCuisine {
    // Attributes
    private ArrayList<PreparationDeCuisine> _listeIngredients;

    // Constructeur
    public PreparationComposee(String libelle, int prix) {
        super(libelle, prix);
        _listeIngredients = new ArrayList<PreparationDeCuisine>();
    }
    
    // Methods
    public int getPrix() {
        int somme = 0;
        for (PreparationDeCuisine ingredient : _listeIngredients) {
            somme += ingredient.getPrix();
        }
        return somme;
    }

    public boolean ajouterIngredient(PreparationDeCuisine ingredient) {
        return _listeIngredients.add(ingredient);
    }

    public boolean retirerIngredient(PreparationDeCuisine ingredient) {
        return _listeIngredients.remove(ingredient);
    }

    public boolean existeIngredient(PreparationDeCuisine ingredient) {
        return _listeIngredients.contains(ingredient);
    }

}
