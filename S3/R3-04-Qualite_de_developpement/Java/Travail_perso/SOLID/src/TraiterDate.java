
public class TraiterDate {
    private Date maDate;

    public TraiterDate(Date maDate) {
        this.maDate = maDate;
    }

    public int toInt() {
        return maDate.getAnnee() * 10000 + maDate.getMois() * 100 + maDate.getJour();
    }
}
