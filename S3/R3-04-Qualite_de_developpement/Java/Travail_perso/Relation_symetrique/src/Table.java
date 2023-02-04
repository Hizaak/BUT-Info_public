
public class Table {
    // Données membres
    private String _numeroTable;
    private Client _client;

    // Constructeurs
    public Table(String numero, Client client) {
        this._numeroTable = numero;
        this._client = client;
    }

    public Table(String table) {
        this._numeroTable = table;
    }

    //Accesseurs
    //Setter
    public Client GetClient(){
        return _client;
    }

    public String GetNumeroTable(){
        return _numeroTable;
    }
    // Getter

    public String getNumeroTable() {
        return _numeroTable;
    }
    public Client getClient() {
        return _client;
    }

    public void delier() {
        this._client = null;
    }

    public void lierA(Client client){
        // On doit d'abord délier la table de son client actuel
        if (this._client != null) {
            this._client.delier();
        }
        this._client = client;
        client.lierA(this);
    }

    // Méthodes usuelles
    public String toString() {
        return "Table numéro : " + this._numeroTable + " - " + " Client : " + this._client;
    }
}
