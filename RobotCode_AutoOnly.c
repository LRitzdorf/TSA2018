#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           liftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           swivelMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Sensor, dgtl10,          redLED,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl11,          yellowLED,     sensorLEDtoVCC)
#pragma config(Sensor, dgtl12,          greenLED,      sensorLEDtoVCC)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

/*-----------------------------------------------------------------------------------
Robot code for GHS VEX Team G
2018-19 Competiton Season

Team members are Lucas Ritzdorf, Riker Foster, and Lauryn Vornbrock.

This version of the robot code is intended to be used exclusively for testing
purposes. For that reason, it is not equipped to interact with the competition
control system, and will immediately start the AUTONOMOUS portion of the code.
-----------------------------------------------------------------------------------*/

// Variable Definitions
const float turnTime = 1000;
float clawTime = 500;
int clawDir = -1;
float liftTime = 3000;
int liftDir = 1;

// Task to open or close the claw concurrently
task claw()
{
	setMotor(clawMotor, clawDir*127);
	sleep(clawTime);
	stopMotor(clawMotor);
}

// Task to raise or lower the lift concurrently
task lift()
{
	setMotor(liftMotor, liftDir*127);
	sleep(liftTime);
	stopMotor(liftMotor);
}

task auto()
{
	turnLEDOff(redLED);
	turnLEDOn(yellowLED);
	// Turn left
	setMotor(leftMotor, -24);
	setMotor(rightMotor, 64);
	sleep(750);
	setMotor(leftMotor, -96);
	sleep(400); // To a right angle
	sleep(100); // Angled slightly toward the wall
	stopMultipleMotors(leftMotor, rightMotor);
	// Drive forwards
	setMultipleMotors(127, leftMotor, rightMotor);
	sleep(1750);
	// Turn slightly right and drive forwards
	setMotor(leftMotor, 64);
	stopMotor(rightMotor);
	sleep(500);
	setMotor(rightMotor, 64);
	sleep(1000);
	// Back up and turn (and open claw)
	clawDir = -1; startTask(claw); clearTimer(T1);
	setMotor(leftMotor, -127);
	setMotor(rightMotor, -32);
	sleep(1500);
	// Back up
	setMultipleMotors(leftMotor, rightMotor, -127);
	sleep(1500);
	// Turn right
	motor[leftMotor] = 127;
	motor[rightMotor] = -127;
	sleep(turnTime+500);
	// Drive forwards (after the claw has opened)
	while(time1[T1] < clawTime) { sleep(0.1); }
	setMultipleMotors(64, leftMotor, rightMotor);
	sleep(1500);
	// Flip the cap
	setMultipleMotors(32, leftMotor, rightMotor);
	setMotor(liftMotor, 127);
	sleep(1500);
	stopAllMotors();
	sleep(250);
	// Back up and lower lift
	liftDir = -1; liftTime = 3; startTask(lift); clearTimer(T2);
	setMultipleMotors(-127, leftMotor, rightMotor);
	sleep(1750);
	// Turn right
	setMotor(leftMotor, 127);
	setMotor(rightMotor, -127);
	sleep(turnTime);
	// Drive forward
	setMultipleMotors(127, leftMotor, rightMotor);
	sleep(1000);
	// Turn left
	setMotor(leftMotor, -127);
	setMotor(rightMotor, 127);
	sleep(turnTime);
	// Drive forward
	setMultipleMotors(127, leftMotor, rightMotor);
	sleep(2500);
	// Lift the cap
	setMotor(liftMotor, 64);
	setMultipleMotors(32, leftMotor, rightMotor);
	sleep(1000);
	// Turn and set the cap down
	setMotor(leftMotor, -32);
	setMotor(rightMotor, 16);
	sleep(2000);
	// Done
	stopAllMotors();
	turnLEDOff(greenLED);
	turnLEDOn(yellowLED);
}

// Emergency-stop task
task e_stop()
{
	while(true) {
		if (vexRT[Btn8L] == 1) {
			turnLEDOff(yellowLED);
			turnLEDOn(redLED);
			stopTask(auto);
			stopAllMotors();
		}
		sleep(0.1);
	}
}

task main()
{
	turnLEDOff(redLED);
	turnLEDOff(yellowLED);
	turnLEDOff(greenLED);
	startTask(e_stop);
	while(true) {
		if (vexRT[Btn8R] == 1) { startTask(auto); }
		sleep(100);
	}
}