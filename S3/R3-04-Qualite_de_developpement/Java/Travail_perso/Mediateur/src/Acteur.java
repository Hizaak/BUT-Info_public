public abstract class Acteur {
    protected Mediateur mediateur;

    public Acteur(Mediateur mediateur) {
        this.mediateur = mediateur;
    }
	
	public Mediateur getMediateur() {
        return this.mediateur;
    }
}
