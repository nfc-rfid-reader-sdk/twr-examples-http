<?PHP
// FIXME: test input data and protect script from malicious content
$SN = $_POST["SN"];
$UID = $_POST["UID"];
$CTRLINFO = $_POST["CTRLINFO"];

$NOW = date("Y-m-d H:i:s");

// append data to the file
// in format: SN=WR654321,UID=52:DA:D9:95,CTRLINFO=129,TIME='2018-02-08 16:11:30'
$data = "SN=$SN,UID=$UID,CTRLINFO=$CTRLINFO,TIME='$NOW'\n";

$file = "/tmp/twr-test-data-log.txt";

$r = file_put_contents($file, $data, FILE_APPEND | LOCK_EX);

// TODO: create SQL string
// + actual data-time
// put in to database

// send ACK back
if ($r > 0)
	echo "OK";
else
	echo "FAILED";

?>
