<?php
session_start();

include "bd.php";

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- rel -->
    <link rel="stylesheet" href="styles/admin.css">
    <link rel="stylesheet" href="styles/all.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200" />
    <title>Page admin</title>
</head>
<body>
    <header>
        <?php
        include "header.php"
        ?>
    </header>
    <?php include "alert.js";?>
    <main>
    <?php

    if (isset($_POST['titre'])) {
        appendToDB($_FILES['image'],$_POST['titre'],$_POST['genre'],$_POST['artiste'],$_POST['prix']);
    }

    // vérifier si l'identifiant est correct
    if ($_SESSION['status'] != "admin"){
        header('Location: connexionAdmin.php');
    }
    else{
        echo 
        '<form action="admin.php" method="post" enctype="multipart/form-data">
            <label class="fichier-selection-label" for="image"><a>Uploadez la couverture</a></label>
            <input style="opacity: 0; height:0px;" required type="file" name="image" id="image">
            <input required type="text" name="titre" id="titre" placeholder="Titre de l\'album">
            <select required placeholder="Genre de l\'album" name="genre" id="genre">
            ';
            foreach (getGenreId() as $genreId) {
                $genreData = getGenreData($genreId);
                echo '<option value="'.$genreData['id'].'">'.$genreData['libelle'].'</option>';
            }

        echo '
            </select>
            <select required placeholder="Artiste de l\'album" name="artiste" id="artiste">';

            foreach (getArtisteId() as $artisteId) {
                $artisteData = getArtisteData($artisteId);
                echo '<option value="'.$artisteData['id'].'">'.$artisteData['nom'].'</option>';
            }

        echo '
            </select>
            <input required type="text" name="prix" id="prix" placeholder="Prix de l\'album">
            
            <input class="important-input" type="submit" value="Ajouter l\'album">
        </form>';
    }

    ?>
    </main>
    <footer>
        <?php
        include "footer.php";
        ?>
    </footer>
</body>
</html>

