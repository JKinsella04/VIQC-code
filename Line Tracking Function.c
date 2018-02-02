#pragma config(Sensor, port2,  leftLightSensor, sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port5,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port8,  middleLightSensor, sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port9,  middleBumpSensor, sensorVexIQ_Touch)
#pragma config(Sensor, port10, rightLightSensor, sensorVexIQ_ColorGrayscale)
#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor4,          leftArmMotor,  tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor6,          middleDriveMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor11,         rightArmMotor, tmotorVexIQ, PIDControl, encoder)

int threshold = 50;

static void leftSensorTracking(const int count, const int speed)
{
	int i=0;
  setMotorSpeed(middleDriveMotor, speed);
	while(i < count)
	{
		while(i < count-1)
		{
			if (getColorGrayscale(leftLightSensor) <= threshold)
			{
				i++;
				displayVariableValues(line2, i);
				waitUntil(getColorGrayscale(leftLightSensor) >= threshold);
				if(getGyroHeading(gyroSensor) > 90)
				{
					setMotor(rightDriveMotor, 10);
					setMotor(leftDriveMotor, -10);
					waitUntil(getGyroHeading(gyroSensor) <= 90);
					setMultipleMotors(0, rightDriveMotor, leftDriveMotor);
				}
				if(getGyroHeading(gyroSensor) < 90)
				{
					setMotor(rightDriveMotor, -10);
					setMotor(leftDriveMotor, 10);
					waitUntil(getGyroHeading(gyroSensor) >= 90);
					setMultipleMotors(0, rightDriveMotor, leftDriveMotor);
				}
			}
		}
		setMotorSpeed(middleDriveMotor, speed/2);
		waitUntil(getColorGrayscale(leftLightSensor) <= threshold);
		i++;
	}
	stopAllMotors();
	setMotor(middleDriveMotor, 0);
}
