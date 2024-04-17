#pragma config(Sensor, S1, touchSensor, sensorEV3_Touch)
#pragma config(Sensor, S2, gyroSensor, sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3, colorSensor, sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4, sonarSensor, sensorEV3_Ultrasonic)
#pragma config(Motor, motorA, armMotor, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorB, leftMotor, tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor, motorC, rightMotor, tmotorEV3_Large, PIDControl, driveRight, encoder)
#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define circumfrance 17.3
void drive(long nMotorRatio, long dist, long power);
void turn90(long nMotorRatio, long power);
void sqrper(long nMotorRatio, long dist, long power);


task main()
{

	//drive(0, 60, 50);
	//turn90(100, 50);
	sqrper(0, 240, 50);


}

//using drive function from previous programme
void drive(long nMotorRatio, long dist, long power)
{
	float rotations = 360 * (dist/circumfrance);

	resetMotorEncoder(motorC);
	resetMotorEncoder(motorB);

	setMotorSyncEncoder(motorC, motorB, nMotorRatio, rotations, power);

	waitUntilMotorStop(motorB);
}

//using turn90 function from previous programme
void turn90(long nMotorRatio, long power)
{


	resetMotorEncoder(motorC);
	resetMotorEncoder(motorB);

	setMotorSyncEncoder(motorC, motorB, nMotorRatio, 170, power);

	waitUntilMotorStop(motorB);

}

void sqrper(long nMotorRatio, long dist, long power)
{
		//Using the ROBOTC function random(1), robot randomly go in a square
		//either turning left or turning right
		int direction = random(1);
		if(direction == 1)
		{
			turn90(-100,100);
		}
		else
		{
			turn90(100, 100);
		}
		drive(0,60, 50);

	for (int i=0; i<3; i++)
	{
		if (direction==0)
		{
			turn90(100,100);
			drive(0,60,50);

		}
		else
		{
			turn90(-100,100);
			drive(0,60,50);
		}


	}

}
