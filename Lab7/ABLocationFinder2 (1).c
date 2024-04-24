#define leftMotor 1
#define rightMotor 2

//function signatures
void get_position(int x, int y);
void drive(int speed);
void Angle_rotation(int y, int Y);
void driveToPosition(int x, int X, int y, int Y);


task main()
{
	//initializing distance to be 0
	int x = 3;
	int y = 1;
	
	
	// Display options to the user
	displayCenteredBigTextLine(4, "press up to move to");
	displayCenteredBigTextLine(6, "3,7");
	
	
	
	
	// gets the position destination
	get_position(x,y);
}


//funtion to get the destination for the robot
void get_position(int x, int y)
{	
	int getToY;
	int getX;
	
	
	//as long the enter botton not pressed 
	while (getButtonPress(buttonEnter)  == 0)
	{
		//if user presses the up button position to 4,1
		if (getButtonPress(buttonUp))
		{	
			displayCenteredBigTextLine(1, "Heading to 3,7");
			getToY = 7;
			getX = 3;
			driveToPosition(x, getX, y, getToY);     //calling funtion to move the robot to the destination
		}
		//else if user presses the down button potition to 5,6
		else if (getButtonPress(buttonDown))
		{
			displayCenteredBigTextLine(4, "invalid input");
			
		}
	}//end while loop
	
}


//function to drive forward one square
void drive(int speed)
{
	// rotates the robot's wheels 360 degrees
	setMotorSyncEncoder(leftMotor, rightMotor, 0, 330, speed);
	sleep(3000);
	
}


//function to turn an angle of 90 degrees left or right
void Angle_rotation(int y, int Y)
{	
	int Angle;
	
	
	eraseDisplay(); // Clear the display
	displayCenteredTextLine(2,"gyro resetting");
	SensorType[S2] = sensorEV3_Gyro; // set sensor to port 2
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
		setMotorSync(leftMotor, rightMotor, -10, 100); //start motor 
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


//function that drives in a square
void driveToPosition(int x, int X, int y, int Y)
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
	
	Angle_rotation(y, Y); //calling function to turn 90 degrees
	
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
	
	Angle_rotation(y, Y); //calling function to turn 90 degrees
	
	// stops the motors
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(2);
}