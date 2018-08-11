#include <Arduino.h>
#include <LiquidCrystal.h>

// button related variables
const int btn_heatUp = 13;
const int btn_heatDown = 8;
const int btn_delayUp = 6;
const int btn_delayDown = 9;
const int btn_weldUp = 7;
const int btn_weldDown = 10;
const int weldPedal = A0;
const int relay = A1;

// button state related variables
int state_btn_heatUp = 0;
int state_btn_heatDown = 0;
int state_btn_delayUp = 0;
int state_btn_delayDown = 0;
int state_btn_weldUp = 0;
int state_btn_weldDown = 0;
int state_btn_weldPedal = 0;
bool btnStateChanged = true;
bool weldDone = false;
bool paramsScreenDrawn = false;

//weld timing related variables
int heatMsPrior = 0;
int delayMsPrior = 0;
int weldMsPrior = 0;
int heatMsCurrent = 10;
int delayMsCurrent = 30;
int weldMsCurrent = 60;
int heatMsMax = 50;
int delayMsMax = 3000;
int weldMsMax = 200;
int delta = 5;

//delay timing related variables
int delayForInputs = 250;

// LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);						                           // Initialise lcd

void setup()
{
	pinMode(btn_heatUp, INPUT);
	pinMode(btn_heatDown, INPUT);
	pinMode(btn_delayUp, INPUT);
	pinMode(btn_delayDown, INPUT);
	pinMode(btn_weldUp, INPUT);
	pinMode(btn_weldDown, INPUT);
	pinMode(weldPedal, INPUT);
	pinMode(relay, OUTPUT);
	digitalWrite(relay, LOW);
	lcd.begin(20, 4); 										                                         // initialise 2004 LCD
	drawInitScreen();
	delay(1000);
}

void loop() {
	getInputs();                                                                   // just listen for inputs
}
