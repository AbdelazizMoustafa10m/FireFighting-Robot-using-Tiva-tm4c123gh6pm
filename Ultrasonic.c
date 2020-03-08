/*
 * Ultrasonic.c
 *
 *  Created on: Dec 21, 2018
 *      Author: Abdelaziz
 */


#include"Ultrasonic.h"
#include"MACROS_TIVA.h"

/**
 *  @file  <Ultrasnoic.c>
 *  @brief <Implements the functions defined in the header file.>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <21-Dec-18>
 *
 */

const float64 PWM_Clk_Period = (1/16000000);
const uint32 MULTIPLIER = 5882; /* Derived from sound speed.*/
uint32 High_Edge;
uint32 Low_Edge;
uint32 Distance_cm;

void Ultrasonic_Init(void)
{
    Timers_Init(Timer3_BASE, Timer3_CLOCK, GPTM_CLOCK_offset,_16BIT_TIMER);
    GPIO_AFSEL_FOR_TIMERS(GPIOPB_APB_BASE,GPIOB_CLOCK, ECHO,INPUT);
    Timers_Configuration(Timer3_BASE,GPTM_B_MODE_offset,TIMERB_ENABLE_BIT, EDGE_TIMECAPATURE_UPC_T_MODE,0,TIMERB_BOTH_EDGES_CAPMODE,Match_Interrupt_DISABLE );
    /* Enable the GPIO Port used by the Trigger pin.*/
    GPIO_CLOCK_ENABLE(GPIOA_CLOCK);

    /* Configures the Pins as Output*/
    GPIO_DIR_SELECT(GPIOPA_APB_BASE,TRIGGER,OUTPUT);


}
uint32 Measure_Distance(void)
{
    CLEAR_PIN(GPIOPA_APB_BASE,TRIGGER);
    Delay_mS(12);
    SET_PIN(GPIOPA_APB_BASE,TRIGGER);
    Delay_mS(12);
    CLEAR_PIN(GPIOPA_APB_BASE,TRIGGER);

    /*Capture firstEgde i.e. rising edge*/

    SET_BIT(Timer3_BASE, GPTM_INT_CLEAR_offset , TIMERB_CAPMODE_EVENT_INTERRUPT_FLAG_BIT);/*clear timer capture flag*/

    while(IS_BIT_CLEAR(Timer3_BASE, GPTM_RAW_INT_STAT_offset, TIMERB_CAPMODE_EVENT_INTERRUPT_FLAG_BIT)){}; /*Wait till captured*/

    High_Edge = REG32_ACCESS((Timer3_BASE),( GPTM_B_offset));

    /*Capture secondEdge i.e. falling edge */

    SET_BIT(Timer3_BASE, GPTM_INT_CLEAR_offset , TIMERB_CAPMODE_EVENT_INTERRUPT_FLAG_BIT);/*clear timer capture flag*/

    while(IS_BIT_CLEAR(Timer3_BASE, GPTM_RAW_INT_STAT_offset, TIMERB_CAPMODE_EVENT_INTERRUPT_FLAG_BIT)){}; /*Wait till captured*/

    Low_Edge = REG32_ACCESS((Timer3_BASE),( GPTM_B_offset));

    uint32 Distance = Low_Edge -High_Edge;

    /* Convert Distance to centimeters.*/
    Distance_cm = (PWM_Clk_Period * (float64)MULTIPLIER * (float64)Distance);

    return Distance_cm;
}
