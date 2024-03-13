#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

	void turn90degreesLeft()
{


		setMotorSpeed(leftMotor, 0);
		setMotorSpeed(rightMotor, 50);
		wait1Msec(900);

}

	void turn90degreesRight()
{


		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 0);
		wait1Msec(900);
}
	void goForward1second()
{
		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 50);
		wait1Msec(1000);
}
	void swingRight90degrees()
	{


		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 0);
		wait1Msec(900);
	}
	void swingLeft90degrees()
	{
		;


		setMotorSpeed(leftMotor, 0);
		setMotorSpeed(rightMotor, 50);
		wait1Msec(900);
	}

	void reverse1second()
	{
		setMotorSpeed(leftMotor, -100);
		setMotorSpeed(rightMotor, -100);
		wait1Msec(1000);
	}

task main()
{
	turn90degreesLeft();
	turn90degreesRight();
	goForward1second();
	swingRight90degrees();
	swingLeft90degrees();
	reverse1second();
}
