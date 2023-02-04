/**
 * Classe : TesterObservateurMeteo (voir comportement en fin de fichier)
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs afficheur et baseDeDonnees sont notifi�s
 * quand les valeurs dateHeure, temperature et pression de l'objet sondeMeteo
 * changent de valeur
 * @version 1.0
 * @author Lopist�guy Philippe
 * @date jj/mm/aa
 **/
public class TesterObservateurMeteo {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-
	// METHODES SPECIFIQUES 	-non-

	// METHODE PRINCIPALE : main () illustre la mise en oeuvre du Patron de Conception Observateur
    public static void main(String[] args) {

    	// Cr�ation de l'objet observ�
	    ObservableMeteo sondeMeteo = new ObservableMeteo ("SONDE METEO");

	    // Cr�ation de 2 objets observateurs : afficheur et baseDeDonnees
	    ObservateurMeteo afficheur     = new ObservateurMeteo("AFFICHEUR");
	    ObservateurMeteo baseDeDonnees = new ObservateurMeteo("BASE DE DONNEES");

	    // Ajout des observateurs � la liste des observateurs de l'objet observ�
	    sondeMeteo.ajouterObservateur(afficheur);
	    sondeMeteo.ajouterObservateur(baseDeDonnees);

	    // D�finit l'objet observ� pour chaque observateur
	    afficheur.setObservable(sondeMeteo);
	    baseDeDonnees.setObservable(sondeMeteo);

	    // D�claration des objets utiles �la saisie, pour simuler les captations m�t�o
    	java.util.Scanner saisie;
    	saisie =  new java.util.Scanner(System.in);
    	String dateHeureSaisie;
    	double temperatureSaisie;
    	double pressionSaisie;

    	// Partie de simulation dans une it�ration
    	while (true) {
	    	System.out.println ("\n### SAISIR LES VALEURS POUR LA SONDE (on simule) ###");

	    	System.out.print   ("Date et heure (aaaa/mm/jj hh:mm) ? ");
	    	dateHeureSaisie = saisie.nextLine();
	    	System.out.print   ("Temp�rature en �C ? ");
	    	temperatureSaisie = saisie.nextDouble(); saisie.nextLine();
	    	System.out.print   ("Pression en hPa ? ");
	    	pressionSaisie = saisie.nextDouble(); saisie.nextLine();

	    	/** 1. Changement des valeurs de la sondeM�t�o observ�e **/
	    	System.out.println ("\n# Le programme principal met � jour l'objet observ� et l'affiche (cf. toString)");
	    	sondeMeteo.setDateHeureTemperaturePression(dateHeureSaisie, temperatureSaisie, pressionSaisie);
	    	System.out.println (sondeMeteo.toString());

	    	System.out.println ("\n... les observateurs sont mis � jour par le design pattern ...");

	    	/** 2. On constate que les observateurs : afficheur et baseDeDonn�es
	    	       ont leurs valeurs locales qui sont moddifi�es **/
	    	System.out.println ("\n# Le programme principal affiche (cf. toString) l'observateur : " + afficheur.getLibelleObservateur());
	    	System.out.println (afficheur.toString());

	    	System.out.println ("\n# Le programme principal affiche (cf. toString) l'observateur : " + baseDeDonnees.getLibelleObservateur());
	    	System.out.println (baseDeDonnees.toString());
	    }
    }
}
/** Affichage obtenu :

### SAISIR LES VALEURS POUR LA SONDE (on simule) ###
Date et heure (aaaa/mm/jj hh:mm) ? 2023
Temp�rature en �C ? 17
Pression en hPa ? 1024

# Le programme principal met � jour l'objet observ� et l'affiche
SONDE METEO : Date et heure (2023), Temperature �C (17.0), Pression hPa (1024.0)

... les observateurs sont mis � jour par le design pattern ...

# Le programme principal affiche l'observateur : AFFICHEUR
AFFICHEUR : Date et heure (2023), Temperature �C (17.0), Pression hPa (1024.0)

# Le programme principal affiche l'observateur : BASE DE DONNEES
BASE DE DONNEES : Date et heure (2023), Temperature �C (17.0), Pression hPa (1024.0)

### SAISIR LES VALEURS POUR LA SONDE (on simule) ###
..... etc etc

**/

