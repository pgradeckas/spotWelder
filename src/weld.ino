void fullWeld () { 													                                     //groups full weld cycle
	preHeat();
	coolDown();
	weld();
	paramsScreenDrawn = false; 							                                       // set to false to redraw the screen once back to parameter adjustment screen
	weldDone = true;                                                               // set variable to true
}

void preHeat () {                          																		   // 1st pulse, to pre-heat
	drawPreheatScreen();
	digitalWrite(relay, HIGH);
	delay(heatMsCurrent);
	digitalWrite(relay, LOW);
}

void coolDown () {                        																		   // pause between 1st and 2nd pulse, to allow metal to cool down a bit
drawDelayScreen();
delay(delayMsCurrent);
}

void weld () {                             																			 // do the actual weld
drawWeldScreen();
digitalWrite(relay, HIGH);
delay(weldMsCurrent);
digitalWrite(relay, LOW);
}
