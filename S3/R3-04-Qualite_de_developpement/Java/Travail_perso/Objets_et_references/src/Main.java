/**
 * Classe : Main
 * Objectif : Mettre en �vidence les probl�mes li�s � la diff�rence entre l'objet et son adresse
 * 
 * 1. Cr�er un pointeur c'est diff�rent que de cr�er un objet 
 * 2. Cas de l'objet r�f�renc� par deux pointeurs
 * 3. Cr�er un objet � l'identique d'un objet mod�le : constructeur par recopie
 * 
 * 4. Comparer deux pointeurs versus comparer deux objets
 *  4.a Comparer 2 pointeurs
 *  4.b Comparer 2 objets => la m�thode boolean equals(objetModele)
 * 
 * 5. Param�tres des fonctions et m�thodes : seule la valeur de la variable est transmise 
 *  5.a Param�tre "type primitif"
 *  	=> modifications de la variable sans effet au niveau appelant
 *  5.b Param�tre "pointeur"
 *  	=> modification de la r�f�rence sans effet au niveau appelant
 *      => modification de l'objet r�f�renc� avec effet au niveau appelant 
 * @version 2.0
 * @author Lopist�guy Philippe
 * @date jj/mm/aa
 */
public class Main {

/** 1.ATTRIBUTS              -non- **/
/** 2.CONSTRUCTEURS          -non- **/
/** 3.METHODES ENCAPSULATION -non- **/
/** 4.METHODES USUELLES      -non- **/

/** 5.METHODES SPECIFIQUES : modifierLeParametreDeTypePrimitifInt, modifierLeParametreAdresse, modifierObjetPointeParLeParametre **/

	static public void modifierLeParametreDeTypePrimitifInt (int entierRecu) {
		System.out.println ("... je re�ois l'entier "+ entierRecu +" et l'augmente de 1");
		entierRecu++;  // incr�mentation
		System.out.println ("... pour moi il vaut "+ entierRecu +" et la fonction se termine");
	}
	
	static public void modifierLeParametreAdresse (Ingredients ingredient) {
		System.out.println ("... je re�ois l'adresse de l'ingredient "+ingredient.toString());
		Ingredients unNouveau;
		unNouveau = new Ingredients ("vin", 40); // Cr�e unNouveau ingredient
		System.out.println ("... je cr�e un nouvel ingredient "+ unNouveau.toString());
		ingredient = unNouveau;					 
		System.out.println ("... le param�tre re�u pointe sur ce nouvel ingr�dient "+ingredient.toString()+" et la fonction se termine");
	}
	
	static public void modifierObjetPointeParLeParametre (Ingredients ingredient) {
		System.out.println ("... je re�ois l'adresse de l'ingredient "+ingredient.toString());
		ingredient.set_quantite(0);
		System.out.println ("... je modifie la quantit� "+ ingredient.toString()+" et la fonction se termine");
	}

/** 6.METHODE PRINCIPALE: main() **/
	public static void main(String[] args) {
		
		 /* 1. Cr�er un pointeur c'est diff�rent que de cr�er un objet 
		 * - un pointeur est capable de stocker l'adresse d'un objet
		 * - un objet est cr�e par un 'new'
		 * - un 'new' retourne l'adresse de l'objet cr��
		 * => on r�cup�re l'adresse dans un pointeur
		*/
		System.out.println("\n1. Cr�er un pointeur c'est diff�rent que de cr�er un objet");
		Ingredients ingredient10;	// On cr�e le pointeur ingredients10
		ingredient10 = new Ingredients ("lait", 10); // on cr�e l'objet <"lait",10>
		// et le pointeur ingredient10 r�cup�re l'adresse de l'objet <"lait",10>
		System.out.println("ingredient10 contient l'adresse de "+ingredient10.toString());

		/* 2. Cas de l'objet r�f�renc� par deux pointeurs
		 *  a. d�clarer 2 pointeurs
		 *  b. cr�er un objet et garder son @ dans le 1er pointeur
		 *  c. copier cette @ dans le 2�me pointeur
		 *  d. afficher l'objet que pointeur le 1er et le 2�me pointeur
		 *  e. modifier l'objet via le 2eme pointeur & constater la modification
		 *  f. afficher l'objet point� par chacun de ces 2 pointeurs
		 * => les modifications de l'objet via le 1er pointeur ont affect� les valeurs
		 *    de l'objet point� par le 2� pointeur. Normal ! c'est le m�me objet
		 */
		System.out.println("\n2. Cas de l'objet r�f�renc� par deux pointeurs");
		Ingredients ingredient21;	// a. cr�ation d'un 1er pointeur ingredient21
		Ingredients ingredient22;	// a. cr�ation d'un 2eme pointeur ingredient22
		ingredient21 = new Ingredients("sel", 21);	// b. le 1er pointe sur new objet <"sel", 21>
		ingredient22 = ingredient21;	// c. copier l'@ de l'objet dans le 2�me pointeur
		System.out.println("ingredient21 contient l'adresse de "+ingredient21.toString());	// d. affichage via 1er pointeur
		System.out.println("ingredient22 contient l'adresse de "+ingredient22.toString());	// d. affichage via 2�me pointeur
		ingredient21.set_quantite(8);	// e. modifier l'objet via le 1er pointeur
		System.out.println("ingredient21 contient l'adresse de "+ingredient21.toString());	// f. affichage via 1er pointeur
		System.out.println("ingredient22 contient l'adresse de "+ingredient22.toString());//    et 2�me pointeur
		
		 /* 3. Cr�er un objet � l'identique d'un objet mod�le : constructeur par recopie
		 *   a. �crire un constructeur avec un objet modele en param�tre (cf. classe Ingredients)
		 *   b. cr�er un 1er objet r�f�renc� par un 1er pointeur
		 *   c. cr�er un 2eme objet (sur la base du 1er objet) r�f�renc� par un 2�me pointeur
		 *   d. constater que les 2 pointeurs se r�f�rent � des objets de m�me valeur
		 *   e. modifier le premier objet
		 *   f. constater que chaque poitneur se r�f�re � des objets de valeurs diff�rentes
		 * => Constructeur par recopie
		 */
		
		System.out.println("\n3. Cr�er un objet � l'identique d'un objet mod�le : constructeur par recopie");
		// a. est d�j� fait : soyez tranquilles...
		Ingredients ingredient31;	// b. cr�e le 1er pointeur    ingredient31
		ingredient31 = new Ingredients("milk", 31);	// b. le 1er pointeur prend l'@ d'un ouvel objet <"milk", 31>
		Ingredients ingredient32;	// c. cr�e le 2�me pointeur   ingredient32
		ingredient32 = new Ingredients(ingredient31);	// c. le 2�me pointeur prend l'@ du 2�me objet qui est construit
                                //    sur la base du 1er objet, cad construit par recopie
		System.out.println("ingredient22 contient l'adresse de "+ingredient31.toString());	// d. affichage de ce que pointe    ingredient31
		System.out.println("ingredient22 contient l'adresse de "+ingredient32.toString());	// d. affichage de ce que pointe    ingredient32
		ingredient31.set_quantite(10);	// e. modification de l'un des 2 objets
		System.out.println("ingredient22 contient l'adresse de "+ingredient31.toString());	// f. affichage  de ce que pointe    ingredient31
		System.out.println("ingredient22 contient l'adresse de "+ingredient32.toString());	// f. affichage  de ce que pointe    ingredient32
		
		/* 4. Comparer deux pointeurs versus comparer deux objets
		 *  4.a Commparer 2 pointeurs
		 *      a. cr�er un objet r�f�renc� par un pointeur
		 *      b. copier le pointeur dans un second pointeur
		        c. observer qu'ils sont �gaux (ils r�f�rencent le m�me objet)
		 *  4.b Comparer 2 objets
		 *      a. cr�er et initialiser un premier objet r�f�renc� par un 1er pointeur
		 *      b. cr�er et initialiser (aux m�me valeurs) un second objet r�f�renc� par un 2�me pointeur
		 *      c. comparer les pointeurs et constater qu'ils sont diff�rents alors que les 2 objets r�f�renc�s sont identiques
		 * 	d. (c'est d�j� fait) surcharger la m�thode "static public boolean equals(objetModele)" (cf. classe Ingredients) de sorte
		 *         � ce que l'objet consid�r� compare ses attributs � ceux de l'objet mod�le et retourne vrai en cas d'�galit�S
		 */
		
		System.out.println("\n4. Comparer deux pointeurs versus comparer deux objets");
		System.out.println("   4.a Comparer deux pointeurs : pointeurs �gaux"); 
		Ingredients ingredient41 = new Ingredients("salt", 41);	// a. cr�er un objet <"salt", 41> point� par ingredient41
		Ingredients ingredient42 = ingredient41; // b. copier le pointeur dans un second pointeur ingredient42
		System.out.println(ingredient41 == ingredient42);	// c. observer que ingredient41 et ingredien42 sont �gaux

		System.out.println("\n   4.b Comparer deux objets => la m�thode boolean equals(objetModele)");
		// xxxx;	// a. cr�er un objet point� par ingredient43 aux valeurs <"vin", 49>
		// xxxx;	// b. cr�er un 2�me objet point� par ingredient44 aux m�mes valeurs <"vin", 49>
		// xxxx;	// c. diff�rence d'adresse des objets, mais m�mes valeurs 
		// xxxx;	// d.valeurs des objets identiqueS : regarder le 'if' (cf. methode equals)
		
		 /* 5. Param�tres des fonctions et m�thodes : c'est la valeur de la variable qui est transmise
		  *   5.a Param�tre "type primitif" => modifications de la variable sans effet au niveau appelant
		  */
		System.out.println("\n5. Param�tres des fonctions et m�thodes : c'est la valeur de la variable qui est transmise");
		System.out.println("     5.a Param�tre type primitif => modifications de la variable sans effet au niveau appelant");
		int unEntier = 20;
		System.out.println ("La valeur de unEntier "+unEntier+" est transmise � la fonction"); // avant  20
		// xxxx;	// appeler :    modifierLeParametreDeTypePrimitifInt (int);
		System.out.println ("La valeur de unEntier "+unEntier+" et est INCHANGE apr�s la fonction"); // apr�s 20 inchang� !!!!
		
		//  5.b Param�tre "pointeur" => modification de la r�f�rence sans effet au niveau appelant
		System.out.println("\n     5.b Param�tre pointeur => modification de la r�f�rence sans effet au niveau appelant");
		Ingredients ingredient00 = new Ingredients ("huile", 10);
		System.out.println ("La valeur de l'ingredient "+ingredient00.toString()+" est transmise � la fonction"); // avant <huile,10>
		// xxxx;	// appeler :   modifierLeParametreAdresse (Ingredients);
		System.out.println ("La valeur de l'ingredient "+ingredient00.toString()+" apr�s la fonction INCHANGE"); // apr�s <huile,10> inchang� !!!!
		
		//  5.c Param�tre "pointeur" => modification de l'objet r�f�renc� avec effet au niveau appelant 
		System.out.println("\n     5.c Param�tre pointeur => modification de l'objet avec effet au niveau appelant");
		Ingredients ingredient11 = new Ingredients ("th�", 11);
		System.out.println ("La valeur de l'objet point� "+ingredient11.toString()+" est transmise � la fonction"); // avant <th�,10>
		// xxxx;	// appeler : 	modifierObjetPointeParLeParametre (Ingredients);
		System.out.println ("La valeur de l'objet point� "+ingredient11.toString()+" apr�s la fonction C H A N G E"); // apr�s <vin,40> inchang� !!!!
	}
}