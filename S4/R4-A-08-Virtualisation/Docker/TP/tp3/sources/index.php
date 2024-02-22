<?php
// Configuration de la base de données
$host = "localhost";
$user = "myuser";
$password = "mypassword";
$dbname = "mydatabase";

// Connexion à la base de données
$conn = mysqli_connect($host, $user, $password, $dbname);

// Vérification de la connexion
if (!$conn) {
    die("Erreur de connexion : " . mysqli_connect_error());
}

// Affichage d'un message de confirmation si la connexion est réussie
echo "Sa marche !!!";

// Fermeture de la connexion
mysqli_close($conn);
?>
