#pragma config(Sensor, S4,     sonarSensor,    sensorNone)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int threshold = 49;
	while(true)
	{
		if(getColorReflected(colorSensor)<threshold) //if it detects a black line it follows the line
		{
			setMotorSpeed(motorB, 10);
			setMotorSpeed(motorC, 50);
		}
		else //when it doesn't detect ablack line it will turn and try and fine the line again
		{
			setMotorSpeed(motorB,50);
			setMotorSpeed(motorC,10);
		}
	}
