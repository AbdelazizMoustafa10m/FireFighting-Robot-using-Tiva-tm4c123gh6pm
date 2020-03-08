/*
 * PWM.c
 *
 *  Created on: Dec 21, 2018
 *      Author: Abdelaziz
 */

#include"PWM.h"

/**
 *  @file  <PWM.c>
 *  @brief <Implements the functions defined in the header file.>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <21-Dec-18>
 *
 */

void GPIO_AFSEL_FOR_PWM(uint32 PORT_BASE, GPIO_CLOCKS PORT_CLOCK, uint8 PIN_NO)
{
       /* Enable the GPIO Port used by the PWM.*/
       GPIO_CLOCK_ENABLE(PORT_CLOCK);

       /* Configures the Pins as Output*/
       GPIO_DIR_SELECT(PORT_BASE,PIN_NO,OUTPUT);

       /* Enable The Digital function*/
       GPIO_DIGITAL_ENABLE(PORT_BASE, PIN_NO);

       /* Configure the pins to work as alternative function*/
       GPIO_ALFUN_ENABLE(PORT_BASE, PIN_NO);

       /* Selects the QEI alternative function for the PhA, PhB  GPIO pins.*/
       GPIO_ALF_CONTROL(PORT_BASE,GPIO_PORT_CTL_offset,PIN_NO,PWM1_Digital_Code);

}

void PWM_Configuration(uint32 PWM_Base, uint32 PWM_No_CTL_Offset, PWM_Modes Mode, PWM_PreDivide Div_Value,
                       uint32 Load_Value, uint32 GEN_ACT_Value, uint32 Compare_Value)
{
      /* Enable the clock for a certain PWM Module.*/
      REG32_ACCESS((SYSTEM_CTL_BASE),(PWM_CLOCK_ofsset)) |= (PWM_CLOCK);

      /* Select the Divide value for the PWM Module clock.*/
      REG32_ACCESS((SYSTEM_CTL_BASE),(PWM_Divide_CLK_ofsset)) |= (Div_Value);

      /*Disable the Desired PWM Module before configuration.*/
      CLEAR_BIT(PWM_Base, PWM_No_CTL_Offset , PWM_ENABLE_BIT);
      REG32_ACCESS((PWM_Base),(PWM_No_CTL_Offset )) |= Mode;

      switch(PWM_No_CTL_Offset)
      {
        case PWM0_CTL_offset :
                                      /* Load the Value that the timer will count up to or down from.*/
                                      REG32_ACCESS((PWM_Base),(PWM0_LOAD_offset)) =  Load_Value;
                                      REG32_ACCESS((PWM_Base),(PWM0_GENB_offset)) =  GEN_ACT_Value;
                                      REG32_ACCESS((PWM_Base),(PWM0_CMPA_offset)) =  Compare_Value;
                                      break;
        case PWM1_CTL_offset :
                                      /* Load the Value that the timer will count up to or down from.*/
                                      REG32_ACCESS((PWM_Base),(PWM1_LOAD_offset)) = Load_Value;
                                      REG32_ACCESS((PWM_Base),(PWM1_GENA_offset)) = GEN_ACT_Value;
                                      REG32_ACCESS((PWM_Base),(PWM1_CMPA_offset)) = Compare_Value;
                                      break;

        case PWM2_CTL_offset :
                                      /* Load the Value that the timer will count up to or down from.*/
                                      REG32_ACCESS((PWM_Base),(PWM2_LOAD_offset)) = Load_Value;
                                      REG32_ACCESS((PWM_Base),(PWM2_GENA_offset)) = GEN_ACT_Value;
                                      REG32_ACCESS((PWM_Base),(PWM2_CMPA_offset)) = Compare_Value;
                                      break;

        case PWM3_CTL_offset :
                                      /* Load the Value that the timer will count up to or down from.*/
                                      REG32_ACCESS((PWM_Base),(PWM3_LOAD_offset)) = Load_Value;
                                      REG32_ACCESS((PWM_Base),(PWM3_GENA_offset)) = GEN_ACT_Value;
                                      REG32_ACCESS((PWM_Base),(PWM3_CMPA_offset)) = Compare_Value;

                                      break;
        default:
                                      break;
    }

    /*Start the PWM Timer*/
    SET_BIT(PWM_Base, PWM_No_CTL_Offset , PWM_ENABLE_BIT);

}

void EN_PWM(uint32 PWM_Base, uint32 PWM_CMP_REG_Offset, float32 Load_Value, float32 Duty_Cycle)
{
    uint32 PWM_Match = (uint32) (((100-Duty_Cycle)/100) * Load_Value);

    REG32_ACCESS((PWM_Base),(PWM_CMP_REG_Offset )) = PWM_Match;

}
