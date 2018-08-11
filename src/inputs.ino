// ================== functions ========================== //

void getInputs () {        									    // cycle through this function while not welding, allow to change params
	readBtnStates(); // capture a press of any button
	if(paramsScreenDrawn == false) {
		drawParamsLabels();
		}

	Serial.println(btnStateChanged);
	Serial.println(weldDone);
		if (btnStateChanged == true || weldDone == true) {
			drawParamsValues();
			delay(delayForInputs);
		}
	resetBtnStates();  											// reset states of the buttons after done with the execution
}

void readBtnStates () {                                 // get states of the buttons

	state_btn_heatUp = digitalRead(btn_heatUp);
	state_btn_heatDown = digitalRead(btn_heatDown);
	state_btn_delayUp = digitalRead(btn_delayUp);
	state_btn_delayDown = digitalRead(btn_delayDown);
	state_btn_weldUp = digitalRead(btn_weldUp);
	state_btn_weldDown = digitalRead(btn_weldDown);
	state_btn_weldPedal = digitalRead(weldPedal);
	// adjust heat, delay and weld variable values based on buttons pressed

	if (state_btn_heatUp == HIGH) {
		heatMsPrior = heatMsCurrent;
		heatMsCurrent = heatMsCurrent + delta;
		btnStateChanged = 1;
	}

	else if (state_btn_heatDown == HIGH && heatMsCurrent >= delta) {
		heatMsPrior = heatMsCurrent;
		heatMsCurrent = heatMsCurrent - delta;
		btnStateChanged = 1;
	}

	else if (state_btn_delayUp == HIGH) {
	    delayMsPrior = delayMsCurrent;
		delayMsCurrent = delayMsCurrent + delta;
		btnStateChanged = 1;
		}

	else if (state_btn_delayDown == HIGH && delayMsCurrent >= delta) {
		delayMsPrior = delayMsCurrent;
		delayMsCurrent = delayMsCurrent - delta;
		btnStateChanged = 1;
		}

	else if (state_btn_weldUp == HIGH) {
	    weldMsPrior = weldMsCurrent;
		weldMsCurrent = weldMsCurrent + delta;
		btnStateChanged = 1;
		}

	else if (state_btn_weldDown == HIGH && weldMsCurrent >= delta) {
		weldMsPrior = weldMsCurrent;
		weldMsCurrent = weldMsCurrent - delta;
		btnStateChanged = 1;
		}
	else if (state_btn_weldPedal == LOW) {
		fullWeld();                               // we're weld if pedal is pressed
	}

}

void resetBtnStates () { // reset states of all buttons
	state_btn_heatUp = 0;
	state_btn_heatDown = 0;
	state_btn_delayUp = 0;
	state_btn_delayDown = 0;
	state_btn_weldUp = 0;
	state_btn_weldDown = 0;
	state_btn_weldPedal = 0;
	btnStateChanged = 0;
}
