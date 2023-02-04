
<?php
header("Content-type: image/jpeg") ;
$image = ImageCreate(400,400) ;
$blanc = ImageColorAllocate($image,255,255,255) ;

imageFill($image,0,0,$blanc) ;

imageJPEG($image) ;

echo "<img src='$image'/>" ;
ImageDestroy($image) ;


$bdd = "roose";
$host = "lakartxela.iutbayonne.univ-pau.fr";
$user = "roose";
$pass = "roose";

$nomtable = "bourse";
//On établit la connexion
print "Connexion au serveur $host en tant que $user...<br>";


$link = mysqli_connect($host, $user, $pass, $bdd) or die("Impossible de se connecter");

print "Connexion établie.<br>";


$query = "SELECT * FROM $nomtable";
$result = mysqli_query($link, $query) or die("Impossible d'exécuter la requête $query");

if (mysqli_connect_errno()) {
    echo "Échec de la connexion : " . mysqli_connect_error();
    exit();
}

while ($donnees=mysqli_fetch_assoc($result)) {
    $ch1=$donnees['ville'];
    $ch2=$donnees['indice'];
    print "$ch1 $ch2 <br>";
}


mysqli_close($link);

?>