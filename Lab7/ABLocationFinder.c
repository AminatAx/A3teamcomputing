#define leftMotor 1
#define rightMotor 2

//function signatures
void findPosition(int x, int y);
void drive(int speed);
void AngleTurn(int y, int Y);
void driveForward(int x, int X, int y, int Y);


task main()
{
	//Set starting position
	int x = 1;
	int y = 4;
	
	
	// Display target options to the user
	displayCenteredBigTextLine(4, "Up for Target 1 or");
	displayCenteredBigTextLine(6, "DOWN for Target 2");
	displayCenteredBigTextLine(2, "Position: [%d,%d]", x, y);
	

	//calling the fuction to get the robots target location
	findPosition(x,y);
}


//funtion to get the robots target location
void findPosition(int x, int y)
{	
	int Y;
	int X;
	
	
	//as long the enter botton not pressed 
	while (getButtonPress(buttonEnter)  == 0)
	{
		//when the user presses the up button, the robot will move to position to 4,1
		if (getButtonPress(buttonUp))
		{	
			displayCenteredBigTextLine(1, "Moving to Target 1");
			getToY = 1;
			getX = 4;
			driveToPosition(x, getX, y, getToY); //calling the function that moves the robot   
		}
		//else when the user presses the down button, the robot will move to potition to 5,6
		else if (getButtonPress(buttonDown))
		{
			displayCenteredBigTextLine(1, "Moving to Target 2");
			getToY = 6;
			getX = 5;
			driveForward(x, getX, y, getToY);     //calling the function that moves the robot to the desired location
		}
	}//end while loop
	
}


//function that makes the robot move one square at a time
void drive(int speed)
{
	// rotates the robot's wheels 360 degrees
	setMotorSyncEncoder(leftMotor, rightMotor, 0, 330, speed);
	sleep(3000);
	
}


//function that turns the robot 90 degrees left or right
void AngleTurn(int y, int Y)
{	
	int Angle;
	
	
	eraseDisplay(); // Clear the display
	displayCenteredTextLine(2,"gyro resetting");
	SensorType[S2] = sensorEV3_Gyro; // Gyro sensor is in the second port
	sleep(500);
	resetGyro(S2); //reset Gyro to get to 0 degrees
	sleep(3);
	displayCenteredTextLine(2,"Angle =%d",getGyroDegrees(S2));
	sleep(500);
	
	
	// Turn Robot 90 degrees around, then stop:
	eraseDisplay();
	Angle=getGyroDegrees(S2); // Get the starting angle which should be 0
	displayCenteredTextLine(2,"Angle =%d",Angle);
	
	
	// checks if y is smaller or equal to the destination number
	if (y <= Y) 
	{
		setMotorSync(leftMotor, rightMotor, -100, 10); //start motor 
		displayCenteredTextLine(4,"rotating 90");
		while (abs(Angle) < 90)
		{
			sleep(2);
			Angle=getGyroDegrees(S2);
			displayCenteredBigTextLine(5,"current angle %4d",Angle); //displays the current angle
			
		}
		setMotorSync(leftMotor, rightMotor, 0, 0); // stop the motors
		sleep(500);
	}
	
	// checks if y is bigger than the destination number
	else if (y > Y) 
	{
		setMotorSync(leftMotor, rightMotor, 100, -10); //start motor 
		displayCenteredTextLine(4,"rotating 90");
		while (abs(Angle) < 270)
		{
			sleep(2);
			Angle=getGyroDegrees(S2);
			displayCenteredBigTextLine(5,"current angle %4d",Angle);  //displays the current angle
			
		}
		setMotorSync(leftMotor, rightMotor, 0, 0); // stop the motors
		sleep(500);
	}
	eraseDisplay(); // Clear the display
	
}


//function that moves the robot to the desired location
void driveForward(int x, int X, int y, int Y)
{
	int distance = X - x;
	int dist = Y - y;
	
	// loops while the distance is not 0
	while (distance != 0)
	{
		// if the distance is bigger than 0, moves the robot forward
		if (distance > 0) 
		{
			drive(20); //calling drive function to drive straight
			x = x + 1; // increments x by 1
			displayCenteredTextLine(4, "Current Position [%d,%d]", x, y);
			distance--;
		}
		
		// if distance is less than 0, moves the robot forward
		else if (distance < 0) 
		{
			drive(20); //calling drive function to drive straight
			x = x - 1; // decrements x by 1
			displayCenteredTextLine(4, "Current Position [%d,%d]", x, y);
			distance++;
		}
	}
	
	AngleTurn(y, Y); //calling function to turn 90 degrees
	
	// loops while the distance is not 0
	while (dist != 0)
	{
		// if the distance is bigger than 0, moves the robot forward
		if (dist > 0) 
		{
			drive(20); //calling drive function to drive straight
			y = y + 1;  // increments y by 1
			displayCenteredTextLine(4, "Current Position [%d,%d]", x, y);
			sleep(500);
			dist--;
		}
		
		// if distance is less than 0, moves the robot forward
		else if (dist < 0) 
		{
			drive(20); //calling drive function to drive straight
			y = y - 1;  // decrements x by 1
			displayCenteredTextLine(4, "Current Position [%d,%d]", x, y);
			sleep(500);
			dist++;
		}
	}
	
	AngleTurn(y, Y); //calling function to turn 90 degrees
	
	// stops the motors
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(2);
}