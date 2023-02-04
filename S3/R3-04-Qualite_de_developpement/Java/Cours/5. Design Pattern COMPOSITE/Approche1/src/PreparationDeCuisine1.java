/**
 * Abstraite : PreparationDeCuisine1
 * Objectif : Tester l'approche 1 du Patron Composite qui d�finit...
 * ... les m�thodes de la composition d�s la super classe Composant
 * @version 1.0
 * @author Lopist�guy Philippe
 * @date jj/mm/aa
 **/
import java.util.*;

public abstract class PreparationDeCuisine1 {
// CONSTANTES 	-non-

// ATTRIBUTS 	prix, libelle, enfants
	protected int prix=0;
	private String libelle="";
	protected Set<PreparationDeCuisine1> enfants = new HashSet<PreparationDeCuisine1>();

// CONSTRUCTEURS PreparationDeCuisine2, PreparationDeCuisine2(String, int)
public PreparationDeCuisine1 () {
	this.setLibelle("");
	this.setPrix(0);
}
public PreparationDeCuisine1 (String libelle, int prix) {
	this.setLibelle(libelle);
	this.setPrix(prix);
}
// METHODES D'ENCAPSULATION get&set libelle, get&set prix
	public void setLibelle (String libelle) {
		this.libelle = libelle;
	}
	public String getLibelle() {
		return this.libelle;
	}
	public void setPrix (int prix) {
		this.prix = prix;
	}
	public abstract int getPrix();    // D�fini dans les sous classes

// METHODES USUELLES 		toString
	public abstract String toString(String message);// Défini dans les sous classes
	
// METHODES SPECIFIQUES jeSuisCompos�, ajouterPreparationDeCuisine, supprimerPreparationDeCuisine, existePreparationDeCuisine
// Toutes ces m�thodes retournent FALSE par d�faut, et doivent �tre sp�cialis�es dans Pr�parationCompos�e pour �tre effectives.
// Une version abstract pour toutes ces m�thodes, sp�cialis�es dans Pr�parationSimple et Pr�parationCompos�e est une meilleurs approche !
	public boolean jeSuisCompose () {
		return false;
	};
	
	public boolean ajouterPreparationDeCuisine (PreparationDeCuisine1 preparation) {
		return false;
	}
	public boolean supprimerPreparationDeCuisine (PreparationDeCuisine1 preparation) {
		return false;
	}
	public boolean existePreparationDeCuisine (PreparationDeCuisine1 preparation) {
		return false;
	}
}
