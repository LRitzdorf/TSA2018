#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
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

In this code, all functions for manually controlled movement are inside the
usercontrol task.
-----------------------------------------------------------------------------------*/

/*
Remote mappings:
Left stick Y-value - left drive - Ch3
Right stick Y-value - right drive - Ch2
More mappings...
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

task usercontrol() {
	// Driver-control code
	motor[leftMotor] = vexRT[Ch3];
	motor[rightMotor] = vexRT[Ch2];
	// Other controls here
  sleep(sleepValue);
}
