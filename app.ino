#include <SoftwareSerial.h>

#define SWITCH 2
#define STARTER 3
#define RUNNING 4

void setup() {
	pinMode(SWITCH, INPUT);
	pinMode(STARTER, OUTPUT);
	pinMode(RUNNING, OUTPUT);
	Serial.begin(9600);

	digitalWrite(STARTER, HIGH);
	digitalWrite(RUNNING, HIGH);
}

//This is what a comment looks like
void loop() {
	if (digitalRead(SWITCH) == LOW) {
		digitalWrite(STARTER, HIGH);
		digitalWrite(RUNNING, HIGH);
	} else {
		for (int i = 0; i < 250; i++) {
			digitalWrite(STARTER, LOW);
			digitalWrite(RUNNING, LOW);

			if (digitalRead(SWITCH) == LOW) {
				break;
			}

			delay(20);
		}
		while(digitalRead(SWITCH) == HIGH){
			digitalWrite(STARTER, HIGH);
		}
	}
}
