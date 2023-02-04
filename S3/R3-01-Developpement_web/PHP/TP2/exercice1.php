<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="exercice1.php" method="POST">
        <!-- Nom -->
        <label for="nom">Nom :</label>
        <input type="text" name="nom" id="nom" required>
        <!-- Age -->
        <label for="age">Age :</label>
        <input type="number" name="age" id="age" required>
        <!-- Mail -->
        <label for="mail">Mail :</label>
        <input type="email" name="mail" id="mail" required>
        <!-- Valeur du don -->
        <label for="don">Valeur du don :</label>
        <input type="number" name="don" id="don" required>

        <!-- Bouton de validation -->
        <input type="submit" value="Envoyer">
    </form>
</body>
</html>

<?php
    if (!empty($_POST)) {
        $ligne = $_POST['nom'] . " | " . $_POST['age'] . " | " . $_POST['mail'] . " | " . $_POST['don'] . "\n";
        echo $ligne;
        $fichier = fopen('resultats.csv', 'a+');
        fwrite($fichier, $ligne);
        fclose($fichier);
    }
    
    ?>



    mail($_POST['mail'], "Confirmation de don", "Merci" . $_POST['nom'] . "pour votre don de " . $_POST['don'] . "€ !");