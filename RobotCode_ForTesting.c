#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           liftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           forkMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

/*-----------------------------------------------------------------------------------
Robot code for GHS VEX Team G
2018-19 Competiton Season

Team members are Lucas Ritzdorf, Riker Foster, and Lauryn Vornbrock.

In this code, all functions for manually controlled movement are inside the
usercontrol task.
-----------------------------------------------------------------------------------*/

/*
Remote mappings:
Left stick Y-value -- left drive ---- Ch3
Right stick Y-value - right drive --- Ch2
Right buttons U, D -- lift up, down - Btn8U, Btn8D
Right buttons L, R -- fork rotation - Btn8L, Btn8R
*/

// Standard sleep value (in milliseconds)
// Can be adjusted for responsiveness as needed
const int sleepValue = 20;

task main() {
	while (true) {
		// Driver-control code
		
		// Drive motor control
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];
		
		// Lift control
		if (vexRT[Btn8U] == 1) { motor[liftMotor] = 127; }
		else if (vexRT[Btn8D] == 1) { motor[liftMotor] = -100; }
		
		// Fork control
		if (vexRT[Btn8L] == 1) { motor[forkMotor] = 127; }
		else if (vexRT[Btn8R] == 1) { motor[forkMotor] = -127; }
		
		// Pause for sleepValue milliseconds
		sleep(sleepValue);
	}
}
