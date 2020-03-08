/*
 * ADC_Tm4c123.h
 *
 *  Created on: Dec 7, 2018
 *      Author: Abdelaziz
 */

#ifndef ADC_TM4C123_H_
#define ADC_TM4C123_H_

#include"Micro_Config_Tiva.h"
#include"MACROS_TIVA.h"
#include"GPIO.h"
#include"STD_TYPES.h"


 /**
 *  @file  <ADC_Tm4c123.h>
 *  @brief <Header File of The Tm4c123 ADC library.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <7-Dec-18>
 *
 */

  /* The following group of definitions represent the Bit Numbers in ADCACTSS Register in Tm4c123.*/
  #define ADC_SS0_ENABLE_BIT                  (0)          /* ASEN0 */
  #define ADC_SS1_ENABLE_BIT                  (1)          /* ASEN1 */
  #define ADC_SS2_ENABLE_BIT                  (2)          /* ASEN2 */
  #define ADC_SS3_ENABLE_BIT                  (3)          /* ASEN3 */

  /* The following group of definitions represent the Bit Numbers in ADCRIS/ADCISC Register in Tm4c123.*/
  #define ADC_SS0_INTERRUPT_FLAG_BIT          (0)          /* INR0 */
  #define ADC_SS1_INTERRUPT_FLAG_BIT          (1)          /* INR1 */
  #define ADC_SS2_INTERRUPT_FLAG_BIT          (2)          /* INR2 */
  #define ADC_SS3_INTERRUPT_FLAG_BIT          (3)          /* INR3 */

  /* The following group of definitions represent the Bit Numbers in ADCPSSI Register in Tm4c123.*/
  #define ADC_SS0_START_SAMPLE                (0)          /* SS0 */
  #define ADC_SS1_START_SAMPLE                (1)          /* SS1 */
  #define ADC_SS2_START_SAMPLE                (2)          /* SS2 */
  #define ADC_SS3_START_SAMPLE                (3)          /* SS3 */

  #define ADC_READ_RESULT_CODE                (0xFFF)

  /* This Enumeration has the clock codes for each ADC Module*/
  typedef enum
  {
      ADC0_CLOCK = 0x00010000,
      ADC1_CLOCK = 0x00020000,
  }ADC_CLOCKS;

  /* The following Enumeration Selects the Sampling Speed of the ADC Modules.*/
  typedef enum {_125K_ADC0_SS = 0x00000000, _250K_ADC0_SS = 0x00000100,
                _500K_ADC0_SS = 0x00000200, _1M_ADC0_SS = 0x00000300,
                _125K_ADC1_SS = 0x00000000, _250K_ADC1_SS = 0x00000400,
                _500K_ADC1_SS = 0x00000800, _1M_ADC1_SS = 0x00000C00
               }ADC_SAMP_SPEED;

  /* The Following Enumeration Define The Different Voltage Reference Modes in ADC.*/
  typedef enum {ADC_REF_INT = 0x00000000, ADC_REF_EXT_3V = 0x00000001}ADC_Reference;

  /* The Following Enumeration Define The Different Event Trigger sources in ADC.*/
  typedef enum { ADC_TRIGGER_PROCESSOR = 0x00000000, ADC_TRIGGER_COMP0 = 0x00000001,
                 ADC_TRIGGER_COMP1 = 0x00000002,     ADC_TRIGGER_COMP2 = 0x00000003,
                 ADC_TRIGGER_EXTERNAL = 0x00000004,  ADC_TRIGGER_TIMER = 0x00000005,
                 ADC_TRIGGER_PWM0  = 0x00000006,     ADC_TRIGGER_PWM1  = 0x00000007,
                 ADC_TRIGGER_PWM2  = 0x00000008,     ADC_TRIGGER_PWM3  = 0x00000009,
                 ADC_TRIGGER_NEVER = 0x0000000E,     ADC_TRIGGER_ALWAYS  = 0x0000000F,
                 ADC_TRIGGER_PWM_MOD0 = 0x00000000,  ADC_TRIGGER_PWM_MOD1 = 0x00000010,
               }ADC_EventTrigger_Source;


   /* The Following Enumeration Define The number of the sample sequencer for the ADC.*/
   typedef enum {ADC_SS0, ADC_SS1, ADC_SS2, ADC_SS3,}ADC_SS_Num;

   /* The Following Enumeration Define The Different Priorities of the sequencers in ADC.*/
   typedef enum { ADC_SS0_Highest_PRI = 0x3210, ADC_SS0_Lowest_PRI = 0x0123,
                  ADC_SS1_Highest_PRI = 0x3201, ADC_SS1_Lowest_PRI = 0x0132,
                  ADC_SS2_Highest_PRI = 0x1023, ADC_SS2_Lowest_PRI = 0x2310,
                  ADC_SS3_Highest_PRI = 0x0123, ADC_SS3_Lowest_PRI = 0x3210,
                }ADC_Sequencer_Priority;

   /* The Following Enumeration Define The Different ADC Channels.*/
   typedef enum { ADC_CH0_AIN0_PE3 = 0x00000000,   ADC_CH1_AIN1_PE2 = 0x00000001,
                  ADC_CH2_AIN2_PE1 = 0x00000002,   ADC_CH3_AIN3_PE0 = 0x00000003,
                  ADC_CH4_AIN4_PD3 = 0x00000004,   ADC_CH5_AIN5_PD2 = 0x00000005,
                  ADC_CH6_AIN6_PD1 = 0x00000006,   ADC_CH7_AIN7_PD0 = 0x00000007,
                  ADC_CH8_AIN8_PE5 = 0x00000008,   ADC_CH9_AIN9_PE4 = 0x00000009,
                  ADC_CH10_AIN10_PB4 = 0x0000000A, ADC_CH11_AIN11_PB5 = 0x0000000B,
                }ADC_Channel;

   /* The following Enumeration Define if the internal Temperature Sensor is enabled or not.*/
   typedef enum {INT_TEMP_SENSOR_ENABLE = 0x00000008, INT_TEMP_SENSOR_DISABLE = 0x00000000,}ADC_Internal_TS_STATE;

   /* The following Enumeration Defines whether the ADC Interrupt enabled or disabled.*/
   typedef enum {INTERRUPT_DISABLE = 0x00000000, INTERRUPT_ENABLE = 0x00000004}ADC_Interrupt;

   /* The following Enumeration Defines whether this sample is the last one or not.*/
   typedef enum {LAST_SAMPLE = 0x00000002, NOT_LAST_SAMPLE = 0x00000000}ADC_End_of_CONV;

   /* The following Enumeration Enables or Disables the Differential input of the ADC.*/
   typedef enum {ADC_DIFF_INPUT_ENABLE=0X00000001, ADC_DIFF_INPUT_DISABLE=0X00000000,}ADC_Diffrential_SEL;

#define ADC_CLOCK_ENABLE(ADC_CLOCK) do{ REG32_ACCESS((SYSTEM_CTL_BASE),(ADC_CLK_ofsset)) |= (ADC_CLOCK);}while(0)


  /**
  *  @brief <void GPIO_CONFIG_FOR_ADC(PORT_CLOCK, PORT_BASE, PINS_CODE)>
  *  <This function will be used to configure the the desired GPIO for the ADC Module.>
  *
  *  @param  GPIO_CLOCKS <PORT_CLOCK> <The clock code of the desired port.>
  *  @param  uint32      <PORT_BASE>  <Base address of the desired port.>
  *  @param  uint8       <PINS_CODE>  <The hexadecimal code that represents the number of pins used.>
  *
  *  @return <This Function Returns Void.>
  *
  */

  /**
   *  @brief <void GPIO_CONFIG_FOR_FL_S(void)>
   *  <This function will be used to configure the GPIO pins to work as alternative function for ADC.>
   *
   *  @param     <void >
   *
   *  @return <This Function Returns Void.>
   *
   */

  void GPIO_CONFIG_FOR_FL_S(void);

  void GPIO_CONFIG_FOR_ADC(GPIO_CLOCKS PORT_CLOCK, uint32 PORT_BASE, uint8 PINS_CODE);

  /**
    *  @brief <void ADC_Init(uint32 ADC_Base, ADC_Reference VRef, ADC_SAMP_SPEED Sampling_Speed)>
    *  <This function will be used to Initiate the ADC Unit in The Tm4c123.>
    *
    *  @param uint32            <ADC_BASE>                 <The Base address for the desired ADC Module.>
    *  @param ADC_Reference     <VRef>                     <different ADC Voltage References.>
    *  @param ADC_SAMP_SPEED    <Sampling_Speed>           <different ADC Sampling Speeds.>
    *
    *  @return <This Function Returns Void.>
    *
    */
   void ADC_Init(uint32 ADC_Base, ADC_Reference VRef, ADC_SAMP_SPEED Sampling_Speed);

    /**
    *  @brief <ADC_S_SEQ_Config(uint32 ADC_BASE, ADC_SS_Num S_Seq_Num, ADC_Sequencer_Priority Priority,
    *                           ADC_EventTrigger_Source Event_source, ADC_Internal_TS_STATE TS_St,
    *                           ADC_Interrupt Interrupt_state, ADC_End_of_CONV Conv_end, ADC_Diffrential_SEL Diff_state)>
    *  <This function will be used to Configure The sample sequencer for the ADC Module in the Tm4c123 Controller.>
    *
    *  @param uint32                   <ADC_BASE>                   <The Base address for the desired ADC Module.>
    *  @param ADC_SS_Num               <S_Seq_Num>                  <the Number of sample sequencer.>
    *  @param ADC_Sequencer_Priority   <ADC_Sequencer_Priority>     <the configuration of the sample sequencer Priority.>
    *  @param ADC_EventTrigger_Source  <Event_source>               <the trigger source of the ADC Module.>
    *  @param ADC_Internal_TS_STATE    <TS_St>                      <State of the internal Temperature sensor.i.e used or not.>
    *  @param ADC_Interrupt            <Interrupt_state>            <Enable or Disable ADC Interrupt.>
    *  @param ADC_End_of_CONV          <Conv_end>                   <Select the Last sample number of the ADC Conversion.>
    *  @param ADC_Diffrential_SEL      <Diff_state>                 <Enable or Disable the differential input of the ADC.>
    *
    *  @return <This Function Returns Void.>
    *
    */
   void ADC_S_SEQ_Config(uint32 ADC_BASE, ADC_SS_Num S_Seq_Num, ADC_Sequencer_Priority Priority,
                             ADC_EventTrigger_Source Event_source, ADC_Internal_TS_STATE TS_St,
                             ADC_Interrupt Interrupt_state, ADC_End_of_CONV Conv_end, ADC_Diffrential_SEL Diff_state);
    /**
      *  @brief <void ADC_Read(ADC_Channel Channel, ADC_SS_Num S_Seq_Num)>
      *  <This function will be used to READ the Voltage Input to the ADC unit.>
      *
      *  @param ADC_Channel   <Channel>     <Selects different ADC channels.>
      *  @param ADC_SS_Num    <S_Seq_Num>   <the Number of sample sequencer.>
      *
      *  @return <uint16 returns The voltage Input to the ADC channel.>
      *
      */
    uint16 ADC_Read(uint32 ADC_BASE, ADC_Channel Channel, ADC_SS_Num S_Seq_Num);

#endif /* ADC_TM4C123_H_ */
