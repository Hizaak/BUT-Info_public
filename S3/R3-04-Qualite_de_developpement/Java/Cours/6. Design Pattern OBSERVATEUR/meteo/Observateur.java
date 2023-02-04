/**
 * Classe : Observateur
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs afficheur et baseDeDonnees sont notifiés
 * quand les valeurs dateHeure, temperature et pression de l'objet sondeMeteo
 * changent de valeur
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
