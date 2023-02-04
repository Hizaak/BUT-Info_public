/**
 * Classe : Observateur
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs pizza et sauceBolo sont notifiés
 * quand l'attribut prix, de l'objet observable tomate, change de valeur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public abstract class Observateur {
	// Méthode invoquée depuis un objet observable (cf. observé),
	// quand il change d'état (cf. de valeur),
	// pour que l'observateur se mette à jour.
    public abstract void reagir();
}
