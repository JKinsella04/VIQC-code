#pragma config(Sensor, port2,  LightSensor,    sensorVexIQ_ColorHue)
#pragma config(Sensor, port3,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          leftClawMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor4,          rightGroundMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor5,          middleSquareMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          dumpMotor,     tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor10,         rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor11,         leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*/

task dump() {
	allign(scoreHeading, alingSpeed);
	leftSensorTracking(1, lineSpeed, scoreHeading);
	moveClaw(300, 75);
	fourWheelDrive(750, scoreHeading, fourSpeed);
	backup(225, fourSpeed);
	middleDrive(-25, 25);
	moveClaw(-400, 75);
	backup(-935, fourSpeed);
	clawReset();



task main()
{



}
