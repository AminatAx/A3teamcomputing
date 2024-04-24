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
	
	
	eraseDisplay(); // Clearing the display
	displayCenteredTextLine(2,"gyro resetting");
	SensorType[S2] = sensorEV3_Gyro; // Gyro sensor is attached to the second port
	sleep(500);
	resetGyro(S2); //reset the Gyro to get to 0 
	sleep(3);
	displayCenteredTextLine(2,"Angle =%d",getGyroDegrees(S2));
	sleep(500);
	
	
	//Turn the robot 90 degrees so it faces forward
	eraseDisplay();
	//Getting the starting angle of the robot
	Angle=getGyroDegrees(S2); 
	displayCenteredTextLine(2,"Angle =%d",Angle);
	

	// checks if the statying y position is smaller or equal to the destination y position
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
	
	//checks if the statying y position is greather than the destination y position
	else if (y > Y) 
	{
		//starting the Robot's motor
		setMotorSync(leftMotor, rightMotor, 100, -10);
		displayCenteredTextLine(4,"rotating 90");
		while (abs(Angle) < 270)
		{
			sleep(2);
			Angle=getGyroDegrees(S2);
			displayCenteredBigTextLine(5,"current angle %4d",Angle);  //displays the current angle
			
		}
		//stops the Robot's motor
		setMotorSync(leftMotor, rightMotor, 0, 0); 
		sleep(500);
	}
	//Clears the display
	eraseDisplay(); 
	
}


//function that moves the robot to the desired  X and Y location
void driveForward(int x, int X, int y, int Y)
{
	int distance = X - x;
	int dist = Y - y;
	
	// Loop starts when the distance is not equal to 0
	while (distance != 0)
	{
		// if the distance between the two points is greater then 0 robot will move forward
		if (distance > 0) 
		{
			//Drive function to move forward by one square
			drive(20);
			//Increments the x number by 1  and displays it
			x = x + 1; 
			displayCenteredTextLine(4, "Position %d,%d", x, y);
			distance--;
		}
		
		// if the distance between the two points is less then 0 robot will move forward
		else if (distance < 0) 
		{
			//Drive function to move forward by one square
			drive(20); 
			//Decrements the x number by 1and displays it
			x = x - 1; 
			displayCenteredTextLine(4, "Position %d,%d", x, y);
			distance++;
		}
	}
	//Calling the function tha tturns the robot 90 degrees left or right
	AngleTurn(y, Y); 
	
	// Loop starts when the distance is not equal to 0
	while (dist != 0)
	{
		//if the distance between the two points is greater then 0 robot will move forward
		if (dist > 0) 
		{
			//Drive function to move forward by one square
			drive(20); 
			//Increments the y number by 1 and displays it
			y = y + 1;  
			displayCenteredTextLine(4, "Position %d,%d", x, y);
			sleep(500);
			dist--;
		}
		
		// if the distance between the two points is less then 0 robot will move forward
		else if (dist < 0) 
		{
			//Drive function to move forward by one square
			drive(20); 
			//Decrements the y number by 1 and displays it
			y = y - 1;  
			displayCenteredTextLine(4, "Position %d,%d", x, y);
			sleep(500);
			dist++;
		}
	}
	//Calling the function tha tturns the robot 90 degrees left or right
	AngleTurn(y, Y); 
	
	// stops the motors
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(2);
}