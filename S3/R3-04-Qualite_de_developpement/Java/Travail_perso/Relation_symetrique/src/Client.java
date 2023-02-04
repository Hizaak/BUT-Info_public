
public class Client {
    // Données membres
    private String _nom;
    private String _telephone;
    private Table _table;

    // Constructeurs
    Client(String nom, String telephone) {
        this._nom = nom;
        this._telephone = telephone;
    }

    Client(Client client) {
        this._nom = client.GetNom();
        this._telephone = client.GetTelephone();
    }

    // Accesseurs
    // Setter
    public void setNom(String nom) {
        this._nom = nom;
    }

    public void setTelephone(String telephone) {
        this._telephone = telephone;
    }
    // Getter
    public String GetNom() {
        return this._nom;
    }

    public String GetTelephone() {
        return this._telephone;
    }

    public Table getTable() {
        return _table;
    }

    public void delier() {
        this._table = null;
    }
    
    public void lierA(Table table){
        // On doit d'abord délier le client de sa table actuelle
        if (this._table != null) {
            this._table.delier();
        }
        _table = table;
        table.lierA(this);
    }

    // Méthodes usuelles
    public String toString() {  
        return "Titulaire : " + this._nom + " - " + " Numéro de téléphone : " + this._telephone + " - " + " Table : " + this._table;
    }
}
