/*
 * DC_Motors.h
 *
 *  Created on: Dec 22, 2018
 *      Author: Abdelaziz
 */

#ifndef DC_MOTORS_H_
#define DC_MOTORS_H_

#include"Timers.h"
/**
 *  @file  <DC_Motors.h>
 *  @brief <Header File of The DC Motors Configuration.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <12-Dec-18>
 *
 */


  #define _1KHZ_FREQ      (16000)
  #define L_MOTOR_PIN     (6)
  #define R_MOTOR_PIN     (7)

  /**
  *  @brief <void Motors_Init(void)>
  *  <This function will be used to initiate the DC motors by configuring the appropriate timers.>
  *
  *  @param     <void >
  *
  *  @return <This Function Returns Void.>
  *
  */
  void Motors_Init(void);

  /**
   *  @brief <void MOVE_FORWARD(void)>
   *  <This function will be used to Move the Robot Forward.>
   *
   *  @param     <void >
   *
   *  @return <This Function Returns Void.>
   *
   */
  void MOVE_FORWARD(void);


  /**
   *  @brief <void STOP(void)>
   *  <This function will be used to Stop the Robot.>
   *
   *  @param     <void >
   *
   *  @return <This Function Returns Void.>
   *
   */
  void STOP(void);

  /**
   *  @brief <void TURN_RIGHT(void)>
   *  <This function will be used to TURN The Robot Right.>
   *
   *  @param     <void >
   *
   *  @return <This Function Returns Void.>
   *
   */
  void TURN_RIGHT(void);

  /**
   *  @brief <void TURN_LEFT(void)>
   *  <This function will be used to TURN The Robot Left.>
   *
   *  @param     <void >
   *
   *  @return <This Function Returns Void.>
   *
   */
  void TURN_LEFT(void);


#endif /* DC_MOTORS_H_ */
