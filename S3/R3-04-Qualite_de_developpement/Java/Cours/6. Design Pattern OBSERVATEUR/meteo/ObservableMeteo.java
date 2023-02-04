/**
 * Class : ObservableMeteo
 * Objectif : Montrer un cas pratique d'observation.
 * Deux objets observateurs afficheur et baseDeDonnees sont notifiés
 * quand les valeurs dateHeure, temperature et pression de l'objet sondeMeteo
 * changent de valeur
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public class ObservableMeteo extends Observable {
// ATTRIBUTS
	private String libelle;
    /** Dés que les mesures changent il faut notifier les observateurs **/
	private String dateHeure = "";
    private double temperature = 0.0;
    private double pression = 0.0;
    
// CONSTRUCTEUR
    public ObservableMeteo (String l) {
    	super();
    	this.setLibelle(l);
    	this.setDateHeureTemperaturePression("", 0, 0);
    }

// ENCAPSULATION libelle, dateHeure, temperature, pression
    public void setLibelle (String l) {
    	libelle = l;
    }
    public String getLibelle () {
    	return (libelle);
    }
    public void setDateHeureTemperaturePression(String dH, double d, double e) {
     	this.dateHeure = dH;
    	this.temperature = d;
    	this.pression = e;
        /** Dés que les mesures changent il faut notifier les observateurs **/
        this.notifierObservateurs(); /** Méthode définie dans la super-classe **/
    }
    public String getDateHeure()    { return this.dateHeure; }
    public double getTemperature () { return this.temperature; }
    public double getPression ()    { return this.pression; }
    
// METHODES USUELLES : toString
    public String toString() {
    	String resultat;
    	resultat = getLibelle()+" : Date et heure ("+ getDateHeure()
    	         + "), Temperature °C (" + getTemperature()
    	         + "), Pression hPa (" + getPression()+")";
    	return resultat;
    }
}
