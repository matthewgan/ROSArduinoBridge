#ifndef CustomizedMotorDriverBoard_h
#define CustomizedMotorDriverBoard_h

#include <Arduino.h>

class CustomizedMotorDriverBoard
{
  public:  
    // CONSTRUCTORS
    CustomizedMotorDriverBoard(); // Default pin selection.
    CustomizedMotorDriverBoard(unsigned char INA1, unsigned char INB1, unsigned char PWM1, 
                               unsigned char INA2, unsigned char INB2, unsigned char PWM2); 
                               // User-defined pin selection. 
    
    // PUBLIC METHODS
    void init(); // Initialize TIMER 1, set the PWM to 20kHZ. 
    void setM1Speed(int speed); // Set speed for M1.
    void setM2Speed(int speed); // Set speed for M2.
    void setSpeeds(int m1Speed, int m2Speed); // Set speed for both M1 and M2.
    void setM1Brake(); // Brake M1. 
    void setM2Brake(); // Brake M2.
    void setBrakes(); // Brake both M1 and M2.
    
  private:
    unsigned char _INA1;
    unsigned char _INB1;
    unsigned char _PWM1;
    
    unsigned char _INA2;
    unsigned char _INB2;
    unsigned char _PWM2;
    
};

#endif