#include"Timers.h"
#include"Delay.h"
#include"DC_Motors.h"
#include"ADC_Tm4c123.h"
#include"Flame_Detection.h"
#include"Servo.h"
#include"Ultrasonic.h"


int main(void)
{
    Servo_Init();
    Motors_Init();
    FLAME_DETECT_Init();
    Ultrasonic_Init();

    while(1)
    {
		SCAN_FOR_FIRE();
    }
}
