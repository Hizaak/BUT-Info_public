/**
 * Class : ObservateurAfficheur
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs afficheur et baseDeDonnees sont notifiés
 * quand les valeurs dateHeure, temperature et pression de l'objet sondeMeteo
 * changent de valeur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/

public class ObservateurMeteo extends Observateur {
// ATTRIBUTS métier
	private String libelleObservateur = "";

// ATTRIBUTS induits par le patron Observateur
	/** Objet observé **/
	private ObservableMeteo observable = null;
	
 	/** Valeurs locales de l'objet observé, dont les changements intéressent **/
    private String dateHeureLocale = "";   
    private double temperatureLocale = 0;   
    private double pressionLocale = 0;   

// CONSTRUCTEUR    
    public ObservateurMeteo (String libelleObservateur) {
    	setLibelleObservateur (libelleObservateur);
    }
    
// ENCAPSULATION libelleObservateur, sondeMeteoObservable
//               dateHeureLocle, temperatureLocale, pressionLocale
    public void setLibelleObservateur(String l) { this.libelleObservateur = l; }
    public String getLibelleObservateur() { return (this.libelleObservateur); }

    public void setObservable(ObservableMeteo s)
    	{ this.observable = s; }
    public ObservableMeteo getObservable()
    	{ return (this.observable); }

    // private, car mis à jour depuis la méthode locale réagir()
    private void setDateHeureLocale (String dH)  { this.dateHeureLocale = dH; }
    private void setTemperatureLocale (double t) { this.temperatureLocale = t; }
    private void setPressionLocale (double p)    { this.pressionLocale = p; }

    // public, car les observateurs peuvent rendre compte de leur 
    public String getDateHeureLocale ()  { return (this.dateHeureLocale); }
    public double getTemperatureLocale () { return (this.temperatureLocale); }
    public double getPressionLocale ()    { return (this.pressionLocale); }

// METHODES USUELLES toString
    public String toString() {
        return (getLibelleObservateur() + " : " 
              + "Date et heure (" + getDateHeureLocale() + "), " 
              + "Temperature °C (" + getTemperatureLocale() + "), " 
              + "Pression hPa (" + getPressionLocale() +")");
    }
    
// METHODES SPECIFIQUES réagir
    public void reagir() { // Met à jour les valeurs locales
        this.setDateHeureLocale  (this.observable.getDateHeure());
        this.setTemperatureLocale(this.observable.getTemperature());
        this.setPressionLocale   (this.observable.getPression());
        // On peut éventuellement ajouter une réaction/un traitement supplémentaire 
 }

}