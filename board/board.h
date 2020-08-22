/*
 * board.h
 *
 *  Created on: 23 ���. 2020 �.
 *      Author: MaxCm
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdint.h>
#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

ConfigResult setSwdPinsUsed();
ConfigResult setHsePinsUsed();

ConfigResult configLeds();
void greenLedCtrl(uint8_t state);
void blueLedCtrl(uint8_t state);

ConfigResult configButtonForPolling();
uint8_t isButtonPushed();

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H_ */
