#define leftMotor 1
#define rightMotor 2

//function signatures
void findPosition(int x, int y);
void drive(int speed);
void AngleTurn(int y, int Y);
void driveForward(int x, int X, int y, int Y);

task main()
{
	//starting position
	int x = 3;
	int y = 1;
	
	//displaying intructions to user
	displayCenteredBigTextLine(4, "press Up");
	//finding position destination
	findPosition(x,y);
}


//this will get the destination
void findPosition(int x, int y)
{	
	int Y;
	int X;
	
	//while the button isnt pressed
	while (getButtonPress(buttonEnter)  == 0)
	{
		//if user presses buttonup
		if (getButtonPress(buttonUp))
		{	
			displayCenteredBigTextLine(1, "moving to 3,7");
			getToY = 7;
			getX = 3;
			//calling driveForward
			driveForward(x, getX, y, getToY); 
		}
		//else display invalid input
		else if (getButtonPress(buttonDown))
		{
			displayCenteredBigTextLine(4, "invalid input");
			
		}
	}//end while loop
	
}

//driving 1 square
void drive(int speed)
{
	// rotates the robot's wheels 360 degrees
	setMotorSyncEncoder(leftMotor, rightMotor, 0, 330, speed);
	sleep(3000);
	
}

//function to turn an angle of 90 degrees left or right
void AngleTurn(int y, int Y)
{	
	int Angle;
	 // Clear the display
	eraseDisplay(); 
	displayCenteredTextLine(2,"gyro resetting");
	//set sensor to port 2
	SensorType[S2] = sensorEV3_Gyro;
	sleep(500);
	//reset Gyro 
	resetGyro(S2);
	//sleep for 3
	sleep(3);
	//displaying angle
	displayCenteredTextLine(2,"Angle =%d",getGyroDegrees(S2));
	sleep(500);
	
	// Turn Robot 90 degrees around
	eraseDisplay();
	//Get the starting angle
	Angle=getGyroDegrees(S2); 
	displayCenteredTextLine(2,"Angle =%d",Angle);

	//if y is smaller or equal to the destination number
	if (y <= Y) 
	{
		setMotorSync(leftMotor, rightMotor, -100, 10); 
		displayCenteredTextLine(4,"rotating 90");
		while (abs(Angle) < 90)
		{
			sleep(2);
			Angle=getGyroDegrees(S2);
			//displaying angle
			displayCenteredBigTextLine(5,"current angle %4d",Angle); 
		}
		setMotorSync(leftMotor, rightMotor, 0, 0); 
		sleep(500);
	}
	
	//if y is bigger than the destination number
	else if (y > Y) 
	{
		setMotorSync(leftMotor, rightMotor, -10, 100); 
		displayCenteredTextLine(4,"rotating 90");
		while (abs(Angle) < 270)
		{
			sleep(2);
			Angle=getGyroDegrees(S2);
			//displaying angle
			displayCenteredBigTextLine(5,"current angle %4d",Angle); 
		}
		setMotorSync(leftMotor, rightMotor, 0, 0); 
		sleep(500);
	}
	//clear
	eraseDisplay(); 
	
}
//function driveForward while distance isnt 0
void driveForward(int x, int X, int y, int Y)
{
	int distance = X - x;
	int dist = Y - y;
	
	//while the distance is not 0
	while (distance != 0)
	{
		// if distance is grater then 0 move it forward
		if (distance > 0) 
		{
			//calling drive to move straight
			drive(20); 
			//plus 1
			x = x + 1; 
			//beep
			playTone(784, 15)
			displayCenteredTextLine(4, "Position is %d,%d", x, y);
			distance--;
		}
		
		// if distance is less then 0 move forward
		else if (distance < 0) 
		{
			//drive function to move straight
			drive(20); 
			//plus 1
			x = x - 1; 
			//beep
			playTone(784,15)
			displayCenteredTextLine(4, "Position is %d,%d", x, y);
			distance++;
		}
	}
	//calling angleturn to turn 90
	AngleTurn(y, Y); 
	
	//while distance isnt 0
	while (dist != 0)
	{
		// if  distance is greater than 0 move forward
		if (dist > 0) 
		{
			//calling drive to move forward
			drive(20); 
			//plus 1
			y = y + 1;
			//beep
			playTone(784,15)
			displayCenteredTextLine(4, "Current Position [%d,%d]", x, y);
			sleep(500);
			dist--;
		}
		
		// if distance is less than 0 move forward
		else if (dist < 0) 
		{
			//calling drive to move forward
			drive(20); 
			//plus 1
			y = y - 1; 
			//beep
			playTone(784,15)
			displayCenteredTextLine(4, "Current Position [%d,%d]", x, y);
			sleep(500);
			dist++;
		}
	}
	//calling angle turn to turn 90
	AngleTurn(y, Y); 
	
	// stops the motors
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(2);
}