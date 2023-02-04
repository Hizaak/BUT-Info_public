<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $file = fopen("restos.csv", "r");
        if($file){
            while(($line = fgetcsv($file, 0, ";"))){
                print "Nom : ".$line[0]."<br>";
                print "Prénom : ".$line[1]."<br>";
                print "Restaurant : ".$line[2]."<br><hr>";
            }
        }

    ?>
</body>
</html>