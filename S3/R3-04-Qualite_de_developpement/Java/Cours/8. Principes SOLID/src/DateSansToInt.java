/**
 * Objectif : comment déporter une méthode dans une autre classe
 * Classe : DateSansToInt
 * @author: Lopisteguy
 * @date : x/x/x
 */
public class DateSansToInt {
 // ATTRIBUTS
	private int _annee = 0;
	private int _mois = 0;
	private int _jour = 0;

 // CONSTRUCTEUR DateSansToInt (int, int, int)
	public DateSansToInt (int a, int m, int j) {
		_annee = a;  _mois = m; _jour = j;
	}
 // ENCAPSULATION _anne, _mois, _jour
	public void set_annee (int a) { _annee = a; }
	public int get_annee ()	{ return _annee; }

	public void set_mois (int m) { _mois = m; }
	public int get_mois ()	{ return _mois; }

	public void set_jour (int j) { _jour = j; }
	public int get_jour ()	{ return _jour; }

 // METHODE USUELLE toString()
	public String toString () {
		String message="";
		message = "jour ("+get_jour()+"), mois ("+get_mois()+"), année ("+get_annee()+")";
		return message;
	}

 // METHODE SPECIFIQUE - non
}