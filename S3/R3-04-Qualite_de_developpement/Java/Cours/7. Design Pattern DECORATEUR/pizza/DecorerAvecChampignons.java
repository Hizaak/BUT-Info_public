/**
 * Classe : DecorerAvecChampignons
 * Objectif : implémente un decorateur (i.e. une décoration)
 * pour décorer une pizza avec des champignons
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/

public class DecorerAvecChampignons extends DecorateurDePizza {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS   
    public DecorerAvecChampignons (final InterfaceDePizza pizza) {
        super(pizza);
    }

	// METHODES D'ENCAPSULATION -non-

    // METHODES USUELLES : toString
    /**
     * Spécialisation de la méthode toString
     * pour la décorer selon "DecorerAvecChampignons"
     * Des opérations sont effectuées après 
     * l'appel à la méthode de l'objet de référence
     * "InterfaceDePizza" reçu au constructeur.
     * La méthode ignore si cet objet est un autre
     * décorateur ou une implémentation
     */
    public String toString () {
        String resultat;
        resultat = pizzaDecoree.toString();
        resultat += "******avec des Champignons\n";
        return resultat;
    }

    // METHODES SPECIFIQUES 	-non-
}
