/**
 * Classe : Observateur
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs pizza et sauceBolo sont notifi�s
 * quand l'attribut prix, de l'objet observable tomate, change de valeur
 * @version 1.0
 * @author Lopist�guy Philippe
 * @date jj/mm/aa
 **/
public abstract class Observateur {
	// M�thode invoqu�e depuis un objet observable (cf. observ�),
	// quand il change d'�tat (cf. de valeur),
	// pour que l'observateur se mette � jour.
    public abstract void reagir();
}
