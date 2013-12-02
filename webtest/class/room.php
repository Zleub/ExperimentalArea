<?php

class room
{
	public $gameid;
	public $roomid;
	public $roomname;
	public $roomimg;
	public $nw;
	public $ne;
	public $en;
	public $es;
	public $se;
	public $sw;
	public $ws;
	public $wn;

    public function fill_it($gameid, $roomid) 
    {
	    $co = mysql_co();
	    $query = 'SELECT * FROM Rooms WHERE gameid="'.$gameid.'" AND roomid="'.$roomid.'"';
	    $result = mysqli_query($co,$query);
	    while($row = mysqli_fetch_array($result))
	    {
	    	$this->gameid = $row['gameid'];
		    $this->roomid = $row['roomid'];
		    $this->roomname = $row['roomname'];
		    $this->roomimg = $row['roomimg'];
		    $this->nw = $row['nw'];
		    $this->ne = $row['ne'];
		    $this->en = $row['en'];
		    $this->es = $row['es'];
		    $this->se = $row['se'];
		    $this->sw = $row['sw'];
		    $this->ws = $row['ws'];
		    $this->wn = $row['wn'];
		}
		mysqli_close($co);
    }
}

?>