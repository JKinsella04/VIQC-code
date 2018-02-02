#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor4,          leftArmMotor,  tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor6,          middleDriveMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor11,         rightArmMotor, tmotorVexIQ, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

static void middleDrive(const int ecount, const int speed)
{
	moveMotorTarget(middleDriveMotor, ecount, speed);
	waitUntilMotorStop(middleDriveMotor);
}

static void moveClaw(const int ecount, const int speed)
{
	moveMotorTarget(leftArmMotor, ecount, speed);
	moveMotorTarget(rightArmMotor, ecount, speed);
	waitUntilMotorStop(leftArmMotor);
}

static void fourWheelDrive(const int ecount, const int speed)
{
	moveMotorTarget(leftDriveMotor, ecount, speed);
	moveMotorTarget(rightDriveMotor, ecount, speed);
	waitUntilMotorStop(leftDriveMotor);
}

//static void realign(const float deg, const int speed) //Add a COLOR SENSOR
//{
//	if (getColorGrayscale(colorSensor) < deg) {
//		displaySensorValues(line1, colorSensor);
//		setMotorSpeed(leftDriveMotor, -speed);
//		setMotorSpeed(rightDriveMotor, speed);
//		waitUntil(getGyroDegreesFloat(colorSensor) >= deg);
//	}
//	if (getGyroDegreesFloat(colorSensor) > deg) {
//		displaySensorValues(line1, colorSensor);
//		setMotorSpeed(leftDriveMotor, speed);
//		setMotorSpeed(rightDriveMotor, -speed);0
//		waitUntil(getGyroDegreesFloat(colorSensor) <= deg);
//	}
//	stopAllMotors();
//	setMotor(middleDriveMotor, -speed);
//	wait(1, seconds);
//	stopAllMotors();
//}

task main()
{
	moveClaw(250, 50);
	fourWheelDrive(4170, 75);
	fourWheelDrive(-250, 75);


}
