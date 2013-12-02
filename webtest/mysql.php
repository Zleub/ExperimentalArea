<?php 

function mysql_co()
{
	$co = mysqli_connect("localhost","root","asdzefasxzdc123","Area");
	if (mysqli_connect_errno($co))
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}
	return $co;
}

/* function mysql_load_user($user)
{
	$co = mysql_co();
	$query = 'SELECT * FROM Users WHERE account = "'.$user.'"';
	$result = mysqli_query($co,$query);
	while($row = mysqli_fetch_array($result))
	{
		$array_user['account'] = $row['account'];
		$array_user['password'] = $row['password'];
		$array_user['title'] = $row['title'];
		$array_user['gameid'] = $row['gameid'];
		$array_user['roomid'] = $row['roomid']; 
		$array_user['pseudo'] = $row['pseudo'];
	}
	mysqli_close($co);
	return $array_user;
}

function mysql_load_room($array_user)
{
	$co = mysql_co();
	$query = 'SELECT * FROM Rooms WHERE gameid="'.$array_user['gameid'].'" AND roomid="'.$array_user["roomid"].'"';
	$result = mysqli_query($co,$query);
	while($row = mysqli_fetch_array($result))
	{
		$array_room['gameid'] = $row['gameid'];
		$array_room['roomid'] = $row['roomid'];
		$array_room['roomname'] = $row['roomname'];
		$array_room['roomimg'] = $row['roomimg'];
		$array_room['nw'] = $row['nw'];
		$array_room['ne'] = $row['ne'];
		$array_room['en'] = $row['en'];
		$array_room['es'] = $row['es'];
		$array_room['se'] = $row['se'];
		$array_room['sw'] = $row['sw'];
		$array_room['ws'] = $row['ws'];
		$array_room['wn'] = $row['wn'];
		
	}	
	mysqli_close($co);
	return $array_room;
}

function mysql_load_game($array_user)
{
	$co = mysql_co();
	$query = 'SELECT * FROM Games WHERE gameid="'.$array_user['gameid'].'"';
	$result = mysqli_query($co,$query);
	while($row = mysqli_fetch_array($result))
	{
		$array_game['gameid'] = $row['gameid'];
		$array_game['gamename'] = $row['gamename'];
		$array_game['startroom'] = $row['startroom'];
	}
	mysqli_close($co);
	return $array_game;
} */
?>