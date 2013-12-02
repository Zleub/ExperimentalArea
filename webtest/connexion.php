<?php

if (isset($_POST["account"])) 
{
	$user = $_POST["account"];
	$password = $_POST["password"];
	$co = mysqli_connect("localhost","root","asdzefasxzdc123","Area");
	if (mysqli_connect_errno($co))
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}
	$query = 'SELECT * FROM Users WHERE account = "'.$user.'"';
	$result = mysqli_query($co,$query);
	while($row = mysqli_fetch_array($result))
	{
		$array_user['account'] = $row['account'];
		$array_user['password'] = $row['password'];
		$array_user['title'] = $row['title'];
		$array_user['gameid'] = $row['gameid'];
		$array_user['roomid'] = $row['roomid'];	} 
	mysqli_close($co);
	if(sha1($password) == $array_user['password'])
	{
		setcookie ( "key_0", $array_user['account']);
		setcookie ( "key_1", sha1($array_user['password']));
		header('Location: game.php');
	}
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
<h1>Connexion</h1>

</form>
<form action="inscription.php" method="post">
<input type="submit" name="onjump" value="Inscription">
</form>
<br>
<form>
Account: <input type="text" name="account"><br>
Password: <input type="password" name="password"><br>
<input type="submit" formaction="connexion.php" formmethod="post" value="Send" placeholder="Send !">

</div>
</div>

</body>
</html>