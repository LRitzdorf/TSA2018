#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           liftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           forkMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Vex_Competition_Includes.c"

/*-----------------------------------------------------------------------------------
Robot code for GHS VEX Team G
2018-19 Competiton Season

Team members are Lucas Ritzdorf, Riker Foster, and Lauryn Vornbrock.

In this code, all functions for manually controlled movement are inside
separate tasks.
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

void pre_auton() {
	bStopTasksBetweenModes = true;
	// Pre-driving setup
	// Set servo positions, etc.
	return;
}

task autonomous() {
	// Autonomous code
}

task leftDrive() {
	while (true) {
		motor[leftMotor] = vexRT[Ch3];
		sleep(sleepValue);
	}
}

task rightDrive() {
	while (true) {
		motor[rightMotor] = vexRT[Ch2];
		sleep(sleepValue);
	}
}

// Additional movement tasks here

task usercontrol() {
	startTask(leftDrive);
	startTask(rightDrive);
}