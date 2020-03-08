/*
 * Flame_Detection.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Abdelaziz
 */

#include"Flame_Detection.h"
#include"DC_Motors.h"
#include"Delay.h"

/**
 *  @file  <Flame_Detection.c>
 *  @brief <Implements the functions defined in the header file.>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <22-Dec-18>
 *
 */

void FLAME_DETECT_Init(void)
{
    /* ADC Initiation for the center flame sensor that will determine the stop distance.*/
    ADC_CLOCK_ENABLE(ADC0_CLOCK);
    ADC_Init(ADC0_BASE, ADC_REF_INT, _125K_ADC0_SS);
    GPIO_CONFIG_FOR_FL_S();
    ADC_S_SEQ_Config(ADC0_BASE, ADC_SS3, ADC_SS3_Highest_PRI, ADC_TRIGGER_PROCESSOR,
                     INT_TEMP_SENSOR_DISABLE,INTERRUPT_ENABLE, LAST_SAMPLE, ADC_DIFF_INPUT_DISABLE);


    /* Digital initiation for the other four Flame Sensors.*/
    GPIO_DIR_SELECTPINS(GPIOPE_APB_BASE,0);
    GPIO_ALFUN_SETPINS(GPIOPE_APB_BASE,0x01);
    GPIO_DIGITAL_ENABLE_PINS(GPIOPE_APB_BASE,0x1E);

}

void SCAN_FOR_FIRE(void)
{

    uint32 Center_Value = ADC_Read(ADC0_BASE,ADC_CH3_AIN3_PE0,ADC_SS3);

    /* No Sensor reads a fire*/
    if (IS_PIN_SET(GPIOPE_APB_BASE,RIGHT_F_SENSOR)&&IS_PIN_SET(GPIOPE_APB_BASE,LEFT_F_SENSOR)&&(Center_Value>3900))
    {
        STOP();
        Servo_Pos(MIN_DUTY_CYCLE);
        Delay_mS(500);
    }
    /*Left sensor reads fire*/
    else if(IS_PIN_CLEAR(GPIOPE_APB_BASE,LEFT_F_SENSOR))
    {
        TURN_LEFT();
        Servo_Pos(MIN_DUTY_CYCLE);
        Delay_mS(500);
    }

    /*Right sensor reads fire*/
    else if(IS_PIN_CLEAR(GPIOPE_APB_BASE,RIGHT_F_SENSOR))
    {
        TURN_RIGHT();
        Servo_Pos(MIN_DUTY_CYCLE);
        Delay_mS(500);
    }

    /*center sensor, center Left sensor and center Right sensor read fire*/
    else if((Center_Value<3900))
    {
        MOVE_FORWARD();

        if(Center_Value<1500)
            {
                STOP();
                /* Deploy Extinguisher.*/
                Servo_Pos(_25_DUTY_CYCLE);
                Delay_mS(500);
            }
    }




}
