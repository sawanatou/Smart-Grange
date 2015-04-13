<?php
function openSerial($command) {
	$openSerialOK = false;
	try {
		exec("mode com1: BAUD=9600 PARITY=n DATA=8 STOP=1 to=off dtr=off rts=off");
		$fp =fopen("com1", "w");
		$openSerialOK = true;
	} catch(Exception $e) {
		echo 'Message: ' .$e->getMessage();
	}

	if($openSerialOK) {
		fwrite($fp, $command);
		fclose($fp);
    }	
}

if(isset($_POST['submit1'])) {
    openSerial("@00 on 1\r");
}

if(isset($_POST['submit2'])) {
    openSerial("@00 of 1\r");
}

if(isset($_POST['submit3'])) {
    openSerial("@00 on 2\r");
}

if(isset($_POST['submit4'])) {
    openSerial("@00 of 2\r");
}
?>
