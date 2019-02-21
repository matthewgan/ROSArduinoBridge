#include "CustomizedMotorDriverBoard.h"

// Constructors ////////////////////////////////////////////////////////////////

CustomizedMotorDriverBoard::CustomizedMotorDriverBoard()
{
  //Pin map
  _PWM1 = 6;
  _INA1 = 7;
  _INB1 = 8;
  
  _PWM2 = 9;
  _INA2 = 11;
  _INB2 = 10;
  
}

CustomizedMotorDriverBoard::CustomizedMotorDriverBoard(unsigned char INA1, unsigned char INB1, unsigned char PWM1, 
                                                       unsigned char INA2, unsigned char INB2, unsigned char PWM2)
{
  //Pin map
  _INA1 = INA1;
  _INB1 = INB1;
  _PWM1 = PWM1;
  
  _INA2 = INA2;
  _INB2 = INB2;
  _PWM2 = PWM2;
}

// Public Methods //////////////////////////////////////////////////////////////
void CustomizedMotorDriverBoard::init()
{
// Define pinMode for the pins and set the frequency for timer1.

  pinMode(_INA1,OUTPUT);
  pinMode(_INB1,OUTPUT);
  pinMode(_PWM1,OUTPUT);

  pinMode(_INA2,OUTPUT);
  pinMode(_INB2,OUTPUT);
  pinMode(_PWM2,OUTPUT);
  
}
// Set speed for motor 1, speed is a number betwenn -400 and 400
void CustomizedMotorDriverBoard::setM1Speed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;
  
  analogWrite(_PWM1,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
  
  if (speed == 0)
  {
    digitalWrite(_INA1,LOW);   // Make the motor coast no
    digitalWrite(_INB1,LOW);   // matter which direction it is spinning.
  }
  else if (reverse)
  {
    digitalWrite(_INA1,LOW);
    digitalWrite(_INB1,HIGH);
  }
  else
  {
    digitalWrite(_INA1,HIGH);
    digitalWrite(_INB1,LOW);
  }
}

// Set speed for motor 2, speed is a number betwenn -400 and 400
void CustomizedMotorDriverBoard::setM2Speed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // make speed a positive quantity
    reverse = 1;  // preserve the direction
  }
  if (speed > 400)  // Max 
    speed = 400;

  analogWrite(_PWM2,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
   
  if (speed == 0)
  {
    digitalWrite(_INA2,LOW);   // Make the motor coast no
    digitalWrite(_INB2,LOW);   // matter which direction it is spinning.
  }
  else if (reverse)
  {
    digitalWrite(_INA2,LOW);
    digitalWrite(_INB2,HIGH);
  }
  else
  {
    digitalWrite(_INA2,HIGH);
    digitalWrite(_INB2,LOW);
  }
}

// Set speed for motor 1 and 2
void CustomizedMotorDriverBoard::setSpeeds(int m1Speed, int m2Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}

// Brake motor 1, brake is a number between 0 and 400
void CustomizedMotorDriverBoard::setM1Brake()
{
  digitalWrite(_INA1, LOW);
  digitalWrite(_INB1, LOW);
}

// Brake motor 2, brake is a number between 0 and 400
void CustomizedMotorDriverBoard::setM2Brake()
{
  digitalWrite(_INA2, LOW);
  digitalWrite(_INB2, LOW);
}

// Brake motor 1 and 2, brake is a number between 0 and 400
void CustomizedMotorDriverBoard::setBrakes()
{
  setM1Brake();
  setM2Brake();
}
