<?php
$lignes = file('config.ini');
$nomFormulaire = $lignes[1];
$nombreChamps = $lignes[3];
$nomChamps = array($lignes[5], $lignes[6], $lignes[7], $lignes[8]);

$nomFormulaire = rtrim($nomFormulaire);
$nomFormulaire = $nomFormulaire.'.html';
echo $nomFormulaire;
// Création de la page du formulaire
$formulaire = '
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>'.$nomFormulaire.'</title>
</head>
<body>
<form action="'.$nomFormulaire.'" method="post">';
for ($i = 0; $i < $nombreChamps; $i++) {
    $formulaire .= '
    <label for="'.$nomChamps[$i].'">'.$nomChamps[$i].'</label>
    <input type="text" name="'.$nomChamps[$i].'">
    ';
}
$formulaire .= '
    <input type="submit" value="Envoyer">';


$nouveauFichier = fopen($nomFormulaire, 'w');
fwrite($nouveauFichier, $formulaire);


fclose($nouveauFichier);

$traitement = "
<?php
foreach (\$_POST as \$key => \$value) {
    echo \$key.' : '.\$value.'<br>';
}
?>";
?>