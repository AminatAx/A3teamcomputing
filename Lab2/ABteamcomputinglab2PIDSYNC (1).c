#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//setMotorSyncEncoder(nMotorOne, nMotorTwo, nTurnRatio, nEncoderCount, nSignedPower);



void moveRobot(long nMotorRatio, long time, long power)
{
	setMotorSyncTime(leftMotor, rightMotor, nMotorRatio, time, power); // part 5a getting robot to move forward
	sleep(time);

}

void randomDirection()
{
	int Direction = random(1);
	if (Direction == 1)
	{
		moveRobot(100, 500, 50);
	}
	else
	{
		moveRobot(-100, 500, 50);
	}

}


task main()
{
	moveRobot(0, 3000, 50);

	randomDirection();

	moveRobot(0, 3000, 50);
	moveRobot(100, 500, 50);
	moveRobot(0, 3000, 50);
	moveRobot(100, 450, 50);
	moveRobot(0, 3000, 50);
	moveRobot(100, 450, 50);
	moveRobot(0, 3000, 50);

	moveRobot(0, 2000, 50);
	moveRobot(100, 800, 50);
	moveRobot(0, 2000, 50);


}
