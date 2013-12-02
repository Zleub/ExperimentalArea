<?php

class door
{
	public $gameid;
	public $roomid_in;
	public $roomid_out;
	public $position;
	public $status;
	public $size;

    public function fill_it($gameid, $roomid) 
    {
	    $co = mysql_co();
	    $query = 'SELECT * FROM Doors WHERE gameid="'.$gameid.'" AND roomid_in="'.$roomid.'"';
	    $result = mysqli_query($co,$query);
	    $i = 0;
	    while($row = mysqli_fetch_array($result))
	    {
	    	$this->gameid[$i] = $row['gameid'];
		    $this->roomid_in[$i] = $row['roomid_in'];
		    $this->roomid_out[$i] = $row['roomid_out'];
		    $this->position[$i] = $row['position'];
		    $this->status[$i] = $row['status'];
		    $this->size[$i] = $row['size'];
		    $i = $i + 1;
		}
		mysqli_close($co);
    }
}

?>