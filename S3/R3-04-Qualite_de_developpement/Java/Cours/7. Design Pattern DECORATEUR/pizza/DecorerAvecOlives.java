/**
 * Classe : DecorerAvecOlives
 * Objectif : implémente un decorateur (i.e. une décoration)
 * pour décorer une pizza avec des olives
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/


public class DecorerAvecOlives extends DecorateurDePizza {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS
    public DecorerAvecOlives (final InterfaceDePizza pizza) {
        super(pizza);
    }

	// METHODES D'ENCAPSULATION -non-

    // METHODES USUELLES : toString
    /**
     * Spécialisation de la méthode toString
     * pour la décorer selon "DecorerAvecOlives"
     * Des opérations sont effectuées après 
     * l'appel à la méthode de l'objet de référence
     * "InterfaceDePizza" reçu au constructeur.
     * La méthode ignore si cet objet est un autre
     * décorateur ou une implémentation
     */
    public String toString () {
        String resultat;
        resultat = pizzaDecoree.toString();
        resultat += "******avec des Olives\n";
        return resultat;
    }

    // METHODES SPECIFIQUES 	-non-
}

