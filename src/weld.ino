void fullWeld () { //groups full weld procedure
	preHeat();
	coolDown();
	weld();
	paramsScreenDrawn = false;  // set to false to redraw the screen once back to parameter adjustment screen
	weldDone = true;
}

void preHeat () { // 1st pulse, to pre-heat the metal
	drawPreheatScreen();
	digitalWrite(relay, HIGH);
	delay(heatMsCurrent);
	digitalWrite(relay, LOW);
}

void coolDown () { // pause between 1st and 2nd pulse, to allow metal to cool down a bit
drawDelayScreen();
delay(delayMsCurrent);
}

void weld () { // weld the metal
drawWeldScreen();
digitalWrite(relay, HIGH);
delay(weldMsCurrent);
digitalWrite(relay, LOW);
}
