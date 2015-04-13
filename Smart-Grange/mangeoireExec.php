<?php
exec("mode com1: BAUD=9600 PARITY=N data=8 stop=1 xon=off dtr=off");
$fp = fopen("COM1", "w+");
fwrite($fp, "<WriteDigital|1>");

function openSerial($command) {
	$openSerialOK = false;
	try {
		exec("mode com1: BAUD=9600 PARITY=n DATA=8 STOP=1 to=off dtr=off rts=off");
		$fp =fopen("com1", "w");
		$openSerialOK = true;
	} catch(Exception $e) {
		echo 'Message: ' .$e->getMessage();
}
}
?>