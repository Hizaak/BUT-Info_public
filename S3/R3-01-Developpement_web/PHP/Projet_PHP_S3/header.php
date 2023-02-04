<?php

if (isset($_SESSION['status'])) {


    ?>
        <div>
            <?php
            if ($_SESSION['status'] == "admin") {
            echo "
                <button class='important-input w-fit'>
                <a href='./admin.php'>Ajouter un album</a></button>
                <button class='important-input w-fit'>
                <a href='./index.php'>Voir les albums</a></button>";
            } else if ($_SESSION['status'] == "user") {
                echo "
                <button class='important-input w-fit'>
                <a href='./cart.php'>Voir la panier</a></button>
                <button class='important-input w-fit'>
                <a href='./index.php'>Voir les albums</a></button>";
            }
            ?>
        </div>
    <div id='right-div'>
    <?php
    if ($_SESSION['status'] == "user" || $_SESSION['status'] == "admin") {
        echo "<p class='f-right'> Connecté en " . $_SESSION["connectedAs"] . " (" . $_SESSION["status"] . ") </p>
                <button class='soft-input f-right w-fit'>
                <a href='./logout.php'>Se deconnecter</a>
                </button>";
    } else {
        echo "<button class='important-input f-right w-fit'>
                <a href='./connexionUser.php'>Connexion</a>
                </button>";
    }
    ?>

<?php




} else {
    echo "
            <div></div>
            <div>
            <button class='f-right important-input w-fit'>
<a href='./connexionUser.php'>Connexion</a></button></div>";
}



?>