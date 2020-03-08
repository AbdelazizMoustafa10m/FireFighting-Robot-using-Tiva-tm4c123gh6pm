/*
 * Flame_Detection.h
 *
 *  Created on: Dec 22, 2018
 *      Author: Abdelaziz
 */

#ifndef FLAME_DETECTION_H_
#define FLAME_DETECTION_H_

#include"ADC_Tm4c123.h"
#include"Servo.h"

/**
 *  @file  <Flame_Detection.h>
 *  @brief <Header File of The flame detection Module of the Robot using ADC.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <22-Dec-18>
 *
 */

   #define CENTER_F_SENSOR     (0)
   #define RIGHT_F_SENSOR      (3)
   #define LEFT_F_SENSOR       (4)

  /**
  *  @brief <void FLAME_DETECT_Init(void)>
  *  <This function will be used to initiate the FLAME sensors using the ADC and GPIO.>
  *
  *  @param     <void >
  *
  *  @return <This Function Returns Void.>
  *
  */
  void FLAME_DETECT_Init(void);

  /**
   *  @brief <void  SCAN_FOR_FIRE(void)>
   *  <This function will be used to Scan the room for fire and deploying it.>
   *
   *  @param     <void >
   *
   *  @return <This Function Returns Void.>
   *
   */
  void SCAN_FOR_FIRE(void);

#endif /* FLAME_DETECTION_H_ */
