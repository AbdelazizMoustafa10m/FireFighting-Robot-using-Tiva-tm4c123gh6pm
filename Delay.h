/*
 * Delay.h
 *
 *  Created on: Dec 12, 2018
 *      Author: Abdelaziz
 */

#ifndef DELAY_H_
#define DELAY_H_

#include"Timers.h"
/**
 *  @file  <Delay.h>
 *  @brief <Header File of The Delay library for the Tm4c123 controller.>
 *         <It contains The Prototypes of all function available in
 *          the library,definitions of all Macros, and Enumerations>
 *
 *  @author<Eng/Abdelaziz Moustafa Abdelazem>
 *  @date  <12-Dec-18>
 *
 */


  /**
  *  @brief <void Delay_uS(uint32 Time)>
  *  <This function will be used to make a delay in microsecond using  Timer4 in the Tm4c123.>
  *
  *  @param uint32     <Time>          <The desired delay time.>
  *
  *  @return <This Function Returns Void.>
  *
  */
  void Delay_uS(uint32 Time);

  /**
  *  @brief <void Delay_mS(uint32 Time)>
  *  <This function will be used to make a delay in milliseconds using  Timer5 in the Tm4c123.>
  *
  *  @param uint32     <Time>          <The desired delay time.>
  *
  *  @return <This Function Returns Void.>
  *
  */
  void Delay_mS(uint32 Time);


  void Delay(uint32 Time);


#endif /* DELAY_H_ */
