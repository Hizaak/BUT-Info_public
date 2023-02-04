<?php
session_start();

include "bd.php";

if (isset($_POST['login']) && isset($_POST['password'])) {
    if (verifAdminConnection($_POST['login'],$_POST['password'])) {
        $_SESSION['connectedAs'] = $_POST['login'];
        $_SESSION['status'] = "admin";
        $_POST = array();

        header('Location: admin.php');
    }
}

?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="styles/all.css">
    <link rel="stylesheet" href="styles/connexion.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200" />
    <title>Page admin</title>
</head>
<body>
    <div>
        <?php include "alert.js";

        if (isset($_POST['login']) && isset($_POST['password'])) {
            if (!verifAdminConnection($_POST['login'],$_POST['password'])) {
                echo '<script>alertMessage("L\'identifiant ou le mot de passe est incorrecte",\'error\')</script>';
            }
        }?>
    </div>
    <form action="connexionAdmin.php" method="post">
        <h2>Connexion administrateur</h2>
        <div><label for="login">Login</label><br>
            <input required type="text" name="login" id="login"></div>
        <div><label for="password">Mot de passe</label><br>
            <input required type="password" name="password" id="password"></div>
        <input class="fit-width important-input" type="submit" value="Se connecter">
        <div>
            <a href="connexionUser.php">Retour</a>
        </div>
    </form>
    <footer>
        <?php
        include "footer.php";
        ?>
    </footer>
</body>
</html>