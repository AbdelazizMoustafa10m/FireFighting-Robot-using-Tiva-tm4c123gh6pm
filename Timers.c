/*
 * Timers.c
 *
 *  Created on: Dec 12, 2018
 *      Author: Abdelaziz
 */

#include"Timers.h"

/**
 *  @file  <Timers.c>
 *  @brief <Implements the functions defined in the header file.>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <12-Dec-18>
 *
 */


void Timers_Init(uint32 Timer_Base, Timer_CLOCKS Clock, uint32 Timer_Clock_Offset, Timer_Size Size)
{
    /* Enable the clock for a certain Timer Module.*/
    REG32_ACCESS((SYSTEM_CTL_BASE),(Timer_Clock_Offset)) |= (Clock);

    /* Select the size for a certain Timer Module.*/
    REG32_ACCESS((Timer_Base),(GPTM_CONFIG_offset )) |= (Size);
}

void GPIO_AFSEL_FOR_TIMERS(uint32 PORT_BASE, GPIO_CLOCKS PORT_CLOCK, uint8 PIN_NO, DIO_MODE direction)
{
    /* Enable the GPIO Port used by the timer.*/
    GPIO_CLOCK_ENABLE(PORT_CLOCK);

    /* Configures the Pins as inputs*/
    GPIO_DIR_SELECT(PORT_BASE,PIN_NO,direction);

    /* Enable The Digital function*/
    GPIO_DIGITAL_ENABLE(PORT_BASE, PIN_NO);

    /* Configure the pins to work as alternative function*/
    GPIO_ALFUN_ENABLE(PORT_BASE, PIN_NO);

    /* Selects the QEI alternative function for the PhA, PhB  GPIO pins.*/
    GPIO_ALF_CONTROL(PORT_BASE,GPIO_PORT_CTL_offset,PIN_NO,TIMERS_Digital_Code);
}

void Timers_Configuration(uint32 Timer_Base, uint32 Timer_n_Mode_Offset, uint8 Timer_Enable_BIT,Timer_Modes Mode,
                              uint32 Count_Value, Timer_CAP_EVENTS Cap_Event, Timer_Interrupt_State Int_state)
{
    /*Disable the Desired Timer Module before configuration.*/
    CLEAR_BIT(Timer_Base, GPTM_CTL_offset , Timer_Enable_BIT);
    REG32_ACCESS((Timer_Base),(Timer_n_Mode_Offset )) |= Mode |Int_state;

    switch(Timer_n_Mode_Offset)
    {
       case GPTM_A_MODE_offset :
                                  /* Load the Value that the timer will count up to or down from.*/
                                  REG32_ACCESS((Timer_Base),(GPTM_A_I_LOAD_offset)) = (Count_Value);
                                  break;
       case GPTM_B_MODE_offset :
                                  /* Load the Value that the timer will count up to or down from.*/
                                  REG32_ACCESS((Timer_Base),(GPTM_B_I_LOAD_offset)) = (Count_Value-1);
                                  break;
       default:
                                  break;
    }

    REG32_ACCESS((Timer_Base),(GPTM_CTL_offset )) |= Cap_Event;

}

void SET_PWM(uint32 Timer_Base, uint32 Timer_n_Mode_Offset, float32 Frequency, float32 Duty_Cycle)
{

   uint32 PWM_Match = (uint32) (((100-Duty_Cycle)/100) * Frequency);

    switch(Timer_n_Mode_Offset)
    {
       case GPTM_A_MODE_offset :
                                  /* Load the Value that the timer will count up to or down from.*/
                                  REG32_ACCESS((Timer_Base),(GPTM_A_I_LOAD_offset)) = Frequency-1;
                                  REG32_ACCESS((Timer_Base),(GPTM_A_MATCH_offset )) = PWM_Match-1;
                                  break;
       case GPTM_B_MODE_offset :
                                  /* Load the Value that the timer will count up to or down from.*/
                                  REG32_ACCESS((Timer_Base),(GPTM_B_I_LOAD_offset)) = Frequency-1;
                                  REG32_ACCESS((Timer_Base),(GPTM_B_MATCH_offset )) = PWM_Match-1;
                                  break;
       default:
                                  break;
    }
}
