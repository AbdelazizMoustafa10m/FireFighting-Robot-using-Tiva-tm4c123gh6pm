/*
 * Servo.h
 *
 * Created: 8/27/2018 7:20:50 PM
 *  Author: Hamdy
 */ 


#ifndef SERVO_H_
#define SERVO_H_

	
	#include "Timers.h"
    #include "PWM.h"


#define MIN_DUTY_CYCLE      (319000) /* This value will turn servo to leftmost point*/
#define MAX_DUTY_CYCLE      (1000) /* This value will turn servo to rightmost point*/
#define _50_DUTY_CYCLE      (160000) /* This value will turn servo to midpoint */
#define _25_DUTY_CYCLE      (100000) /* This value will turn servo to 25 % of the rotation */
#define _50Hz_FREQ          (320000)
	
/**
 *  @file  <Ultrasonic.h>
 *  @brief <Header File of The Servo Motor library.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <21-Dec-18>
 *
 */


  /**
  *  @brief <void Servo_Init(void)>
  *  <This function will be used to initiate the Servo Motor by initiating the input capture using Timer4 B in the Tm4c123.>
  *
  *  @param uint32        <PORT_BASE>            <The Base Address of the desired GPIO.>
  *  @param GPIO_CLOCKS   <PORT_CLOCK>           <The Clock code for the desired GPIO PORT used by the servo Motor.>
  *  @param uint8         <PIN_NO>               <GPIO PIN number used as the servo signal pin.>
  *
  *  @return <This Function Returns Void.>
  *
  */
  void Servo_Init(void);



  /**
  *  @brief < void Servo_Pos(uint8 Position ,uint32 Timer_Base, uint32 Timer_n_Mode_Offset, uint32 Frequency,
  *                          void (*P_tf)(uint32, uint32, uint32, float32))>
  *  <This function will be used to Rotate the servo motor a desired angle by generating PWM usig the Timers Module.>
  *
  *  @param uint8       <Position>             <The Desired position for the Servo Motor.>
  *  @param uint32      <Timer_Base>           <The Base Address of the desired Timer Module.>
  *  @param uint32      <Timer_n_Mode_Offset>  <The address of the offset register for the desired timer, GPTMTAMR/GPTMTBMR.>
  *  @param uint32      <Frequncy>             <The desired PWM Frequency that will determine the load value for the Timer.>
  *  @param void        <(*P_tf)>              <Pointer to the Timers_PWM function.>
  *
  *  @return <This Function Returns Void.>
  *
  */
  void Servo_Pos(uint32 Position);

  void Servo_turn(void);

  void Servo_turnss(void);
	
	
#endif /* SERVO_H_ */
