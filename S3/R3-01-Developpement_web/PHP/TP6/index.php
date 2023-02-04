<?php
$xml = simplexml_load_file('pays.xml');
foreach($xml as $continent) {
    print_r("L'".$continent->getName()." contient :"."<br>");
    foreach ($continent->pays as $pays){
        print_r($pays. '<br />');
    }
    print("<hr>");
}


?>
