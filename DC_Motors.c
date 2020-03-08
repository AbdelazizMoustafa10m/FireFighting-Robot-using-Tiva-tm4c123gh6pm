/*
 * DC_Motors.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Abdelaziz
 */

#include"DC_Motors.h"
/**
 *  @file  <DC_Motors.c>
 *  @brief <Implements the functions defined in the header file.>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <12-Dec-18>
 *
 */

void Motors_Init(void)
{
    /* DC Motor 1 Initialization using timer0 A in PWM Mode with 1 KHZ Frequency.*/

    Timers_Init(Timer0_BASE,Timer0_CLOCK,GPTM_CLOCK_offset,_16BIT_TIMER);
    GPIO_AFSEL_FOR_TIMERS(GPIOPB_APB_BASE, GPIOB_CLOCK, L_MOTOR_PIN, OUTPUT);
    Timers_Configuration(Timer0_BASE,GPTM_A_MODE_offset,TIMERA_ENABLE_BIT,PWM_PER_T_MODE,_1KHZ_FREQ,TIMERA_PWM_NONINVERTED,CAP_EVENT_Interrupt_ENABLE);
    Timers_ENABLE(Timer0_BASE,TIMERA_ENABLE_BIT);

    /* DC Motor 2 Initialization using timer0 B in PWM Mode with 1 KHZ Frequency.*/

    GPIO_AFSEL_FOR_TIMERS(GPIOPB_APB_BASE, GPIOB_CLOCK, R_MOTOR_PIN, OUTPUT);
    Timers_Configuration(Timer0_BASE,GPTM_B_MODE_offset,TIMERB_ENABLE_BIT,PWM_PER_T_MODE,_1KHZ_FREQ,TIMERB_PWM_NONINVERTED,CAP_EVENT_Interrupt_ENABLE);
    Timers_ENABLE(Timer0_BASE,TIMERB_ENABLE_BIT);
}

void MOVE_FORWARD(void)
{
    SET_PWM(Timer0_BASE,GPTM_A_MODE_offset, _1KHZ_FREQ, 30);
    SET_PWM(Timer0_BASE,GPTM_B_MODE_offset, _1KHZ_FREQ, 30);
}

void STOP(void)
{
    SET_PWM(Timer0_BASE,GPTM_A_MODE_offset, _1KHZ_FREQ, 1);
    SET_PWM(Timer0_BASE,GPTM_B_MODE_offset, _1KHZ_FREQ, 1);
}

void TURN_RIGHT(void)
{
    SET_PWM(Timer0_BASE,GPTM_A_MODE_offset, _1KHZ_FREQ, 5);
    SET_PWM(Timer0_BASE,GPTM_B_MODE_offset, _1KHZ_FREQ, 25);
}

void TURN_LEFT(void)
{
    SET_PWM(Timer0_BASE,GPTM_A_MODE_offset, _1KHZ_FREQ, 25);
    SET_PWM(Timer0_BASE,GPTM_B_MODE_offset, _1KHZ_FREQ, 5);
}
