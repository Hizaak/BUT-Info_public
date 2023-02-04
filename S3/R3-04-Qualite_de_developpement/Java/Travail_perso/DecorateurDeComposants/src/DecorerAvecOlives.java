
public class DecorerAvecOlives extends DecorateurDePizza {
		// CONSTRUCTEUR
		public DecorerAvecOlives (IComposant composant) {
			super(composant);
		}
		// METHODE A DECORER AVANT et/ou APRES : opération
		public String toString() {
			String res="# + Olives #\n";
			res+=composantDécoré.toString();
			res+="# + Olives #\n";
			return res;
		}
}
