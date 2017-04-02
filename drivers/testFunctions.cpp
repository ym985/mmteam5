/**
 * Implementation of test functions.
 */

#include "testFunctions.hpp"

extern Buzzer buzzer;
extern PwmOut ledMf;
extern DigitalOut ledRed;
extern DigitalOut ledYellow;
extern DigitalOut ledGreen;

void cycleLEDs(float flashPeriod)
{
	ledRed = 0;
	ledYellow = 0;
	ledGreen = 0;

	for(int i = 0; i < 3; i += 1 ) {
		ledRed = !ledRed;
		wait(flashPeriod);

		ledRed = !ledRed;
		ledYellow = !ledYellow;
		wait(flashPeriod);

		ledYellow = !ledYellow;
		ledGreen = !ledGreen;
		wait(flashPeriod);

		ledGreen = !ledGreen;
	}
}

void cycleMFs(float flashPeriod)
{
	float a = 0.0;
	ledMf.period_ms(5);
	ledMf.write(a);

	for(int i = 1; i <= 5; i += 1) {
		a += 0.2;
		ledMf.write(a);
		wait(flashPeriod);
	}

	ledMf.write(0);
}

void testBuzzer()
{
	buzzer.testSound();
}