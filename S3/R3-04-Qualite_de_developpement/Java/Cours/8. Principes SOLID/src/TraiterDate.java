/**
 * Objectif : comment d�porter une m�thode dans une autre classe
 * Classe : TraiterDate - prend en charge la m�thode toInt
 * @author: Lopisteguy
 * @date : x/x/x
 */
public class TraiterDate {
 // ATTRIBUTS maDate
	public DateSansToInt maDate = null; // objet sur lequel faire porter les m�thodes

 // CONSTRUCTEUR TraiterDate (DateSansToInt )
	public TraiterDate (DateSansToInt d) {
		maDate = d; //
	}

 // METHODE USUELLE - non
	
 // METHODE SPECIFIQUE toInt() d�port�e ici
    public int toInt () {
	        return (maDate.get_annee()*10000 + maDate.get_mois()*100 + maDate.get_jour());
	}	    
}
