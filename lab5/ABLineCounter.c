#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     colorSensor,    sensorEV3_Color)
#pragma config(Sensor, S3,     gyroSensor,     sensorNone)
#pragma config(Sensor, S4,     sonarSensor,    sensorNone)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//



task main() 

{ 

		int threshold = 49; 
		int lineCounter = 0; 
		bool onLine = false;
  

		while (true) 

	{ 
		
		setMotorSpeed(motorC, 50); 
		
		setMotorSpeed(motorB, 50); 

  



	if (SensorValue(colorSensor) > threshold) 
		
	{ 
		
		onLine = true; // Robot is on the line 
		
	} 
		
		else if (onLine) // If the robot was on the line and now it's off 
		
	{ 

		setMotorSpeed(motorC, 0);  
		
		setMotorSpeed(motorB, 0); 
		
		sleep(500);
		
		lineCounter++; 
		
		displayCenteredTextLine(3, "Line Count: %d", lineCounter); 
		
		onLine = false;
		
		  
		
	 
		
		setMotorSpeed(motorC, 50); 
		setMotorSpeed(motorB, 50); 

		}  

	}

}
