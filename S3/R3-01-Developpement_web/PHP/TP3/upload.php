<html>
    L'uplaod a réussi !
</html>

<?php
    foreach($_FILES as $file){
        $tmp_name = $file['tmp_name'];
        $name = $file['name'];
        move_uploaded_file($tmp_name, "img/$name");

    }
?>