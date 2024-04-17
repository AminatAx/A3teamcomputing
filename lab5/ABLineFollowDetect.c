#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch, modeEV3Bump)
#pragma config(Sensor, S3,     Colour,         sensorEV3_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turn90Left(); //function to
void turn90Right();
void drive();
task main()
{

    while (SensorValue(touchSensor) != 0)
    {
        if (SensorValue(Colour) < 40)
        {
            setMotorSpeed(leftMotor, 0);
            setMotorSpeed(rightMotor, 20);
        }

        else if (SensorValue(Colour) > 40)
        {
            setMotorSpeed(leftMotor, 20);
            setMotorSpeed(rightMotor, 0);
        }


        if (SensorValue(sonarSensor) < 10) {
            displayCenteredBigTextLine(2, "Obstacle Detected");
            setMotorSpeed(leftMotor, -20);
            setMotorSpeed(rightMotor, -20);
            sleep(1000);
            turn90Left();
            drive();
            turn90Right();
            setMotorSpeed(leftMotor, 20);
            setMotorSpeed(rightMotor, 20);
            sleep(2500);
            turn90Right();
            drive();
            turn90Left();
        }

    }

}

void drive() {
    setMotorSpeed(leftMotor, 20);
    setMotorSpeed(rightMotor, 20);
    sleep(1000);
}


void turn90Left() {
    setMotorSyncEncoder(leftMotor, rightMotor, -50, 370, 50);
    sleep(1500);

}

void turn90Right() {
    setMotorSyncEncoder(leftMotor, rightMotor, 50, 370, 50);
    sleep(1500);
}
