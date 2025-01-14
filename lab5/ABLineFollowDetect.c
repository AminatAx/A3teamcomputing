#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch, modeEV3Bump)
#pragma config(Sensor, S3,     Colour,         sensorEV3_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turn90Left(); //function to do a left turn
void turn90Right(); //fuction to do a right turn
void drive(); //drive function to move robot
task main()
{

    while (SensorValue(touchSensor) != 0) //while the touch sensor it not pressed
    {
        if (SensorValue(Colour) < 40) // //the robot will follow the black line
        {
            setMotorSpeed(leftMotor, 0);
            setMotorSpeed(rightMotor, 20);
        }

        else if (SensorValue(Colour) > 40) 
        {
            setMotorSpeed(leftMotor, 20);
            setMotorSpeed(rightMotor, 0);
        }


        if (SensorValue(sonarSensor) < 10) { //but when it detects that an obstacle is 10 cm away it will stop, move back a bit and then turn left or right
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

void drive() { //function for the robot to drive until it meets an obstacle
    setMotorSpeed(leftMotor, 20);
    setMotorSpeed(rightMotor, 20);
    sleep(1000);
}


void turn90Left() { //function for the robot to turn left
    setMotorSyncEncoder(leftMotor, rightMotor, -50, 370, 50);
    sleep(1500);

}

void turn90Right() { //function for the robot to turn right
    setMotorSyncEncoder(leftMotor, rightMotor, 50, 370, 50);
    sleep(1500);
}
