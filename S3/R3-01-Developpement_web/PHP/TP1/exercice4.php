<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        // Code permettant de mettre un compteur de visite
        // On ouvre le fichier compteur.txt
        $fichier = fopen('compteur.txt', 'r+');
        // On lit la première ligne (nombre de pages vues)
        $pages_vues = fgets($fichier);
        // On augmente de 1 ce nombre de pages vues
        $pages_vues += 1;
        // On remet le curseur au début du fichier
        fseek($fichier, 0);
        // On écrit le nouveau nombre de pages vues
        fputs($fichier, $pages_vues);
        // On ferme le fichier
        fclose($fichier);
        // On affiche le nombre de pages vues
        echo '<p>Cette page a été vue ' . $pages_vues . ' fois !</p>';
    ?>
</body>
</html>