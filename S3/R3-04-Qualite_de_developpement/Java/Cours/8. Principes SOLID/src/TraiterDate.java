/**
 * Objectif : comment déporter une méthode dans une autre classe
 * Classe : TraiterDate - prend en charge la méthode toInt
 * @author: Lopisteguy
 * @date : x/x/x
 */
public class TraiterDate {
 // ATTRIBUTS maDate
	public DateSansToInt maDate = null; // objet sur lequel faire porter les mèthodes

 // CONSTRUCTEUR TraiterDate (DateSansToInt )
	public TraiterDate (DateSansToInt d) {
		maDate = d; //
	}

 // METHODE USUELLE - non
	
 // METHODE SPECIFIQUE toInt() déportée ici
    public int toInt () {
	        return (maDate.get_annee()*10000 + maDate.get_mois()*100 + maDate.get_jour());
	}	    
}
