/*
 * Timers.h
 *
 *  Created on: Dec 11, 2018
 *      Author: Abdelaziz
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include"Micro_Config_Tiva.h"
#include"MACROS_TIVA.h"
#include"GPIO.h"

/**
 *  @file  <Timers.h>
 *  @brief <Header File of The Timers Module of the Tm4c123 controller.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <11-Dec-18>
 *
 */

  /* The following group of definitions represent the Bit Numbers in GPTMCTL Register in Tm4c123.*/
  #define TIMERA_ENABLE_BIT                           (0)          /* TAEN */
  #define TIMERB_ENABLE_BIT                           (8)          /* TBEN */

  /* The following group of definitions represent the Bit Numbers in GPTMRIS/GPTMICR Register in Tm4c123.*/
  #define TIMERA_Match_INTERRUPT_FLAG_BIT             (4)          /* TAMRIS */
  #define TIMERA_CAPMODE_EVENT_INTERRUPT_FLAG_BIT     (2)          /* CAERIS */
  #define TIMERA_CAPMODE_MATCH_INTERRUPT_FLAG_BIT     (1)          /* CAMRIS */
  #define TIMERA_TIME_OUT_INTERRUPT_FLAG_BIT          (0)          /* TATORIS */
  #define TIMERB_Match_INTERRUPT_FLAG_BIT             (11)         /* TBMRIS */
  #define TIMERB_CAPMODE_EVENT_INTERRUPT_FLAG_BIT     (10)         /* CBERIS */
  #define TIMERB_CAPMODE_MATCH_INTERRUPT_FLAG_BIT     (9)          /* CBMRIS */
  #define TIMERB_TIME_OUT_INTERRUPT_FLAG_BIT          (8)          /* TBTORIS */

  /* This Macro Defines the digital code encoded in GPIOCTL Register to select the Timer Alternative Function*/
  #define TIMERS_Digital_Code                         (7)


  /* This Enumeration has the clock codes for each Timer in the Timers Module*/
  typedef enum
  {
      Timer0_CLOCK = 0x01,     WTimer0_CLOCK = 0x01,
      Timer1_CLOCK = 0x02,     WTimer1_CLOCK = 0x02,
      Timer2_CLOCK = 0x04,     WTimer2_CLOCK = 0x04,
      Timer3_CLOCK = 0x08,     WTimer3_CLOCK = 0x08,
      Timer4_CLOCK = 0x10,     WTimer4_CLOCK = 0x10,
      Timer5_CLOCK = 0x20,     WTimer5_CLOCK = 0x20,
  }Timer_CLOCKS;


  /* This Enumeration has the GPTimer sizes codes for each Timer in the Timers Module*/
  typedef enum
  {
      _32BIT_TIMER     = 0x00,         _64BIT_WTIMER     = 0x00,
      _32BIT_RTC_TIMER = 0x01,         _64BIT_RTC_WTIMER = 0x01,
      _16BIT_TIMER     = 0x04,         _32BIT_WTIMER      = 0x00,

  }Timer_Size;

  /* This Enumeration has the Operating Modes for each Timer in the Timers Module*/
  typedef enum
  {
      ONE_SHOT_DOWNC_T_MODE           = 0x00000001,      ONE_SHOT_UPC_T_MODE           = 0x00000011,
      PERIODIC_DOWNC_T_MODE           = 0x00000002,      PERIODIC_UPC_T_MODE           = 0x00000012,
      EDGE_COUNTCAPATURE_DOWNC_T_MODE = 0x00000003,      EDGE_COUNTCAPATURE_UPC_T_MODE = 0x00000013,
      EDGE_TIMECAPATURE_DOWNC_T_MODE  = 0x00000007,      EDGE_TIMECAPATURE_UPC_T_MODE  = 0x00000017,
      PWM_PER_T_MODE                  = 0x0000000A,      PWM_OSHOT_T_MODE              = 0x00000009,
  }Timer_Modes;

  /* This Enumeration has the GPTimer interrupt States for each Timer in the Timers Module*/
  typedef enum
  {
      Match_Interrupt_DISABLE         = 0x00000000,        Match_Interrupt_ENABLE         = 0x00000020,
      CAP_EVENT_Interrupt_DISABLE     = 0x00000000,        CAP_EVENT_Interrupt_ENABLE     = 0x00000100,
  }Timer_Interrupt_State;

  /* This Enumeration has the Capture Events Modes for each Timer in the Timers Module*/
  typedef enum
  {
     NO_CAP_NO_PWM_MODE              = 0x00000000,
     TIMERA_PWM_NONINVERTED          = 0x00000000,      TIMERA_PWM_INVERTED             = 0x00000040,
     TIMERB_PWM_NONINVERTED          = 0x00000000,      TIMERB_PWM_INVERTED             = 0x00004000,
     TIMERA_ADC_TRIGGER_DISABLE      = 0x00000000,      TIMERA_ADC_TRIGGER_ENABLE       = 0x00000020,
     TIMERB_ADC_TRIGGER_DISABLE      = 0x00000000,      TIMERB_ADC_TRIGGER_ENABLE       = 0x00002000,
     TIMERA_POS_EDGE_CAPMODE         = 0x00000000,      TIMERA_NEG_EDGE_CAPMODE         = 0x00000004,
     TIMERA_BOTH_EDGES_CAPMODE       = 0x0000000C,      TIMERB_POS_EDGE_CAPMODE         = 0x00000000,
     TIMERB_NEG_EDGE_CAPMODE         = 0x00000400,      TIMERB_BOTH_EDGES_CAPMODE       = 0x00000C00,
  }Timer_CAP_EVENTS;


  /* This Macro is Used to enable the desired Timer Module*/
  #define Timers_ENABLE(Timer_BASE,Timer_n_EN_BIT) do{ SET_BIT(Timer_BASE,GPTM_CTL_offset,Timer_n_EN_BIT);}while(0)


  /**
    *  @brief < void Timers_Init(uint32 Timer_Base,T imer_CLOCKS Clock,uint32 Timer_Clock_Offset, Timer_Size Size)>
    *  <This function will be used to Initiate the Timers Module in The Tm4c123.>
    *
    *  @param uint32        <Timer_Base>          <The Base Address of the desired Timer Module.>
    *  @param Timer_CLOCKS  <Clock>               <The Clock code for the desired Timer Module.>
    *  @param uint32        <Timer_Clock_Offset>  <the offset address of the clock for the desired timer or wide timer .>
    *  @param Timer_Size    <Size>                <different timer sizes.>
    *
    *  @return <This Function Returns Void.>
    *
    */
    void Timers_Init(uint32 Timer_Base, Timer_CLOCKS Clock, uint32 Timer_Clock_Offset, Timer_Size Size);

    /**
     *  @brief < void GPIO_AFSEL_FOR_QEI(uint32 PORT_BASE, GPIO_CLOCKS PORT_CLOCK, uint8 PIN_NO, DIO_MODE direction)>
     *  <This function will be used to Select the QEI alternative function for .>
     *
     *  @param uint32        <PORT_BASE>            <The Base Address of the desired GPIO.>
     *  @param GPIO_CLOCKS   <PORT_CLOCK>           <The Clock code for the desired GPIO PORT used by the timer Module.>
     *  @param uint8         <PIN_NO>               <GPIO PIN number used for the Timer Module.>
     *  @param DIO_MODE      <direction>           <GPIO PIN direction whether input or output.>
     *
     *  @return <This Function Returns Void.>
     *
     */
     void GPIO_AFSEL_FOR_TIMERS(uint32 PORT_BASE, GPIO_CLOCKS PORT_CLOCK, uint8 PIN_NO, DIO_MODE direction);

    /**
     *  @brief <void Timers_Configuration(uint32 Timer_Base, uint32 Timer_n_Mode_Offset, uint8 Timer_Enable_BIT,Timer_Modes Mode,
     *                                    uint32 Count_Value, Timer_CAP_EVENTS Cap_Event, Timer_Interrupt_State Int_state)>
     *  <This function will be used to Configure The Timer Module in the Tm4c123 Controller.>
     *
     *  @param uint32                <Timer_Base>           <The Base Address of the desired Timer Module.>
     *  @param uint32                <Timer_n_Mode_Offset>  <The address of the offset register for the desired timer, GPTMTAMR/GPTMTBMR.>
     *  @param uint8                 <Timer_Enable_BIT>     <The number of bit that enables a desired timer module.>
     *  @param Timer_Modes           <Mode>                 <The Mode of operation of the desired Timer.>
     *  @param uint32                <Count_Value>          <The value that the timer will count up to or down from.>
     *  @param Timer_CAP_EVENTS      <Cap_Event>            <The different input capture moods for the Timer.>
     *  @param Timer_Interrupt_State <Int_state>            <Enable or Disable Timer Interrupt.>
     *
     *  @return <This Function Returns Void.>
     *
     */
    void Timers_Configuration(uint32 Timer_Base, uint32 Timer_n_Mode_Offset, uint8 Timer_Enable_BIT,Timer_Modes Mode,
                              uint32 Count_Value, Timer_CAP_EVENTS Cap_Event, Timer_Interrupt_State Int_state);

    /**
     *  @brief <Timers_PWM(uint32 Timer_Base, uint32 Timer_n_Mode_Offset, uint32 Frequency, uint32 Duty_Cycle)>
     *  <This function will be used to generate a PWM of a desired frequency and duty cycle from the timer module.>
     *
     *  @param uint32      <Timer_Base>           <The Base Address of the desired Timer Module.>
     *  @param uint32      <Timer_n_Mode_Offset>  <The address of the offset register for the desired timer, GPTMTAMR/GPTMTBMR.>
     *  @param float32      <Frequncy>             <The desired PWM Frequency that will determine the load value for the Timer.>
     *  @param float32     <Duty_Cycle>           <The desired PWM Duty cycle that will determine the match value for the Timer.>
     *
     *  @return <This Function Returns Void.>
     *
     */
    void SET_PWM(uint32 Timer_Base, uint32 Timer_n_Mode_Offset, float32 Frequency, float32 Duty_Cycle);




#endif /* TIMERS_H_ */
