#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)

task main()
{
	setMotorSpeed(leftMotor, 60);
	setMotorSpeed(rightMotor, 100);
	sleep(2000);

	setMotorSpeed(leftMotor, 100);
	setMotorSpeed(rightMotor, 60);
	sleep(3000);

	setMotorSpeed(leftMotor, 60);
	setMotorSpeed(rightMotor, 100);
	sleep(2000);

	setMotorSpeed(leftMotor, 60);
	setMotorSpeed(rightMotor, 100);
	sleep(1500);



}
