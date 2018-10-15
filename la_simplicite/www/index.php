<?php
include "auth.php";
?>
<html>
    <head>
        <title>Un site simple</title></title>
    </head>
    <body>
        <center><iframe width="560" height="315" src="https://www.youtube.com/embed/2bjk26RwjyU?rel=0&amp;controls=0&amp;showinfo=0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe></center>
<?php
	if(isset($_POST["h1"]))
	{
		$h1 = md5($_POST["h1"] . "Shrewk");
		echo "h1 vaut: ".$h1."</br>";
		if($h1 == "0")
		{
				echo "<!--Bien joué le flag est ".$flag."-->";
		}
	}
?>
<!-- Si une méthode ne fonctionne pas il faut en utiliser une autre -->
<!-- Un formulaire c'était pas assez simple donc on en a pas mis -->
</body>
</html>
