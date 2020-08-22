/*
 * IrqPriorities.h
 *
 *  Created on: 23 лип. 2020 р.
 *      Author: MaxCm
 */

#ifndef INC_IRQPRIORITIES_H_
#define INC_IRQPRIORITIES_H_

#ifdef __cplusplus
extern "C" {
#endif

#define IrqPrio_Pwm1Update	2
#define IrqPrio_Timer2		3
#define IrqPrio_Timer4		4

#define IrqPrio_Spi1Finish	5
#define IrqPrio_Spi2Finish	5

#define IrqPrio_I2C1	4
#define IrqPrio_I2C2	4

#ifdef __cplusplus
}
#endif

#endif /* INC_IRQPRIORITIES_H_ */
