/*
Project : Automated Chocolate Wrapping Machine
Platform: Arduino Mega 2560
Language: Embedded C/C++ (Arduino)
Motor Sequence:
1. Conveyor Motor ON (2 seconds)
2. Wrapping Rollers ON (1.5 seconds)
3. Exit Conveyor ON (2 seconds)
4. Repeat
Author : Chinmay Yalawatti
Year   : 2025
==========================================================
*/
// Motor 1 - Main Conveyor
const int conveyorMotorPin1 = 10;
const int conveyorMotorPin2 = 5;

// Motor 2 - Exit Conveyor
const int exitConveyorPin1 = 11;
const int exitConveyorPin2 = 4;

// Motor 3 - Left Wrapping Roller
const int leftWrapperPin1 = 8;
const int leftWrapperPin2 = 7;

// Motor 4 - Right Wrapping Roller
const int rightWrapperPin1 = 9;
const int rightWrapperPin2 = 6;

// Setup Function

void setup()
{
  // Configure all motor control pins as OUTPUT

  pinMode(conveyorMotorPin1, OUTPUT);
  pinMode(conveyorMotorPin2, OUTPUT);

  pinMode(exitConveyorPin1, OUTPUT);
  pinMode(exitConveyorPin2, OUTPUT);

  pinMode(leftWrapperPin1, OUTPUT);
  pinMode(leftWrapperPin2, OUTPUT);

  pinMode(rightWrapperPin1, OUTPUT);
  pinMode(rightWrapperPin2, OUTPUT);

  // Ensure all motors are OFF during startup

  stopMotor(conveyorMotorPin1, conveyorMotorPin2);
  stopMotor(exitConveyorPin1, exitConveyorPin2);
  stopMotor(leftWrapperPin1, leftWrapperPin2);
  stopMotor(rightWrapperPin1, rightWrapperPin2);
}

void loop()
{
  // Step 1 : Move Chocolate on Main Conveyor
  moveMotor(conveyorMotorPin1, conveyorMotorPin2, true);

  delay(2000);

  stopMotor(conveyorMotorPin1, conveyorMotorPin2);

  // Step 2 : Rotate Wrapping Rollers
  moveMotor(leftWrapperPin1, leftWrapperPin2, true);
  moveMotor(rightWrapperPin1, rightWrapperPin2, false);
  delay(1500);
  stopMotor(leftWrapperPin1, leftWrapperPin2);
  stopMotor(rightWrapperPin1, rightWrapperPin2);

  // Step 3 : Move Wrapped Chocolate to Output
  moveMotor(exitConveyorPin1, exitConveyorPin2, true);
  delay(2000);
  stopMotor(exitConveyorPin1, exitConveyorPin2);

  // Pause Before Next Cycle

  delay(1000);
}

// Function : moveMotor()
/*
Controls the direction of a DC motor.
Parameters:
pin1    -> Motor Driver Input 1
pin2    -> Motor Driver Input 2
forward -> true  = Forward Rotation
           false = Reverse Rotation
*/

void moveMotor(int pin1, int pin2, bool forward)
{
  digitalWrite(pin1, forward ? HIGH : LOW);
  digitalWrite(pin2, forward ? LOW : HIGH);
}

// Function : stopMotor()
/*
Stops the selected DC motor.

Parameters:
pin1 -> Motor Driver Input 1
pin2 -> Motor Driver Input 2
*/

void stopMotor(int pin1, int pin2)
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}
