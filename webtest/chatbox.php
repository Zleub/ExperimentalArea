<?php 

function chatbox_is_action($text)
{
	$user = new user();
	$user->fill_it($_COOKIE['key_0']);

	$array_text = explode(" ", $text);
	if($array_text[0] == "/me")
	{
		$action = chatbox_search_action($array_text);
		if($action)
		{	
			$argument = chatbox_search_argument($action, $array_text);
			call_user_func(array($user,$action), $argument);
		}
	
		$array_text[0] = $user->pseudo;
		$new_text = implode(" ", $array_text);
		$text = '<i>'.$new_text.'</i>';
	}
	else
	{
		$text = $user->pseudo.' : '.$text;
	}

	$user->fill_it($_COOKIE['key_0']);
	$user->score(1);
	$co = mysql_co();
	$query = 'INSERT INTO Chatbox VALUES ("'.$user->gameid.'","'.$user->roomid.'", "'.$text.'")';
	mysqli_query($co,$query);
	mysqli_close($co);
}

function chatbox_search_action($array_text)
{
	$pointeur = opendir('./dictio/verbs');

	$i = 0;
	while ($file[$i] = readdir($pointeur)) 
	{	
    	$i = $i + 1;
    }
    sort($file);
    $j = 3;
    while ($j <= $i)
    {
	    $array_file[$file[$j]] = file("./dictio/verbs/".$file[$j]."");
	    $j = $j + 1;
    }
    $k = 0;
    while ($array_text[$k])
    {
   	    $j = 3;
    	while($j <= $i)
    	{
    		$l = 0;
	    	while($array_file[$file[$j]][$l])
	    	{
	    		if($array_text[$k] == rtrim($array_file[$file[$j]][$l]))
	    		{
	    			$action = $file[$j];
	    			closedir($pointeur);
	    			return ($action);
	    		}
	    		else
			    	$l = $l + 1;
	    	}
	    	$j = $j + 1;
    	}
	    $k = $k + 1;
    }
    closedir($pointeur);

    /* echo '<br> DEBUG ACTION <br>';
    echo '<br> $file <br>';
    print_r($file);
    echo '<br> $array_file <br>';
    print_r($array_file);
    echo '<br> $array_text <br>';
    print_r($array_text);
    echo '<br> action <br>';
    echo $action; */
}

function chatbox_search_argument($action, $array_text)
{
	$test = file('./dictio/index');
	$i = 0;
	while($test[$i])
	{
		$array_test = explode("	", $test[$i]);
		$i = $i + 1;
	}
	$j = 0;
	while($array_test[$j])
	{
		if($action == $array_test[$j])
			$argument_type = $array_test[$j + 1];
		$j = $j + 2;
	}


	$pointeur = opendir('./dictio/args/'.rtrim($argument_type).'');

	$i = 0;
	while ($file[$i] = readdir($pointeur)) 
	{	
    	$i = $i + 1;
    }
    sort($file);
    $j = 3;
    while ($j <= $i)
    {
	    $array_file[$file[$j]] = file("./dictio/args/".rtrim($argument_type)."/".$file[$j]."");
	    $j = $j + 1;
    }
    $k = 0;
    while ($array_text[$k])
    {
   	    $j = 3;
    	while($j <= $i)
    	{
    		$l = 0;
	    	while($array_file[$file[$j]][$l])
	    	{
	    		if($array_text[$k] == rtrim($array_file[$file[$j]][$l]) && !isset($argument))
	    		{
	    			$argument = $file[$j];
	   			    closedir($pointeur);
	    			return ($argument);
	    		}
	    		else
			    	$l = $l + 1;
	    	}
	    	$j = $j + 1;
    	}
	    $k = $k + 1;
    }
    closedir($pointeur);
    
    /* echo '<br> DEBUG ARGUMENT <br>';
    echo '<br> $file <br>';
    print_r($file);
    echo '<br> $array_file <br>';
    print_r($array_file);
    echo '<br> $array_text <br>';
    print_r($array_text);


	echo '<br> $test <br>';
	print_r($test);
	echo '<br> $array_test <br>';
	print_r($array_test);
	echo '<br> $argument_type <br>';
	echo $argument_type;
	echo '<br> $argument <br>';
	echo $argument; */
}

?>