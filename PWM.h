/*
 * PWM.h
 *
 *  Created on: Dec 12, 2018
 *      Author: Abdelaziz
 */


#ifndef PWM_H_
#define PWM_H_

#include"Micro_Config_Tiva.h"
#include"MACROS_TIVA.h"
#include"GPIO.h"

/**
 *  @file  <PWM.h>
 *  @brief <Header File of The PWM Module of the Tm4c123 controller.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <21-Dec-18>
 *
 */


  /* The following group of definitions represent the Bit Numbers in PWMnCTL Register in Tm4c123.*/
  #define PWM_ENABLE_BIT                           (0)          /* ENABLE */

  /* This Macro Defines the digital code encoded in GPIOCTL Register to select the PWM Alternative Function*/
  #define PWM0_Digital_Code                         (4)
  #define PWM1_Digital_Code                         (5)

  /* This Macro Defines the Clock Code for the PWM Module.*/
  #define PWM_CLOCK                                (0x00100000)


  typedef enum
  {
      PWM0_CLOCK = 0x00000001,
      PWM1_CLOCK = 0x00000002,
  }PWM_CLOCKS;

  /* This Enumeration Selects the PWM predevide value  for each PWM Module*/
  typedef enum
  {
      PWM_PRE_DIV_2      =      0x00000000,     PWM_PRE_DIV_4       =      0x00120000,
      PWM_PRE_DIV_8      =      0x00140000,     PWM_PRE_DIV_16      =      0x00160000,
      PWM_PRE_DIV_32     =      0x00180000,     PWM_PRE_DIV_64      =      0x001A0000,

  }PWM_PreDivide;

    /* This Enumeration has the enable codes for each PWM channel in the PWM Module*/
    typedef enum
    {
      PWM0_GENA_ENABLE      =      0x01,          PWM0_GENB_ENABLE         =     0x02,
      PWM1_GENA_ENABLE      =      0x04,          PWM1_GENB_ENABLE         =     0x08,
      PWM2_GENA_ENABLE      =      0x10,          PWM2_GENB_ENABLE         =     0x20,
      PWM3_GENA_ENABLE      =      0x40,          PWM3_GENB_ENABLE         =     0x80,

    }PWM_Enable;

    /* This Enumeration has the Operating Modes for each Timer in the Timers Module*/
    typedef enum
    {
      PWM_COUNTDOWN_MODE = 0x00000000,      PWM_COUNT_UP_DOWN_MODE  = 0x00000002,

    }PWM_Modes;


    /* This Macro is Used to enable the desired Timer Module*/
    #define PWM_ENABLE(PWM_BASE,PWM_Enable) do{ REG32_ACCESS((PWM_BASE),(PWM_EN_offset)) |= (PWM_Enable);}while(0)

    /**
     *  @brief < void GPIO_AFSEL_FOR_QEI(uint32 PORT_BASE, GPIO_CLOCKS PORT_CLOCK, uint8 PIN_NO, DIO_MODE direction)>
     *  <This function will be used to Select the QEI alternative function for .>
     *
     *  @param uint32        <PORT_BASE>            <The Base Address of the desired GPIO.>
     *  @param GPIO_CLOCKS   <PORT_CLOCK>           <The Clock code for the desired GPIO PORT used by the PWM Module.>
     *  @param uint8         <PIN_NO>               <GPIO PIN number used for the PWM Module.>
     *
     *  @return <This Function Returns Void.>
     *
     */
    void GPIO_AFSEL_FOR_PWM(uint32 PORT_BASE, GPIO_CLOCKS PORT_CLOCK, uint8 PIN_NO);

    /**
     *  @brief void PWM_Configuration(uint32 PWM_Base, uint32 PWM_No_CTL_Offset, PWM_Modes Mode, PWM_PreDevide Div_Value
                           uint32 Load_Value, uint32 GEN_ACT_Value, uint32 Compare_Value).>
     *
     *  @param uint32          <PWM_Base>            <The Base Address of the desired PWM Module.>
     *  @param uint32          <PWM_No_REG_Offset>   <The address of the offset register for the desired PWM, PWMnCTL.>
     *  @param PWM_Modes       <Mode>                <The Mode of operation of the desired PWM.i.e Down or UP/DOWN.>
     *  @param PWM_PreDevide   <Div_Value>           <The Pre-divide value for the PWM Clock .>
     *  @param uint32          <Count_Value>         <The value that the PWM timer will count up to or down from.>
     *  @param uint32          <GEN_ACT_Value>       <The Generation action value for the PWM Timer.>
     *  @param uint32          <Compare_Value>       <The Compare Value as the minimum Duty cycle.>
     *
     *  @return <This Function Returns Void.>
     *
     */
    void PWM_Configuration(uint32 PWM_Base, uint32 PWM_No_CTL_Offset, PWM_Modes Mode, PWM_PreDivide Div_Value,
                           uint32 Load_Value, uint32 GEN_ACT_Value, uint32 Compare_Value);

    /**
     *  @brief <  SET_PWM(uint32 PWM_Base, uint32 PWM_CMP_REG_Offset, float32 Load_Value, float32 Duty_Cycle)>
     *  <This function will be used to generate a PWM of a desired frequency and duty cycle from the timer module.>
     *
     *  @param uint32      <PWM_Base>             <The Base Address of the desired PWM Module.>
     *  @param uint32      <PWM_CMP_REG_Offset>   <The address of the offset register for the desired PWM.>
     *  @param float32     <Load_Value>           <The desired PWM load value for the Timer.>
     *  @param float32     <Duty_Cycle>           <The desired PWM Duty cycle that will determine the match value for the Timer.>
     *
     *  @return <This Function Returns Void.>
     *
     */
    void EN_PWM(uint32 PWM_Base, uint32 PWM_CMP_REG_Offset, float32 Load_Value, float32 Duty_Cycle);


#endif /* PWM_H_ */
