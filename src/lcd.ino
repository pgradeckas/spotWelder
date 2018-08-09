void drawInitScreen () {   // display welcome message
lcd.setCursor(0, 0);
lcd.print("+------------------+");
lcd.setCursor(0, 1);
lcd.print("|    SpotWelder    |");
lcd.setCursor(0, 2);
lcd.print("|       v1.0       |");
lcd.setCursor(0, 3);
lcd.print("+------------------+");
}

void drawParamsLabels () {

		lcd.clear();
			lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Heat (ms) :");
		lcd.setCursor(0,1);
		lcd.print("Delay (ms):");
		lcd.setCursor(0, 2);
		lcd.print("Weld (ms) :");
		lcd.setCursor(0,3);
		lcd.print("-==Pedal for Weld==-");
		paramsScreenDrawn = true; // set to true so that names of adjustable variables are not redrawn
}
void drawParamsValues () {   // display parameter adjustment screen

if (heatMsCurrent != heatMsPrior) {
	lcd.setCursor(15,0);
	lcd.print("     ");
	lcd.setCursor(15,0);
	lcd.print(heatMsCurrent);
}

if (delayMsCurrent != delayMsPrior) {
	lcd.setCursor(15,1);
	lcd.print("     ");
	lcd.setCursor(15,1);
	lcd.print(delayMsCurrent);
}

if (weldMsCurrent != weldMsPrior) {
	lcd.setCursor(15,2);
	lcd.print("     ");
	lcd.setCursor(15,2);
	lcd.print(weldMsCurrent);
}
weldDone = false;
}

void drawPreheatScreen () {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("+------------------+");
	lcd.setCursor(0, 1);
	lcd.print("|       Heat       |");
	lcd.setCursor(0, 2);
	lcd.print("|                  |");
	lcd.setCursor(0, 3);
	lcd.print("+------------------+");
	}

void drawDelayScreen () {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("+------------------+");
	lcd.setCursor(0, 1);
	lcd.print("|       Cool       |");
	lcd.setCursor(0,2);
	lcd.print("|       Down       |");
	lcd.setCursor(0, 3);
	lcd.print("+------------------+");
}

void drawWeldScreen () {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("+------------------+");
	lcd.setCursor(0, 1);
	lcd.print("|       Weld       |");
	lcd.setCursor(0, 2);
	lcd.print("|                  |");
	lcd.setCursor(0, 3);
	lcd.print("+------------------+");
}
