#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)


task main()
{
		//move forward for 3 seconds
		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 50);
		sleep(3000);

		//stop and sleep for 1 second
		setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motorB) to Off
		setMotorSpeed(rightMotor, 0);  	//Set the rightMotor (motorC) to Off
		sleep(1000);

		//turning 90 degrees
		setMotorSpeed(leftMotor, 100);	//Set the leftMotor (motorB) to full power forward (100)
		setMotorSpeed(rightMotor, -100);//Set the rightMotor (motorC) to full power reverse (-100)
		sleep(225);

		//moving forward for 3 seconds
		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 50);
		sleep(3000);


		//stop and sleep for 1 second
		setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motorB) to Off
		setMotorSpeed(rightMotor, 0);  	//Set the rightMotor (motorC) to Off
		sleep(1000);

		//turn 90 degrees
		setMotorSpeed(leftMotor, 100);	//Set the leftMotor (motorB) to full power forward (100)
		setMotorSpeed(rightMotor, -100);//Set the rightMotor (motorC) to full power reverse (-100)
		sleep(225);

		//move forward for 3 seconds
		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 50);
		sleep(3000);


		//stop and sleep for 1 second
		setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motorB) to Off
		setMotorSpeed(rightMotor, 0);  	//Set the rightMotor (motorC) to Off
		sleep(1000);

		//turn 90 degrees
		setMotorSpeed(leftMotor, 100);	//Set the leftMotor (motorB) to full power forward (100)
		setMotorSpeed(rightMotor, -100);//Set the rightMotor (motorC) to full power reverse (-100)
		sleep(225);

		//move forward for 3 seconds
		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 50);
		sleep(3000);


		//stop and sleep for 1 second
		setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motorB) to Off
		setMotorSpeed(rightMotor, 0);  	//Set the rightMotor (motorC) to Off
		sleep(1000);

		//turn 90 degrees, robot is returned to starting point
		setMotorSpeed(leftMotor, 100);	//Set the leftMotor (motorB) to full power forward (100)
		setMotorSpeed(rightMotor, -100);//Set the rightMotor (motorC) to full power reverse (-100)
		sleep(225);
