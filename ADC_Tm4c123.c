/*
 * ADC_Tm4c123.c
 *
 *  Created on: Dec 8, 2018
 *      Author: Abdelaziz
 */


#include"ADC_Tm4c123.h"
#include"GPIO.h"

/**
 *  @file  <ADC_Tm4c123.c>
 *  @brief <Implements the functions defined in the header file.>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <8-Dec-18>
 *
 */

void GPIO_CONFIG_FOR_ADC(GPIO_CLOCKS PORT_CLOCK, uint32 PORT_BASE, uint8 PIN_NO)
{
    /* Enable the GPIO Port used by the timer.*/
    GPIO_CLOCK_ENABLE(PORT_CLOCK);

    /* Configures the Pins as inputs*/
    GPIO_DIR_SELECT(PORT_BASE,PIN_NO,INPUT);

    /* Configure the pins to work as alternative function*/
    GPIO_ALFUN_ENABLE(PORT_BASE, PIN_NO);

    /* DISABLE The Digital function*/
    GPIO_DIGITAL_DISABLE(PORT_BASE, PIN_NO);
    /* Enable analog function.*/
    GPIO_ANALOG_ENABLE(PORT_BASE,PIN_NO);

}

void GPIO_CONFIG_FOR_FL_S(void)
{
    /* Enable the GPIO Port used by the timer.*/
    GPIO_CLOCK_ENABLE(GPIOE_CLOCK);

    /* Configures the Pins as inputs*/
    GPIO_DIR_SELECTPINS(GPIOPE_APB_BASE, 0);

    /* Configure the pins to work as alternative function*/
    GPIO_ALFUN_SETPINS(GPIOPE_APB_BASE, 0x1F);

    /* DISABLE The Digital function*/
    GPIO_DIGITAL_DISABLE_PINS(GPIOPE_APB_BASE, 0);
    /* Enable analog function.*/
    GPIO_ANALOG_ENABLE_PINS(GPIOPE_APB_BASE, 0x1F);
}

void ADC_Init(uint32 ADC_Base, ADC_Reference VRef, ADC_SAMP_SPEED Sampling_Speed)
{

    REG32_ACCESS((ADC_Base),(ADC_CTL_offset)) |=VRef;
    REG32_ACCESS((SYSTEM_CTL_BASE),(ADC_SAMP_SPEED_ofsset)) |= Sampling_Speed;
}

void ADC_S_SEQ_Config(uint32 ADC_BASE, ADC_SS_Num S_Seq_Num, ADC_Sequencer_Priority Priority,
                          ADC_EventTrigger_Source Event_source, ADC_Internal_TS_STATE TS_St,
                          ADC_Interrupt Interrupt_state, ADC_End_of_CONV Conv_end, ADC_Diffrential_SEL Diff_state)
{
    switch(S_Seq_Num)
       {
               case ADC_SS0:
                             /*Disable the sample sequencer before configuring the ADC Module.*/
                             CLEAR_BIT(ADC_BASE, ADC_ACTIVE_SS_offset, ADC_SS0_ENABLE_BIT);
                             REG32_ACCESS((ADC_BASE),(ADC_SS_PRI_offset)) |= Priority;
                             REG32_ACCESS((ADC_BASE),(ADC_EVENT_SEL_offset)) |= Event_source;
                             REG32_ACCESS((ADC_BASE),(ADC_SS0_CTL_offset)) |= TS_St |Interrupt_state |Conv_end |Diff_state;
                             SET_BIT(ADC_BASE,ADC_INT_MASK,ADC_SS0_INTERRUPT_FLAG_BIT);
                             /* Enable ADC unit by setting the ASEN0 bit.*/
                             SET_BIT(ADC_BASE, ADC_ACTIVE_SS_offset, ADC_SS0_ENABLE_BIT);
                             break;

               case ADC_SS1:
                             /*Disable the sample sequencer before configuring the ADC Module.*/
                             CLEAR_BIT(ADC_BASE, ADC_ACTIVE_SS_offset, ADC_SS1_ENABLE_BIT);
                             REG32_ACCESS((ADC_BASE),(ADC_SS_PRI_offset)) |= Priority;
                             REG32_ACCESS((ADC_BASE),(ADC_EVENT_SEL_offset)) |= (4<<Event_source);
                             REG32_ACCESS((ADC_BASE),(ADC_SS1_CTL_offset)) |= TS_St |Interrupt_state |Conv_end |Diff_state;
                             SET_BIT(ADC_BASE,ADC_INT_MASK,ADC_SS1_INTERRUPT_FLAG_BIT);
                             /* Enable ADC unit by setting the ASEN1 bit.*/
                             SET_BIT(ADC_BASE, ADC_ACTIVE_SS_offset, ADC_SS1_ENABLE_BIT);
                             break;
               case ADC_SS2:
                             /*Disable the sample sequencer before configuring the ADC Module.*/
                             CLEAR_BIT(ADC_BASE, ADC_ACTIVE_SS_offset, ADC_SS2_ENABLE_BIT);
                             REG32_ACCESS((ADC_BASE),(ADC_SS_PRI_offset)) |= Priority;
                             REG32_ACCESS((ADC_BASE),(ADC_EVENT_SEL_offset)) |= (8<<Event_source);
                             REG32_ACCESS((ADC_BASE),(ADC_SS2_CTL_offset)) |= TS_St |Interrupt_state |Conv_end |Diff_state;
                             SET_BIT(ADC_BASE,ADC_INT_MASK,ADC_SS2_INTERRUPT_FLAG_BIT);
                             /* Enable ADC unit by setting the ASEN2 bit.*/
                             SET_BIT(ADC_BASE, ADC_ACTIVE_SS_offset, ADC_SS2_ENABLE_BIT);
                             break;
               case ADC_SS3:
                             /*Disable the sample sequencer before configuring the ADC Module.*/
                             CLEAR_BIT(ADC_BASE, ADC_ACTIVE_SS_offset, ADC_SS3_ENABLE_BIT);
                             REG32_ACCESS((ADC_BASE),(ADC_SS_PRI_offset)) |= Priority;
                             REG32_ACCESS((ADC_BASE),(ADC_EVENT_SEL_offset)) |= (12<<Event_source);
                             REG32_ACCESS((ADC_BASE),(ADC_SS3_CTL_offset)) |= TS_St |Interrupt_state |Conv_end |Diff_state;

                             /* Enable ADC unit by setting the ASEN0 bit.*/
                             SET_BIT(ADC_BASE, ADC_ACTIVE_SS_offset, ADC_SS3_ENABLE_BIT);

                             break;
               default:
                             break;
       }







}

uint16 ADC_Read(uint32 ADC_BASE, ADC_Channel Channel, ADC_SS_Num S_Seq_Num)
{
    uint32 Result = 0;

    switch(S_Seq_Num)
    {
            case ADC_SS0:
                          REG32_ACCESS((ADC_BASE),(ADC_SS0_MUX_offset)) |= 0x00000000;
                          /* Select The Channel*/
                          REG32_ACCESS((ADC_BASE),(ADC_SS0_MUX_offset)) |= Channel;
                          /*Initiate SS3 the sample sequencer0.*/
                          SET_BIT(ADC_BASE, ADC_Pro_SS_init_offset, ADC_SS0_START_SAMPLE);
                          while(IS_BIT_CLEAR(ADC_BASE,ADC_RAW_INT_STAT_offset,ADC_SS0_INTERRUPT_FLAG_BIT))
                           {
                                    /* DO Nothing.*/
                           }
                           /*Read the result of conversion.*/
                           Result = (REG32_ACCESS((ADC_BASE),(ADC_SS0_RESULT_offset)) & ADC_READ_RESULT_CODE);
                           /* Acknowledge completion of conversion.*/
                           SET_BIT(ADC_BASE,ADC_INT_STAT_CLEAR_offset,ADC_SS0_INTERRUPT_FLAG_BIT);
                           return Result;


            case ADC_SS1:
                           REG32_ACCESS((ADC_BASE),(ADC_SS1_MUX_offset)) |= 0x00000000;
                           /* Select The Channel*/
                           REG32_ACCESS((ADC_BASE),(ADC_SS1_MUX_offset)) |= Channel;
                           /*Initiate SS3 the sample sequencer0.*/
                           SET_BIT(ADC_BASE, ADC_Pro_SS_init_offset, ADC_SS1_START_SAMPLE);
                           while(IS_BIT_CLEAR(ADC_BASE,ADC_RAW_INT_STAT_offset,ADC_SS1_INTERRUPT_FLAG_BIT))
                           {
                                   /* DO Nothing.*/
                           }
                           /*Read the result of conversion.*/
                           Result = (REG32_ACCESS((ADC_BASE),(ADC_SS1_RESULT_offset)) & ADC_READ_RESULT_CODE);
                           /* Acknowledge completion of conversion.*/
                           SET_BIT(ADC_BASE,ADC_INT_STAT_CLEAR_offset,ADC_SS1_INTERRUPT_FLAG_BIT);
                           return Result;


            case ADC_SS2:
                          REG32_ACCESS((ADC_BASE),(ADC_SS2_MUX_offset)) |= 0x00000000;
                          /* Select The Channel*/
                          REG32_ACCESS((ADC_BASE),(ADC_SS2_MUX_offset)) |= Channel;
                          /*Initiate SS3 the sample sequencer0.*/
                          SET_BIT(ADC_BASE, ADC_Pro_SS_init_offset, ADC_SS2_START_SAMPLE);
                          while(IS_BIT_CLEAR(ADC_BASE,ADC_RAW_INT_STAT_offset,ADC_SS2_INTERRUPT_FLAG_BIT))
                          {
                                     /* DO Nothing.*/
                          }
                          /*Read the result of conversion.*/
                          Result = (REG32_ACCESS((ADC_BASE),(ADC_SS2_RESULT_offset)) & ADC_READ_RESULT_CODE);
                          /* Acknowledge completion of conversion.*/
                          SET_BIT(ADC_BASE,ADC_INT_STAT_CLEAR_offset,ADC_SS2_INTERRUPT_FLAG_BIT);
                          return Result;


            case ADC_SS3:
                          REG32_ACCESS((ADC_BASE),(ADC_SS3_MUX_offset)) |= 0x00000000;
                          /* Select The Channel*/
                          REG32_ACCESS((ADC_BASE),(ADC_SS3_MUX_offset)) |= Channel;
                          /*Initiate SS3 the sample sequencer0.*/
                          SET_BIT(ADC_BASE, ADC_Pro_SS_init_offset, ADC_SS3_START_SAMPLE);
                          while(IS_BIT_CLEAR(ADC_BASE,ADC_RAW_INT_STAT_offset,ADC_SS3_INTERRUPT_FLAG_BIT))
                          {
                                    /* DO Nothing.*/
                          }
                          /*Read the result of conversion.*/
                          Result = (REG32_ACCESS((ADC_BASE),(ADC_SS3_RESULT_offset)) & ADC_READ_RESULT_CODE);
                          /* Acknowledge completion of conversion.*/
                          SET_BIT(ADC_BASE,ADC_INT_STAT_CLEAR_offset,ADC_SS3_INTERRUPT_FLAG_BIT);
                          return Result;


            default:
                          break;
    }


    return 0;
}

