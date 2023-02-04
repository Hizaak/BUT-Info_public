/**
 * Classe : TesterStrategie
 * Objectif : Tester le patron de conception Strategie
 * Ici, une opérationMétier s'exécute différement selon la stratégie du moment
 * @version 1.0
 * @author: Lopisteguy
 * @date : jj/mm/aaaa
 **/
public class TesterStrategie {
	// ATTRIBUTS 				-non-
	// CONSTRUCTEURS 			-non-
	// METHODES D'ENCAPSULATION -non-
	// METHODES USUELLES 		-non-
	// METHODES SPECIFIQUES 	-non-

	// METHODE PRINCIPALE : main () 
	public static void main(String[] args) {
		// Déclaration d'un objetX capable de réaliser une operationMétier
		ClasseXutilisantStrategie objetX;
		objetX = new ClasseXutilisantStrategie();

		// Déclaration d'une variable capable de pointer vers une Stratégie
		IStrategie uneStrategie;

		// Sélection de la stratégie concrète 1
		uneStrategie = new StrategieConcrete1();
		objetX.setLaStrategie(uneStrategie);
		// Exécution de l'opération métier avec la stratégie1
		objetX.operationMetier();		// Comportement 1

		// Sélection de la stratégie concrète 2
		uneStrategie = new StrategieConcrete2();
		objetX.setLaStrategie(uneStrategie);
		// Exécution de l'opération métier avec la stratégie2
		objetX.operationMetier();		// Comportement 2
		
		/** Affiche 
L'opération métier commence son exécution
(méthode de Stratégie Concrète 1 qui s'exécute)
l'opération métier se termine !

L'opération métier commence son exécution
(méthode de Stratégie Concrète 2 qui s'exécute)
l'opération métier se termine !
		 **/
	}
}