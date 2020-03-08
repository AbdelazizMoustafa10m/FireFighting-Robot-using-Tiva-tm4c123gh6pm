/*
 * Delay.c
 *
 *  Created on: Dec 12, 2018
 *      Author: Abdelaziz
 */

#include"Delay.h"
#include"MACROS_TIVA.h"

/**
 *  @file  <Delay.c>
 *  @brief <Implements the functions defined in the header file.>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <12-Dec-18>
 *
 */

void Delay_uS(uint32 Time)
{
    uint32 Counter;

    Timers_Init(Timer5_BASE, Timer5_CLOCK, GPTM_CLOCK_offset,_16BIT_TIMER);
    Timers_Configuration(Timer5_BASE,GPTM_A_MODE_offset,TIMERA_ENABLE_BIT,PERIODIC_DOWNC_T_MODE,16,NO_CAP_NO_PWM_MODE,Match_Interrupt_DISABLE );
    Timers_ENABLE(Timer5_BASE,TIMERA_ENABLE_BIT);

    for(Counter=0;Counter<Time;Counter++)
    {
        while(IS_BIT_CLEAR(Timer5_BASE,GPTM_RAW_INT_STAT_offset,TIMERA_TIME_OUT_INTERRUPT_FLAG_BIT));
        /*Acknowledge that the timer has timed out.*/
        SET_BIT(Timer5_BASE,GPTM_INT_CLEAR_offset,TIMERA_TIME_OUT_INTERRUPT_FLAG_BIT);
    }
}

void Delay_mS(uint32 Time)
{
    uint32 Counter;

    Timers_Init(Timer4_BASE, Timer4_CLOCK, GPTM_CLOCK_offset,_32BIT_TIMER);
    Timers_Configuration(Timer4_BASE,GPTM_A_MODE_offset,TIMERA_ENABLE_BIT,PERIODIC_DOWNC_T_MODE,16000,NO_CAP_NO_PWM_MODE,Match_Interrupt_DISABLE );
    Timers_ENABLE(Timer4_BASE,TIMERA_ENABLE_BIT);

    for(Counter=0;Counter<(Time*1000);Counter++)
    {
        if(IS_BIT_SET(Timer4_BASE,GPTM_RAW_INT_STAT_offset,TIMERA_TIME_OUT_INTERRUPT_FLAG_BIT))
        {
           /*Acknowledge that the timer has timed out.*/
           SET_BIT(Timer4_BASE, GPTM_INT_CLEAR_offset ,TIMERA_TIME_OUT_INTERRUPT_FLAG_BIT);
        }
    }
}
void Delay(uint32 Time)
{
    uint32 i,j;
    i=0;
    j=0;
    while(i<Time)
    {
        while(j<3180)
        {
            j++;
        }
        i++;
    }
}

