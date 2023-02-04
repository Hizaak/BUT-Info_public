<?php

function genererMiniature($image, $name) {
    $fileName = "./sources/images/".$name.".png";
    $fileMiniatureName = __DIR__."/sources/miniatures/".$name.".png";

    var_dump(__DIR__);
    echo "<br>",$image,"<br>", $fileName;

    move_uploaded_file($image, $fileName);

    $image = imagecreatefrompng($fileName);
    $image = imagescale($image, 128, 128);

    imagejpeg($image, $fileMiniatureName);
    return [$fileName, $fileMiniatureName];
}

function afficherAlbum($album){
    echo
    '<section class="album">
        <img src="'.$album['Miniature'].'" alt="Pochette de l\'album">
        <a href="index.php?fullAlbum='.$album['Identifiant'].'" ><h2>'.$album['Titre'].'</h2></a>
        <p>'.$album['Auteur'].'</p>';

    echo   '</div>';
        if (isset($_SESSION['status'])) {
            if ($_SESSION["status"] == "user") {
                if (isset($_SESSION['cart'])) {
                    if (isset($_SESSION['cart'][$album['Identifiant']])) {
                        echo '<p>L\'album est déja dans le panier</p>';
                    } else {
                        echo '<button class="soft-input w-full"><a href="index.php?selectedAlbum=' . $album['Identifiant'] . '" >Ajouter au panier</a></button>';
                    }
                }
            } else {
                echo '<button class="soft-input w-full"><a href="index.php?removeAlbum=' . $album['Identifiant'] .'" >Supprimer cette album</a></button>';
            }
        } else {
            echo '<p style="padding: 10px; color: rgba(133,0,0,0.49);">Vous devez être connecté pour ajouter au panier</p>';
        }
        echo '
        </section>';
}

function afficherAlbumInCart($album){
    echo
        '<section class="album">
        <img src="'.$album['Miniature'].'" alt="Pochette de l\'album">

        <a href="cart.php?fullAlbum='.$album['Identifiant'].'" ><h2>'.$album['Titre'].'</h2></a>
        <p>'.$album['Auteur'].'</p>
        <p>'.$album['Genre'].'</p>
        <p id="textNumber"><strong>'.$album['Prix'].'€</strong></p>
        <button class="soft-input w-full"><a href="cart.php?selectedAlbum='.$album['Identifiant'].'" >Retirer du panier</a></button>
        </section>';
}

function afficherFull($album) {
    echo
        '<div class="backdrop">
        <section class="full-details-overlay">
        
        
        <div class="full-grid-layout">
        <img src="'.$album['Image'].'" alt="Pochette de l\'album">
        <section>
        
        <div class="top">
        <h2>'.$album['Titre'].'</h2>
        <p>'.$album['Auteur'].'</p>
        <p>'.$album['Genre'].'</p>
        </div>
        <div class="bottom">
        
        <p><strong>'.$album['Prix'].'€</strong></p>
        ';

    if (isset($_SESSION['status'])) {
        if ($_SESSION["status"] == "user") {
            if (isset($_SESSION['cart'])) {
                if (isset($_SESSION['cart'][$album['Identifiant']])) {
                    echo '<button class="important-input w-full"><a href="cart.php?selectedAlbum=' . $album['Identifiant'] . '&fullAlbum=' . $album['Identifiant'] . '" >Retirer du panier</a></button>';
                } else {
                    echo '<button class="important-input w-full"><a href="index.php?selectedAlbum=' . $album['Identifiant'] . '&fullAlbum=' . $album['Identifiant'] . '" >Ajouter au panier</a></button>';
                }
            } else {
                echo '<button class="important-input w-full"><a href="index.php?selectedAlbum=' . $album['Identifiant'] . '&fullAlbum=' . $album['Identifiant'] . '" >Ajouter au panier</a></button>';
            }

        } else {
            echo '<button class="important-input w-full"><a href="index.php?removeAlbum=' . $album['Identifiant'] .'" >Supprimer cette album</a></button>';
        }
    } else {
        echo '<p style="padding: 10px; color: rgba(133,0,0,0.49);">Vous devez être connecté pour ajouter au panier</p>';
    }


    echo '
        </div>
        </section>
        </div>
        <a class="close-button" href="index.php"><span class="material-symbols-outlined">close</span></a>
        </section></div>';
}

?>