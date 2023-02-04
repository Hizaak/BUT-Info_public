<?php
session_start();

include "bd.php";

$success = false;

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- rel -->
    <link rel="stylesheet" href="styles/all.css">
    <link rel="stylesheet" href="styles/connexion.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200" />
    <title>Page admin</title>
</head>
<body>
<main>
    <div>
        <?php
            include 'alert.js';

            if (isset($_POST['code']) && isset($_POST['date'])) {
                $dateDiff = date_diff(date_create(date('y-m-d')),date_create($_POST['date']))->format("%D");
                if (strlen($_POST['code']) == 16 && substr($_POST['code'], -1) == substr($_POST['code'], 0,1) && $dateDiff > 3) {
                    echo "<script>
                            alertMessage('félicitations ! Vous devriez recevoir votre commande dans quelques jours','success'); 
                            </script>";
                    $success = true;

                } else if (strlen($_POST['code']) != 16) {
                    echo "<script>alertMessage('Un code de 16 chiffres est attendu','error')</script>";
                } else if (substr($_POST['code'], -1) != substr($_POST['code'], 0,1)) {
                    echo "<script>alertMessage('Le premier ou le dernier chiffre du code est invalide','error')</script>";
                } else {
                    echo "<script>alertMessage('Votre carte expire dans moins de 3 jours','error')</script>";
                }
            }
        ?>
    </div>
    <?php

    if (!$success) {
        echo
        '
        <form action="buy.php" method="post">
            <h2>Paiement et livraison</h2>
            <div><label for="code">Code</label><br>
                <input required type="text" name="code" id="code">
                <ul>
                    <li>
                        <p>16 chiffres</p>
                    </li>
                    <li>
                        <p>premier et dernier identique</p>
                    </li>
                </ul></div>
    
            <div><label for="date">Date d\'expiration</label><br>
                <input required type="date" name="date" id="date"></div>
            <input class="fit-width important-input" type="submit" value="Payer">
            <div>
                <a href="cart.php">Retour</a>
            </div>
        </form>';
    } else {
        echo "
        <form>
        <h2>Félicitation</h2>
        <p>
           Vous devriez recevoir votre commande sous 10 jours.
        </p>
        <button class='important-input'><a href='index.php'>Retour à l'accueil</a></button>
        </form>";
    }

    ?>
    <footer>
        <?php
        include "footer.php";
        ?>
    </footer>
</main>
</body>
</html>

