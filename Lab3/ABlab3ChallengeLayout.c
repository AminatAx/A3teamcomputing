#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	//while touch sensor isnt pressed
	while(SensorValue(touchSensor)== 0)
	{
		setMotorSpeed (motorB, 50;
		setMotorSpeed (motorC, 50;
	}

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	wait1Msec(500);

	//this is to move slightly back
	setMotorSpeed(motorB, -30);
	setMotorSpeed(motorC, -30);
	wait1Msec(500);

	//this is for the robot to turn 90 degrees
	setMotorSpeed(motorB, -50);
	setMotorSpeed(motorC, 50);
	wait1Msec(305);

	//while sonar sensor is greater than 10
	while(sensorValue(sonarSensor)>10)
	{
		setMotorSpeed (motorB, 50;
		setMotorSpeed (motorC, 50;

	}
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	wait1Msec(500);

	setMotorSpeed(motorB, -30);
	setMotorSpeed(motorC, -30);
	wait1Msec(500);

	//this is for the robot to turn 90 degrees
	setMotorSpeed(motorB, -50);
	setMotorSpeed(motorC, 50);
	wait1Msec(305);

	while(SensorValue(touchSensor)== 0)
	{
		setMotorSpeed (motorB, 50;
		setMotorSpeed (motorC, 50;
	}

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	wait1Msec(500);

	//this is to move slightly back
	setMotorSpeed(motorB, -30);
	setMotorSpeed(motorC, -30);
	wait1Msec(500);

	//this is for the robot to turn 90 degrees
	setMotorSpeed(motorB, -50);
	setMotorSpeed(motorC, 50);
	wait1Msec(305);

	nMotorEncoder (motorB) =  0;


	// this is for the robot to move forward 30 centimeters
	while(nMotorEncoder(motorB)<(360*30/17.27))
	{
		setMotorSpeed(motorB, 50);
		setMotorSpeed(motorC, 50);
	}


}
