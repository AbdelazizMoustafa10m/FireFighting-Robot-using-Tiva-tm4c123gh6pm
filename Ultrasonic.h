/*
 * Ultrasonic.h
 *
 *  Created on: Dec 12, 2018
 *      Author: Abdelaziz
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include"Timers.h"
#include"Delay.h"

/**
 *  @file  <Ultrasonic.h>
 *  @brief <Header File of The Ultrasonic Sensor library.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <12-Dec-18>
 *
 */

#define ECHO       (3)             /*PB2*/
#define TRIGGER    (4)            /*PA4*/


  /**
  *  @brief <void Ultrasonic_Init(void)>
  *  <This function will be used to initiate the ultrasonic sensor by initiating the input capture using Timer3 in the Tm4c123.>
  *
  *  @param uint32        <PORT_BASE>            <The Base Address of the desired GPIO.>
  *  @param GPIO_CLOCKS   <PORT_CLOCK>           <The Clock code for the desired GPIO PORT used by the Trigger pin.>
  *  @param uint8         <PIN_NO>               <GPIO PIN number used as the trigger for the ultrasonic sensor.>
  *
  *  @return <This Function Returns Void.>
  *
  */
  void Ultrasonic_Init(void);

  /**
   *  @brief <uint32 Measure_Distance(void)>
   *  <This function will be used to measure distance using the ultrasonic sensor.>
   *
   *  @param           <Void>
   *
   *  @return uint32   <Distance_cm>     <The distance measured by the ultrasonic sensor in centimeters.>
   *
   */
  uint32 Measure_Distance(void);

#endif /* ULTRASONIC_H_ */
