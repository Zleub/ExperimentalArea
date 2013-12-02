<?php

function regex_account($to_check)
{
	$regex = '#^[a-zA-Z0-9éèàêâôùïüë.\ _-]{1,30}$#';
	$bool = preg_match($regex, $to_check);
	if($bool == FALSE)
	{
		$error = 'Le nom de compte doit être uniquement composé de lettres et de chiffres. Longueur max 30 caract.';
		return $error;
	}
}

function regex_password($to_check)
{
	$regex = '#^[a-zA-Z0-9éèàêâôùïüë._-]{1,40}$#';
	$bool = preg_match($regex, $to_check);
	if($bool == FALSE)
	{
		$error = 'Le mot de passe doit être uniquement composé de lettres et de chiffres. Longueur max 40 caract.';
		return $error;
	}
}

function regex_mail($to_check)
{
	$regex = '#^[a-zA-Z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$#';
	$bool = preg_match($regex, $to_check);
	if($bool == FALSE)
	{
		$error = "L'adresse mail doit être au format email@boite.com . Longueur max 40 caract.";
		return $error;
	}
}

function regex_title($to_check)
{
	$regex = '#^[a-zA-Z0-9éèàêâôùïüë.\ @_-]{1,30}$#';
	$bool = preg_match($regex, $to_check);
	if($bool == FALSE)
	{
		$error = "Le titre doit faire au max 30 caract.";
		return $error;
	}
}

function regex_chatbox($to_check)
{
	$regex = "#^[a-zA-Z0-9éèàêâôùïüëç.;:,\/ '&*%?![\]()@_^-]+$#";
	$bool = preg_match($regex, $to_check);
	if($bool == FALSE)
	{
		$error = "L'un des caractères que vous essayez d'utiliser n'est pas reconnu.";
		return $error;
	}
}
?>

<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
</head>
<body>

Faire un test chatbox : 
<form class="message" method="post" action="security.php">
	<input class="message" maxlength="170" placeholder="Play Here !" name="text">
	<input class="send" type="submit" value="Send">
</form>
<?php 
if(isset($_POST['text']))
{
	$argument = $_POST['text'];
	$error = regex_chatbox($argument);

	echo "<br> |$argument| <br>";
	if(isset($error))
	echo $error;
	echo "<br>";
}
?>
</body>
</html>