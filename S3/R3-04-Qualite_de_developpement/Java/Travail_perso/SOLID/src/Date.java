
public class Date {
    private int annee;
    private int mois;
    private int jour;

    public Date(int annee, int mois, int jour) {
        this.annee = annee;
        this.mois = mois;
        this.jour = jour;
    }

    public int getAnnee() {
        return annee;
    }

    public void setAnnee(int annee) {
        this.annee = annee;
    }

    public int getMois() {
        return mois;
    }

    public void setMois(int mois) {
        this.mois = mois;
    }

    public int getJour() {
        return jour;
    }

    public void setJour(int jour) {
        this.jour = jour;
    }

    public String toString() {
        return "Date{" +
                "annee=" + annee +
                ", mois=" + mois +
                ", jour=" + jour +
                '}';
    }
}
