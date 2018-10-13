#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*-----------------------------------------------------------------------------------
Robot code for GHS VEX Team G
2018-19 Competiton Season

Team members are Lucas Ritzdorf, Riker Foster, and Lauryn Vornbrock.

In this code, all functions for manually controlled movement are inside
separate tasks.
-----------------------------------------------------------------------------------*/

/*
Remote mappings:
Left stick Y-value - left drive - Ch3
Right stick Y-value - right drive - Ch2
Left shoulder buttons - autonomous on (and interrupt)/driver-control on - Btn5U/Btn5D
More mappings...
*/

// Standard sleep value (in milliseconds)
// Can be adjusted for responsiveness as needed
const int sleepValue = 20;

task pre_drive() {
	// Pre-driving setup
	// Set servo positions, etc.
}

task autonomous() {
	// Autonomous code
}

task leftDrive() {
	motor[leftMotor] = vexRT[Ch3];
	sleep(sleepValue);
}

task rightDrive() {
	motor[rightMotor] = vexRT[Ch2];
	sleep(sleepValue);
}

// Additional movement tasks here

task driverControl() {
	startTask(leftDrive);
	startTask(rightDrive);
}

task main() {
	// Pre-drive setup
	startTask(pre_drive);

	// Autonomous (Btn5U 2nd time to cancel)
	waitUntil(vexRT[Btn5U] == 1);
	clearTimer(T1);
	startTask(autonomous);
	while((time1[T1] <= 15000) && (vexRT[Btn5U] != 1)) {
		sleep(100);
	}
	stopTask(autonomous);
	stopAllMotors();

	// Driver-control
	waitUntil(vexRT[Btn5D] == 1);
	startTask(driverControl);
	while(true) {
		sleep(1000);
	}
}
