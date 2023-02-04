/**
 * Classe : Table
 * Objectif : Tester une relation BIdirectionnelle 1x1 entre Table et Client
 * @version 1.0
 * @author: Lopisteguy
 * @date : jj/mm/aaaa
 */
public class Table {
///ATTRIBUT
	private String numeroTable="";
	private Client monClient = null;
/// CONSTRUCTEUR
	public Table(String numero) {
		this.setNumeroTable (numero);
	}
/// ENCAPSULATION numeroTable, monClient
	public void setNumeroTable (String numero) {
		this.numeroTable = numero;
	}
	public String getNumeroTable () {
		return this.numeroTable;
	}
	public void setMonClient(Client client) {
		this.monClient = client;
	}
	public Client getMonClient() {
		return this.monClient;
	}
/// METHODES USUELLES toString
	public String toString() {
		String resultat;
		resultat = "("+getNumeroTable()+")";
		if (this.getMonClient() != null) {
			 resultat += " <=> ("+this.getMonClient().getNom();
			 resultat += " - "+this.getMonClient().getTelephone()+")";
		}
		return resultat;
	}
/// METHODES SPECIFIQUES delierMonClient, lierMonClient(Client)
	public void delierMonClient () {          // Délier la relation AVEC réciprocité
	    if (this.monClient != null) {         // Si je suis lié, alors,
	        this.monClient.setMaTable (null); // - il ne doit plus pointer vers moi,
	        this.monClient = null;            // - je ne dois plus pointer vers lui.
	    }
	}
	public void lierMonClient(Client client) { // Lier la relation AVEC réciprocité
	    if (client != null) {         // Si mon futur correspondant existe, alors
	        this.delierMonClient();   // - me délier de mon correspondant actuel,
	        client.delierMaTable ();  // - délier mon futur correspondant,
	        this.setMonClient(client);// - pointer vers lui,
	        client.setMaTable(this);  // - le faire pointer vers moi.
	    }
	}
}