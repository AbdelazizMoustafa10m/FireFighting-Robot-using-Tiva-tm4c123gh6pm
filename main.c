#include"Timers.h"
#include"Delay.h"
#include"DC_Motors.h"
#include"ADC_Tm4c123.h"
#include"Flame_Detection.h"
#include"Servo.h"
#include"Ultrasonic.h"


int main(void)
{
   // Servo_Init();
    //Motors_Init();
   // FLAME_DETECT_Init();
    Ultrasonic_Init();

    GPIO_CLOCK_ENABLE(GPIOF_CLOCK);
     GPIO_DIR_SELECT(GPIOPF_APB_BASE,3,INPUT);
    GPIO_ALFUN_SETPINS(GPIOPF_APB_BASE, 3);
    GPIO_DIGITAL_ENABLE(GPIOPF_APB_BASE, 3);

  //  GPIO_DIR_SELECT(GPIOPF_APB_BASE,2,OUTPUT);
     //   GPIO_ALFUN_SETPINS(GPIOPF_APB_BASE, 2);
     //   GPIO_DIGITAL_ENABLE(GPIOPF_APB_BASE, 2);
        /*
        GPIO_DIR_SELECT(GPIOPF_APB_BASE,1,OUTPUT);
            GPIO_ALFUN_SETPINS(GPIOPF_APB_BASE, 1);
            GPIO_DIGITAL_ENABLE(GPIOPF_APB_BASE, 1);

  sint16 pos = 90;*/
    while(1)
    {



        uint32 Distance = Measure_Distance();

        if(Distance<20)
         {
              SET_PIN(GPIOPF_APB_BASE, 3);
         }
         else
         {
             CLEAR_PIN(GPIOPF_APB_BASE, 3);
          }


/*
        SET_PIN(GPIOPB_APB_BASE, 6);
        Delay_mS(500);
        CLEAR_PIN(GPIOPB_APB_BASE, 6);
        Delay_mS(500);
*/
     //  Servo_Pos(MAX_DUTY_CYCLE);
      //  Delay_uS(12000);

     /*  if(IS_PIN_CLEAR(GPIOPB_APB_BASE,5))
       {
           Servo_Pos(MIN_DUTY_CYCLE);
           Delay_mS(500);
       }
       else
       {
           Servo_Pos(_25_DUTY_CYCLE);
           Delay_mS(500);
       }*/
     //  SCAN_FOR_FIRE();
       // Servo_turn();
      //  Servo_turnss();

    }
}
