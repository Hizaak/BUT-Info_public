import java.util.ArrayList;

public class Personnage {

    private String orientation = "Nord";

    public void tourner(int nbFois) {
        ArrayList<String> listeOrientations = new ArrayList<String>();
        listeOrientations.add("Nord");
        listeOrientations.add("Est");
        listeOrientations.add("Sud");
        listeOrientations.add("Ouest");

        for (int i = 0; i < nbFois; i++) {
            // Si l'orientation est "Nord", on la change en "Est" par exemple
            // Récupérer l'orientation actuelle
            String orientationAcuelle = this.orientation;
            // Récupérer l'index de l'orientation actuelle dans la liste des orientations
            int indexOrientationActuelle = listeOrientations.indexOf(orientationAcuelle);
            // Récupérer l'index de la nouvelle orientation
            int indexNouvelleOrientation = indexOrientationActuelle + 1;
            // Si l'index de la nouvelle orientation est supérieur à la taille de la liste des orientations
            if (indexNouvelleOrientation >= listeOrientations.size()) {
                // On revient au début de la liste
                indexNouvelleOrientation = 0;
            }
            // Récupérer la nouvelle orientation
            String nouvelleOrientation = listeOrientations.get(indexNouvelleOrientation);
            // Changer l'orientation du personnage
            this.orientation = nouvelleOrientation;


        }
    }
}
