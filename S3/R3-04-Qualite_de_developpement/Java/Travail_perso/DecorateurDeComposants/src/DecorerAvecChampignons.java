
public class DecorerAvecChampignons extends DecorateurDePizza{
		// CONSTRUCTEUR
		public DecorerAvecChampignons (IComposant composant) {
			super(composant);
		}
		// METHODE A DECORER AVANT et/ou APRES : opération
		public String toString() {
			String res="# + Champignons #\n";
			res+=composantDécoré.toString();
			res+="# + Champigons #\n";
			return res;
		}
}