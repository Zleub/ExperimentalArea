<?php

class user
{
    public $account;
    public $password;
    public $title;
    public $gameid;
    public $roomid;
    public $pseudo;
    public $score;
    
    
    public function fill_it($user) 
    {
	    $co = mysql_co();
	    $query = 'SELECT * FROM Users WHERE account = "'.$user.'"';
	    $result = mysqli_query($co,$query);
	    while($row = mysqli_fetch_array($result))
	    {
			$this->account = $row['account'];
			$this->password = $row['password'];
			$this->title = $row['title'];
			$this->gameid = $row['gameid'];
			$this->roomid = $row['roomid']; 
			$this->pseudo = $row['pseudo'];
			$this->score = $row['score'];
		}
		mysqli_close($co);
    }
    
    public function update_title($new_title)
    {
	    $co = mysql_co();
		$query = 'UPDATE Users SET title="'.$new_title.'" WHERE account = "'.$this->account.'"';
		mysqli_query($co,$query);
		mysqli_close($co);
    }
    
    public function move($argument)
    {
   		$co = mysql_co();
   		$query = 'SELECT '.$argument.' FROM Rooms WHERE gameid="'.$this->gameid.'" and roomid="'.$this->roomid.'"';
   		$result = mysqli_query($co,$query);
   		while($row = mysqli_fetch_array($result))
   		{
			$new_room = $row[$argument];
		}
		if($new_room != NULL)
		{
			$query = 'UPDATE Users SET roomid="'.$new_room.'" WHERE account = "'.$this->account.'"';
			mysqli_query($co,$query);
		}
		mysqli_close($co); 
   	    $this->score(1);
    }
    
    public function score($toadd)
    {
	    $co = mysql_co();
	    $toadd = $this->score + $toadd;
		$query = 'UPDATE Users SET score="'.$toadd.'" WHERE account = "'.$this->account.'"';
		mysqli_query($co,$query);
		mysqli_close($co);
    }
 
}

?>