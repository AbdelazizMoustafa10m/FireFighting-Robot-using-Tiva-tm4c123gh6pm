
#include "Servo.h"
#include"Delay.h"

/**
 *  @file  <Servo.c>
 *  @brief <Implements the functions defined in the header file.>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <21-Dec-18>
 *
 */



#define OUTPUT_SET_RELOAD    (0x0000008C)

void Servo_Init(void)
{
    /* Enable the clock for PWM1 Module.*/
    REG32_ACCESS((SYSTEM_CTL_BASE),(PWM_CLK_ofsset)) |= (PWM1_CLOCK);

    GPIO_AFSEL_FOR_PWM(GPIOPF_APB_BASE, GPIOF_CLOCK, 3);

    /* Enable the clock for a general PWM Module.*/
    REG32_ACCESS((SYSTEM_CTL_BASE),(PWM_CLOCK_ofsset)) |= (PWM_CLOCK);


    /* Select the Divide value for the PWM Module clock.*/
    REG32_ACCESS((SYSTEM_CTL_BASE),(PWM_Divide_CLK_ofsset)) |= (PWM_PRE_DIV_2);

    /*Disable the Desired PWM Module before configuration.*/
    CLEAR_BIT(PWM1_BASE, PWM3_CTL_offset , PWM_ENABLE_BIT);

    REG32_ACCESS((PWM1_BASE),(PWM3_CTL_offset )) |= PWM_COUNTDOWN_MODE;

    REG32_ACCESS((PWM1_BASE),(PWM3_GENB_offset)) =  OUTPUT_SET_RELOAD;
    REG32_ACCESS((PWM1_BASE),(PWM3_LOAD_offset)) =  _50Hz_FREQ;
    REG32_ACCESS((PWM1_BASE),(PWM3_CMPA_offset)) =  MIN_DUTY_CYCLE;

    /*Start the PWM Timer*/
    SET_BIT(PWM1_BASE, PWM3_CTL_offset , PWM_ENABLE_BIT);

    PWM_ENABLE(PWM1_BASE,PWM3_GENB_ENABLE);
}

void Servo_Pos(uint32 Position)
{
    REG32_ACCESS((PWM1_BASE),(PWM3_CMPA_offset )) = Position;
}

void Servo_turn(void)
{
    uint32 i;
    REG32_ACCESS((PWM1_BASE),(PWM_EN_offset)) |= (PWM3_GENB_ENABLE);
    for(i=MIN_DUTY_CYCLE;i>=260000;i-=6400)
    {
       REG32_ACCESS((PWM1_BASE),(PWM3_CMPA_offset )) = i;
       Delay_uS(1200);
    }
    REG32_ACCESS((PWM1_BASE),(PWM_EN_offset)) &= ~(PWM3_GENB_ENABLE);
}

void Servo_turnss(void)
{
    uint32 i;
    REG32_ACCESS((PWM1_BASE),(PWM_EN_offset)) |= (PWM3_GENB_ENABLE);
    for(i=260000;i<MIN_DUTY_CYCLE;i+=6400)
    {
       REG32_ACCESS((PWM1_BASE),(PWM3_CMPA_offset )) = i;
       Delay_uS(10000);
    }
    REG32_ACCESS((PWM1_BASE),(PWM_EN_offset)) &= ~(PWM3_GENB_ENABLE);
}
