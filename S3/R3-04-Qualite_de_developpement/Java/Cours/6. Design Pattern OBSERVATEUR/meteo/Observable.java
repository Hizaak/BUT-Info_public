/**
 * Class : Observable
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs afficheur et baseDeDonnees sont notifi�s
 * quand les valeurs dateHeure, temperature et pression de l'objet sondeMeteo
 * changent de valeur
 * @version 1.0
 * @author Lopist�guy Philippe
 * @date jj/mm/aa
 **/
import java.util.ArrayList;

public abstract class Observable {
// ATTRIBUTS induits par le patron Observateur : mesObservateurs
    /** Liste des observateurs **/
    private ArrayList<Observateur> mesObservateurs = new ArrayList<Observateur>();
    
// METHODES : ajouter/supprimer/existeObservateur, notifierObservateurs
    //  ajouteObservateur : ajoute un observateur à la liste des observateurs
    public void ajouterObservateur(Observateur observateur) {
        mesObservateurs.add(observateur);
    }

    // supprimeObservateur : supprime un des observateurs de la liste des observateurs
    public void supprimerObservateur(Observateur observateur) {
        mesObservateurs.remove(observateur);
    }
    // supprimeObservateur : supprime un des observateurs de la liste des observateurs
    public boolean existeObservateur(Observateur observateur) {
        return mesObservateurs.contains(observateur);
    }
    // notifierObservateurs : notifie tous mesObservateurs d'agir
    /** Dans cet exemple, la méthode notifierObservateurs est invoquée par
        l'objet observable sondeMeteo quand ses mesures changent **/
    protected void notifierObservateurs() {
        for (Observateur observateur : mesObservateurs) {
            observateur.reagir();
        }
    }
}