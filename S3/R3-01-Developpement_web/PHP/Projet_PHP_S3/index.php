<?php
session_start();

include "bd.php";
require 'outils.php';

if (isset ($_GET['selectedAlbum'])) {
    if (!isset($_SESSION['cart'])) {
        $_SESSION['cart'] = [];
    }
    if (isset($_SESSION['cart'][$_GET['selectedAlbum']])) {
        $_SESSION['cart'][$_GET['selectedAlbum']] += 1;
    } else {
        $_SESSION['cart'][$_GET['selectedAlbum']] = 1;
    }
}

$removeSuccess = false;
if (isset($_GET['removeAlbum'])) {
    if(removeAlbumInBD($_GET['removeAlbum'])) {
        $removeSuccess = true;

    }
}

if (isset($_GET['fullAlbum'])) {
    afficherFull(getAlbumData($_GET['fullAlbum']));
}

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="styles/index.css">
    <link rel="stylesheet" href="styles/all.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200" />
    <title>Accueil</title>
</head>
<body>
    <div>
        <?php include "alert.js" ?>
    </div>
    <header>
        <?php
        include "header.php";
        if ($removeSuccess) {
            echo "<script>alertMessage('L\'album a bien été supprimé','success')</script>";
        }

        if (isset ($_GET['selectedAlbum'])) {
            echo "<script>alertMessage('Album \"".getAlbumData($_GET['selectedAlbum'])['Titre']."\" ajouté au panier','success')</script>";
        }
        ?>
    </header>
    <main>

        <article style="margin: 20px;">
            <h1>Liste des albums disponibles sur notre site</h1>
            <form action="index.php" method="post" class="flex-container">
            <?php
            foreach (getAlbumsId() as $album) {

                afficherAlbum(getAlbumData($album));
            }
            ?>
            </form>
        </article>
    </main>
    <footer>
        <?php
        include "footer.php";
        ?>
    </footer>
</body>
</html>