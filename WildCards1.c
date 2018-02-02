#pragma config(Sensor, port5,  allignSensor,   sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port8,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          RingHolder,    tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor3,          OmniDrive,     tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor4,          RingIntake,    tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          PivotMotor,    tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor11,         leftMotor,     tmotorVexIQ, openLoop, driveLeft, encoder)
#pragma config(Motor,  motor12,         rightMotor,    tmotorVexIQ, PIDControl, reversed, driveRight, encoder)

void allign(const int coords, const int speed)
{
	if(getGyroDegrees(gyroSensor) > coords)
	{
		setMotor(rightMotor, speed);
		setMotor(leftMotor, -speed);
		waitUntil(getGyroDegrees(gyroSensor) <= coords);
		setMultipleMotors(0, rightMotor, leftMotor);
	}

	if(getGyroDegrees(gyroSensor) < coords)
	{
		setMotor(rightMotor, -speed);
		setMotor(leftMotor, speed);
		waitUntil(getGyroDegrees(gyroSensor) >= coords);
		setMultipleMotors(0, rightMotor, leftMotor);
	}
}

void fourWheelDrive(const int ecount, const int speed)
{
}

void turnLeft(const int coords, const int speed)
{
			setMotor(rightMotor, -speed);
		setMotor(leftMotor, speed);
		waitUntil(getGyroDegrees(gyroSensor) >= coords);
		setMultipleMotors(0, rightMotor, leftMotor);
}

void turnright(const int ecount, const int speed)
{
}


void moveSquare(const int ecount, const int speed)
{
	moveMotorTarget(OmniDrive, ecount, speed);
	waitUntilMotorMoveComplete(OmniDrive);
	stopMotor(OmniDrive);
}

void dumpSquare(const int ecount, const int speed)
{
	moveMotorTarget(PivotMotor, ecount, speed);
	waitUntilMotorMoveComplete(PivotMotor);
	stopMotor(PivotMotor);
}

void setup()
{
	resetMotorEncoder(OmniDrive);
	resetMotorEncoder(PivotMotor);
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	resetMotorEncoder(rightMotor);
	resetGyro(gyroSensor);
}
task main()		//setMotorTarget sets the Square to dumping positition
{
setup();
displaySensorValues(line3, gyroSensor);
turnLeft(80, 100);
displaySensorValues(line5, gyroSensor);
}
