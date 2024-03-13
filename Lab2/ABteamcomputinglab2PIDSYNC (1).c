#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//setMotorSyncEncoder(nMotorOne, nMotorTwo, nTurnRatio, nEncoderCount, nSignedPower);

//Programme description: Using PID controls create 2 functions: moveRobot and randomDirection

//Function to get the robot to move forward
void moveRobot(long nMotorRatio, long time, long power)
{
	setMotorSyncTime(leftMotor, rightMotor, nMotorRatio, time, power); // part 5a getting robot to move forward
	sleep(time);

}

//if statement that set the robot to move in a random direction depending on if it chooses a 0 or 1
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

//main function that calls the moveRobot and randomDirection and imlements the code
task main()
{
	moveRobot(0, 3000, 50);

	randomDirection();

//this part of the code implement Lab2 part 6 which gets the robot to move in a square and to go forward for 2 second  at full speed, spin 180 degrees and then travel back at half speed
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
