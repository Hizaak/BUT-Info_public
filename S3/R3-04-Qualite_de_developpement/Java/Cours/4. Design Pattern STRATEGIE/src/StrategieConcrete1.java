/**
 * Classe : StrategieConcrete1
 * Objectif : Tester le patron de conception Strategie
 * Ici, une opérationMétier s'exécute différement selon la stratégie du moment
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public class StrategieConcrete1 implements IStrategie {
	// CONSTANTES 				-non-
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-

	// METHODE SPECIFIQUE methodeDeStrategie
	public void methodeDeStrategie() {
    	System.out.println ("(méthode de Stratégie Concrète 1 qui s'exécute)");
    }
}
