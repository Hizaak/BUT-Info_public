<?php
    // Tentative de connexion à la base de données lakartxela (uniquement depuis les ordi de l'iut)
    $_SESSION["database_connection"] = false;
    $database = "";

initDB();

    function initDB()
    {
        global $database;

        //connexion à la base
        $db_servername = "lakartxela";
        $db_username = "gtritsch_bd";
        $db_password = "gtritsch_bd";
        $db_name = "gtritsch_bd";

        try {
            $database = new PDO('mysql:host=' . $db_servername . ';dbname=' . $db_name . ';charset=utf8', '' . $db_username . '', '' . $db_password . '');
            $_SESSION["database_connection"] = true;
        } catch (PDOException $e) {
            $_SESSION["database_connection"] = false;
        }
    }

    function removeAlbumInBD($id) {
        if ($_SESSION["database_connection"]) {
            // base de données

            global $database;

            $db = $database->prepare("DELETE FROM album WHERE id = ".$id);
            $db->execute();
            return true;
        }
        return false;
    }

    // A utiliser pour toutes les valeurs envoyer vers la base de données
    function dataCorrection ($data){
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }

    function getAlbumsId () {
        if ($_SESSION["database_connection"]) {
            // utilisation de la base de données

            global $database;

            $db = $database->prepare("SELECT Identifiant FROM album_details");
            $db->execute();
            $data = $db->fetchAll(PDO::FETCH_COLUMN);
        } else {
            // utilisation de données de test

            $data = [];
            for ($i = 1; $i <= 10; $i++) {
                array_push($data,$i);
            }
        }

        return $data;
    }

    function getGenreId () {
        if ($_SESSION["database_connection"]) {
            // utilisation de la base de données

            global $database;

            $db = $database->prepare("SELECT id FROM genre");
            $db->execute();
            $data = $db->fetchAll(PDO::FETCH_COLUMN);

            return $data;
        }

    }

    function getGenreData($id)  {
        if ($_SESSION["database_connection"]) {
            global $database;

            $db = $database->prepare("SELECT * FROM genre WHERE id='".$id."'");
            $db->execute();
            $info = $db->fetch(PDO::FETCH_ASSOC);

            return $info;
        }
    }

function getArtisteId () {
        if ($_SESSION["database_connection"]) {
            // utilisation de la base de données

            global $database;

            $db = $database->prepare("SELECT id FROM artiste");
            $db->execute();
            $data = $db->fetchAll(PDO::FETCH_COLUMN);

            return $data;
        }
    }

    function getArtisteData($id)  {
        if ($_SESSION["database_connection"]) {
            global $database;

            $db = $database->prepare("SELECT * FROM artiste WHERE id='".$id."'");
            $db->execute();
            $info = $db->fetch(PDO::FETCH_ASSOC);

            return $info;
        }
    }

    function verifUserConnection ($pseudo, $pwd) {
        if ($_SESSION["database_connection"]) {
            // utilisation de la base de données

            global $database;

            $db = $database->prepare("SELECT pwd FROM utilisateur WHERE name='" . $pseudo . "'");
            $db->execute();
            $data = $db->fetch(PDO::FETCH_ASSOC);
            if ($data) {
                if (sizeof($data) != 0) {
                    if (password_verify($pwd, $data["pwd"])) {
                        return true;
                    }
                }
            }

        } else {
            // utilisation de données de test

            if ($pseudo == "user" && $pwd == "user") {
                return true;
            }
        }

        return false;
    }

    function verifAdminConnection ($pseudo, $pwd) {
        if ($_SESSION["database_connection"]) {
            // utilisation de la base de données

            global $database;

            $db = $database->prepare("SELECT psw FROM adminUtilisateur WHERE pseudo='" . $pseudo . "'");
            $db->execute();
            $data = $db->fetch(PDO::FETCH_ASSOC);
            if ($data) {
                if (sizeof($data) != 0) {
                    if (password_verify($pwd, $data["psw"])) {
                        return true;
                    }
                }
            }


        } else {
            // utilisation de données de test

            if ($pseudo == "admin" && $pwd == "admin") {
                return true;
            }
        }

        return false;

    }

function getDBStatus() {
    if (!$_SESSION["database_connection"]) {
        echo "<section class='error'>
                <span class='material-symbols-outlined'>
                error
                </span>
                <p>Connexion à la base de données échouées, vous évoluez dans un environnement de test</p>
            </section>";
    } else {
        echo "<section class='information'>
                <span class='material-symbols-outlined'>
                error
                </span>
                <p>Connexion à la base de données réussie</p>
            </section>";
    }

}

function appendToDB($image, $titre, $genreId, $artisteId, $prix) {
        global $database;



        var_dump($image);

        require "outils.php";

        $db = $database->prepare("SELECT max(id) as maxid FROM album");
        $db->execute();
        $idMax = $db->fetch(PDO::FETCH_ASSOC);
        $idMax = $idMax['maxid'] +1;

        // Miniaturiser l'image
        $path = genererMiniature($image['tmp_name'], $idMax);


        // Album


        $sql = "INSERT INTO album VALUES ('".$idMax."', '".$titre."', '".$genreId."', '".$artisteId."', '".$prix."', NULL, './sources/images/".$idMax.".png','./sources/miniatures/".$idMax.".png')";
        echo $sql;
        $db = $database->prepare($sql);

        $db->execute();

        echo "<script>alertMessage('L\'album a bien été rajouté','success')</script>";
}

function getAlbumData($albumId) {
    if ($_SESSION["database_connection"]) {
        global $database;

        $db = $database->prepare("SELECT * FROM album_details WHERE Identifiant='".$albumId."'");
        $db->execute();
        $info = $db->fetch(PDO::FETCH_ASSOC);
    } else {
        $info = array(
            "Identifiant" => "$albumId",
            "Miniature" => "./sources/miniatures/DaftPunk_RAM_miniature.jpg",
            "Titre" => "Titre ".$albumId,
            "Auteur" => "Auteur ".$albumId,
            "Genre" => "Genre ".$albumId,
            "Prix" => "Prix ".$albumId
        );
    }

    return $info;
}
?>