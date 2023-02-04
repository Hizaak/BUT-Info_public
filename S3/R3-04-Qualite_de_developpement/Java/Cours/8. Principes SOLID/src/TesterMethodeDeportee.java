/**
 * Objectif : comment déporter une méthode dans une autre classe
 * Classe : Main
 * @author: Lopisteguy
 * @date : x/x/x
 **/
public class TesterMethodeDeportee {
	// ATTRIBUTS - non
	// ENCAPSULATION - non
	// METHODES USUELLES - non
	// METHODES SPECIFIQUES - non

	// METHODE PRINCIPALE
	public static void main(String[] args) {

		// Invoque toInt via un objet d'une classe assumant la méthode
		System.out.println ("Invoque toInt sur un objet d'une classe assumant la méthode");
		DateAvecToInt dateNONsimpleResponsabilite = new DateAvecToInt (2023, 12, 28);
	    System.out.println (dateNONsimpleResponsabilite.toInt());
	    
		// Invoque toInt pour un objet d'une classe n'ayant pas la responsabilité de cette classe 
	    System.out.println ("\nInvoque toInt pour un objet d'une classe n'ayant pas la responsabilité de cette classe");
	    DateSansToInt dateSimpleResponsabilite = new DateSansToInt(2023, 12, 28);
	    TraiterDate traiterUneDate             = new TraiterDate (dateSimpleResponsabilite);
	    System.out.println (traiterUneDate.toInt());
	}
}