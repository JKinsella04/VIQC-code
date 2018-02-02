#pragma config(Sensor, port2,  leftLightSensor, sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port5,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port9,  middleBumpSensor, sensorVexIQ_Touch)
#pragma config(Sensor, port10, rightLightSenssor, sensorVexIQ_ColorGrayscale)
#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor4,          leftArmMotor,  tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor6,          middleDriveMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor11,         rightArmMotor, tmotorVexIQ, PIDControl, encoder)

task main()
{
  while(true)
  {
		displaySensorValues(line1, leftLightSensor);
		displaySensorValues(line5, rightLightSenssor);
	}
}
