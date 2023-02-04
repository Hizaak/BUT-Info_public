/**
 * Classe : ClasseXutilisantStrategie
 * Objectif : Tester le patron de conception IStrategie
 * Ici, une opérationMétier s'exécute différement selon la stratégie du moment
 * @version 1.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 **/
public class ClasseXutilisantStrategie {
    // ATTRIBUTS laStrategie
    private IStrategie laStrategie; // Pointe sur une strategie qui implémente un.des méthodes.s d'intérêt

    // CONSTRUCTEURS 			-non-

    // METHODES D'ENCAPSULATION laStrategie
    public void setLaStrategie (IStrategie s) { this.laStrategie = s; }
    public IStrategie getLaStrategie (IStrategie s) { return this.laStrategie; }

    // METHODES USUELLES 		-non-

    // METHODES SPECIFIQUES 	opérationMetier

    // operationMetier : utilise une.des méthode.s de laStrategie
    public void operationMetier() {
        System.out.println ("L'opération métier commence son exécution");
    	// Invoque la méthode selon la stratégie du moment
        laStrategie.methodeDeStrategie(); 
        System.out.println ("l'opération métier termine son exécution !\n");
    }
}