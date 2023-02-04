<?php
session_start();

require "bd.php";
include "outils.php";

if(!isset($_SESSION["cart"])) {
    $_SESSION["cart"] = [];
}

if (isset ($_GET['selectedAlbum'])) {
    unset($_SESSION["cart"][$_GET['selectedAlbum']]);
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
    <!-- rel -->
    <link rel="stylesheet" href="styles/index.css">
    <link rel="stylesheet" href="styles/all.css">

    <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200" />
    <title>Page admin</title>
</head>
<body>
<div>
    <?php
    include "alert.js";

    if (isset ($_GET['selectedAlbum'])) {
        echo "<script>alertMessage('Album \"".getAlbumData($_GET['selectedAlbum'])['Titre']."\" retiré du panier','success')</script>";
    }
    ?>
</div>
<header>
    <?php
    include "header.php";

    ?>
</header>
<main>
    <article style="margin: 20px;">
        <h1>Votre panier</h1>
        <p>Prix total : <?php $sum = 0; foreach ($_SESSION['cart'] as $album) {$sum += getAlbumData($album)['Prix'];} echo $sum;?>€</p>
        <button class="important-input" style="margin: 20px;"><a href="buy.php">Passer au paiement</a></button>
        <form action="cart.php" method="post" class="flex-container">
            <?php
            foreach ( array_keys($_SESSION['cart']) as $album) {
                afficherAlbumInCart(getAlbumData($album));
            }
            ?>
        </form>
        <?php if (count($_SESSION['cart']) == 0) {echo "<p>Votre panier est vide, <button class='soft-input'><a href='index.php'>poursuivre vos achats</a></button></p>";}?>
    </article>
</main>

<footer>
    <?php
    include "footer.php";
    ?>
</footer>
</body>
</html>