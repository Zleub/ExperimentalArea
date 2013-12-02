<?php

class game
{
    public $gameid;
    public $gamename;
    public $startroom;
    
    public function fill_it_gameid($gameid) 
    {
	    $co = mysql_co();
	    $query = 'SELECT * FROM Games WHERE gameid = "'.$gameid.'"';
	    $result = mysqli_query($co,$query);
	    while($row = mysqli_fetch_array($result))
	    {
			$this->gameid = $row['gameid'];
			$this->gamename = $row['gamename'];
			$this->startroom = $row['startroom'];
		}
		mysqli_close($co);
    }
    
    public function fill_it_gamename($gamename) 
    {
	    $co = mysql_co();
	    $query = 'SELECT * FROM Games WHERE gamename = "'.$gamename.'"';
	    $result = mysqli_query($co,$query);
	    while($row = mysqli_fetch_array($result))
	    {
			$this->gameid = $row['gameid'];
			$this->gamename = $row['gamename'];
			$this->startroom = $row['startroom'];
		}
		mysqli_close($co);
    }
}

?>