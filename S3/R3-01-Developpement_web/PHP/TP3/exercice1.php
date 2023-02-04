<?php
    if (!empty($_POST)) {
        // Récupérer la valeur de nbPhotos
        $nbPhotos = $_POST['nbPhotos']; 
        print '<FORM ENCTYPE="multipart/form-data" ACTION="upload.php" METHOD="POST" style="display:flex ; flex-direction:column">
               <input type=hidden name=nbphotos value='.$nbPhotos.'>';
        for ($i = 0; $i < $nbPhotos; $i++) {
            print '<input type="file" name="photo' . $i . '">';
        }

        print '<input type=submit value="Télécharger Photos">
               </FORM>';

    }

?>

