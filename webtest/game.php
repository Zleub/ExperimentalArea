<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
<meta http-equiv="refresh" content="30">
<link rel="stylesheet" type="text/css" href="../styles.css">
</head>

<body>
<?php

include('./mysql.php');

include('./chatbox.php');

include('./class/user.php');
include('./class/game.php');
include('./class/room.php');
include('./class/door.php');

//print_r($GLOBALS);

$cb_on_off = "on";

if (isset($_COOKIE['key_0']))
{
	if (isset($_POST['text'])) 
	{
		chatbox_is_action($_POST['text']);
	}

	$user = new user(); 
	$user->fill_it($_COOKIE['key_0']);
	
	$game = new game();
	$game->fill_it_gameid($user->gameid);
	
	$room = new room();
	$room->fill_it($user->gameid, $user->roomid);
	
	$door = new door();
	$door->fill_it($user->gameid, $user->roomid);
	
	
	var_dump($user);
	echo '<br>';
	echo '<br>';
	var_dump($game);
	echo '<br>';
	echo '<br>';
	var_dump($room);
	echo '<br>';
	echo '<br>';
	var_dump($door);

	//$array_game = mysql_load_game($array_user);
	//$array_room = mysql_load_room($array_user);
	
	if($user->gameid == NULL)
	{
		header('Location: profil.php');
	}
	
	$co	= mysql_co();
	$query = 'SELECT * FROM Users WHERE gameid="'.$user->gameid.'" AND roomid="'.$user->roomid.'"';
	$result = mysqli_query($co,$query);
	$i = 0;
	while($row = mysqli_fetch_array($result))
	{
		$array_co_user[$i]['account'] = $row['account'];
		$array_co_user[$i]['title'] = $row['title'];
		$array_co_user[$i]['pseudo'] = $row['pseudo'];
		$i = $i + 1;
	}
	rsort($array_co_user);
	$query = 'SELECT * FROM Chatbox WHERE gameid="'.$user->gameid.'" AND roomid="'.$user->roomid.'"';
	$result = mysqli_query($co,$query);
	$j = 0;
	while($row = mysqli_fetch_array($result))
	{
		$array_chatbox[$j]['message'] = $row['message'];
		$j = $j + 1;
	}
	mysqli_close($co);
}

/* print_r($GLOBALS);
echo '<br>$array_user <br>';
print_r($array_user);
echo '<br> $array_game <br>';
print_r($array_game);
echo '<br> $array_room <br>';
print_r($array_room);
echo '<br> $array_co_user <br>';
print_r($array_co_user);
echo '<br> $array_chatbox <br>';
print_r($array_chatbox); */

?>

<div class="main">

<div class="header">
<h1>Area</h1>
</div>

<div class="menu">
<h2 class = "game">Informations</h2>

<p><?php echo ''.$game->gamename.' - '.$room->roomname.''; ?></p>
<p><?php echo 'Score : '.$user->score.''; ?></p>
<p><a href="./game.php">Actualiser la pièce</a></p>
<div class="heros_box">
Personnes présentes :
<div class="heros">
<?php while($i >= 0)
{
	echo '<div class="hero">'.$array_co_user[$i]['pseudo'].' '.$array_co_user[$i]['title'].'</div>'; 
	$i = $i - 1; 
}?>
</div>
</div>
<br>

<div class = "minimap">
<?php
echo '<img class ="minimap_main" src="./img/minimap/main_80_here.png" alt="minimain">';
if(isset($room->ne))
	echo '<img class ="minimap_ne" src="./img/minimap/ne_40.png" alt="minine">';
if(isset($room->nw))
	echo '<img class ="minimap_nw" src="./img/minimap/nw_40.png" alt="mininw">';
if(isset($room->en))
	echo '<img class ="minimap_en" src="./img/minimap/en_40.png" alt="minien">';
if(isset($room->es))
	echo '<img class ="minimap_es" src="./img/minimap/es_40.png" alt="minies">';
if(isset($room->se))
	echo '<img class ="minimap_se" src="./img/minimap/se_40.png" alt="minise">';
if(isset($room->sw))
	echo '<img class ="minimap_sw" src="./img/minimap/sw_40.png" alt="minisw">';
if(isset($room->wn))
	echo '<img class ="minimap_wn" src="./img/minimap/wn_40.png" alt="miniwn">';
if(isset($room->ws))
	echo '<img class ="minimap_ws" src="./img/minimap/ws_40.png" alt="miniws">';
?>
</div>


<br>Sac ?

<br><br><a href="./profil.php">Profil</a>


</div>

<div class="right">

<div class="image">
<div class="img_box">
<img class ="scene" src="<?php echo $room->roomimg; ?>" alt="640x480">
</div>
<br>
</div>

<div class="chatbox">

<div class="cb_box">
<?php
if($cb_on_off == "off")
	echo '/!\ <i>Actions désactivées !</i>';
?>

<div class="cb_box_scroll">
<?php 
$j = $j - 1;
while($j >= 0)
{ 
	echo '<div class="message">'.$array_chatbox[$j]['message'].'</div>';
	$j = $j - 1;
} ?>
</div>

<!-- <button class="refresh" type="button" onclick="NIQUE TA MERE JAVASCRIPT"> -->


<div class="text">
<form class="message" method="post" action="game.php">
	<input class="message" maxlength="170" placeholder="Play Here !" name="text">
	<input class="send" type="submit" value="Send">
</form>
</div>

</div>
</div>

</div>

</div>

</body>

</html> 