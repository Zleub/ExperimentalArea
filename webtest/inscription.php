<?php

//print_r($GLOBALS);

include('./mysql.php');

if (isset($_POST['referent']) && isset($_POST['account']))
{
	$referent = $_POST['referent'];
	$co = mysql_co();
		
	$query = 'SELECT account FROM Users WHERE account = "'.$_POST['account'].'"';
	$result = mysqli_query($co,$query);
	while($row = mysqli_fetch_array($result))
	{
		$array_user['account'] = $row['account'];
	}
	mysqli_close($co);
	
	if($array_user['account'] == NULL)
	{
		$co = mysql_co();
		$query = 'SELECT account FROM Users WHERE account = "'.$referent.'"';
		$result = mysqli_query($co,$query);
		while($row = mysqli_fetch_array($result))
		{
			$array_user['account'] = $row['account'];
		} 
		mysqli_close($co);
		if($array_user['account'] == NULL)
		{
			header('Location: inscription.php');
		}
		else
		{
			if(sha1($_POST['password']) == sha1($_POST['password_verif']))
			{
				$co = mysql_co();
				$query = "INSERT INTO Users VALUES ('".$_POST['account']."', '".sha1($_POST['password'])."', '".$_POST['mail']."', 'New one', NULL, NULL, NULL)";
				$result = mysqli_query($co,$query);
				$valid = "Inscription validée !";
				mysqli_close($co);
				header('Location: connexion.php');
			}
			else
			{
				$error = "Les deux mots de passes ne sont pas identiques !";
			}
		}
	}
	else
	{
		$error = "Le nom de compte existe déjà !";
	}
}
else 
{
	$error = "Le referent est le nom de compte d'un joueur déjà enregistré";
}

?>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
<link rel="stylesheet" type="text/css" href="./styles.css">
</head>

<body>

<div class = "global">
<div class = "connexion">
<h1>Inscription</h1>

<form action="inscription.php" method="post">
Account: <input type="text" name="account"><br>
Password: <input type="password" name="password"><br>
Verify Password: <input type="password" name="password_verif"><br>
Mail : <input type="text" name="mail"><br>
Referent : <input type="text" name="referent"><br>
<input type="submit" value="Send" placeholder="Send !">
</form>
<?php if(isset($error)){echo '<br> '.$error.' <br>';} 
		echo $valid; ?>
</div>
</div>

</body>
</html>