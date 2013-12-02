<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
<link rel="stylesheet" type="text/css" href="../styles.css">
</head>

<body>

<?php

include('./mysql.php');
include('./class/user.php');
include('./class/game.php');

if (isset($_POST['onjump'])) 
{
	$tmp = $_POST['onjump'];
	$game = new game();
	$game->fill_it_gamename($_POST['onjump']);
	
	$co = mysql_co();
	$pseudo = file("./FakeNameGenerator.com_ec6fa6ab.txt");
	$query = 'SELECT * FROM Users WHERE gameid="'.$game->gameid.'"';
	$result = mysqli_query($co,$query);
	$i = 0;
	while($row = mysqli_fetch_array($result))
	{
		$array_pseudo[$i]['pseudo'] = $row['pseudo'];
		$i = $i + 1;
	}
	$j = $i;
	$pseudoname = $pseudo[rand(1,301)];
	while($j >= 0)
	{
		if(rtrim(str_replace("	", " ", $pseudoname)) != $array_pseudo[$j]['pseudo'])
		{
			$j = $j - 1;
		}
		else
		{
			$pseudoname = $pseudo[rand(1,301)];
			$j = $i;
		}
	}
	$pseudoname = str_replace("	", " ", $pseudoname);
	$pseudoname = rtrim($pseudoname);
	$query = 'UPDATE Users SET gameid="'.$game->gameid.'", roomid="'.$game->startroom.'", pseudo="'.$pseudoname.'", score="0" WHERE account="'.$_COOKIE['key_0'].'"';
	mysqli_query($co,$query);
	mysqli_close($co);
}

if (isset($_POST['new_title']))
{
	$user = new user();
	$user->fill_it($_COOKIE['key_0']);
	$user->update_title($_POST['new_title']);
}

if (isset($_COOKIE['key_0']))
{
	$user = new user();
	$user->fill_it($_COOKIE['key_0']);
	$game = new game();
	$game->fill_it_gameid($user->gameid);
}

//print_r($GLOBALS);

?>

<div class="main">

<div class="header">
<h1>Area</h1>
</div>

<div class="menu">
<h2 class = "game">Informations</h2>

<?php 
echo 'Compte : '.$user->account.'<br>
	Personnage : '.$user->pseudo.'<br> 
	Titre : '.$user->title.'<br>
	Score : '.$user->score.'<br>';
	
?>
<h2 class = "game">Options</h2>
<form action="profil.php" method="post">
<input type="text" name="new_title">
<input type="submit" value="Choisir nouveau titre">
</form>

</div>

<div class="right">

<div class="image">
<div class="img_box">
<p>Bonjour <?php echo $user->account; ?>.</p>

<?php 
if(isset($user->gameid))
{
	echo 'Vous êtes dans la partie N°'.$user->gameid.' - '.$game->gamename.' sous le nom de '.$user->pseudo.' '.$user->title.'';
	echo '<form action="game.php" method="post"><input type="submit" name="play" value="Play"></form>';
}
else
{
  	$co = mysql_co();
	$query = 'SELECT * FROM Games';
	$result = mysqli_query($co,$query);
	$i = 0;
	while($row = mysqli_fetch_array($result))
	{
		$array_game[$i]['gameid'] = $row['gameid'];
		$array_game[$i]['gamename'] = $row['gamename'];
		$i = $i + 1;
	} 
	mysqli_close($co);
	
	echo "Vous n'avez aucune partie en cours. Voici la liste des parties disponibles. <br><br>"; 
	$i = $i - 1;
	while($i >= 0)
	{
		echo '<form action="profil.php" method="post"><input type="submit" name="onjump" value="'.$array_game[$i]['gamename'].'"></form><br>';
		$i = $i - 1;
	}
}
?>

</div>
<br>
</div>


<!--
<div class="chatbox">

<div class="cb_box">

<div class="cb_box_scroll">
<div class="message">Pseudo : message 1</div>
<div class="message">Pseudo : message 2</div>
<div class="message">Pseudo : message 3</div>
<div class="message">Pseudo : message 4</div>
<div class="message">Pseudo : message 5</div>
<div class="message">Pseudo : message 1</div>
<div class="message">Pseudo : message 2</div>
<div class="message">Pseudo : message 3</div>
<div class="message">Pseudo : message 4</div>
<div class="message">Pseudo : message 5</div>
</div>


<button class="refresh" type="button" onclick="NIQUE TA MERE JAVASCRIPT">


<div class="text">
<form class="message" id="message" method="" action="">
	<input class="message" form="message" maxlength="100" placeholder="Play Here !" name="text">
	<input class="send" type="submit" form="message" formaction="game.php" formmethod="post" value="Send" placeholder="Send !">

</form>
</div>

</div>
</div>
-->
</div>

</div>

</body>

</html> 