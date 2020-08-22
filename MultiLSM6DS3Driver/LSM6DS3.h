/*
 * LSM6DS3.h
 *
 *  Created on: 24 лип. 2020 р.
 *      Author: MaxCm
 */

#ifndef LSM6DS3_H_
#define LSM6DS3_H_

//device registers
#define FUNC_CFG_ACCESS 	0x01
#define SENSOR_SYNC_TIME_FRAME 	0x04

#define FIFO_CTRL1 	0x06
#define FIFO_CTRL2 	0x07
#define FIFO_CTRL3 	0x08
#define FIFO_CTRL4 	0x09
#define FIFO_CTRL5 	0x0A

#define ORIENT_CFG_G 	0x0B

#define INT1_CTRL 	0x0D
#define INT2_CTRL 	0x0E

#define WHO_AM_I 	0x0F

#define CTRL1_XL 	0x10
typedef enum
{
	A_POWER_DOWN = 0x00 << 4,   // Power-down mode (0x0)
	A_ODR_13 = 0x01 << 4,       // 12.5 Hz (0x1)        low power
	A_ODR_26 = 0x02 << 4,       // 26 Hz (0x2)          low power
	A_ODR_52 = 0x03 << 4,       // 52 Hz (0x3)          low power
	A_ODR_104 = 0x04 << 4,      // 104 Hz (0x4)         normal mode
	A_ODR_208 = 0x05 << 4,      // 208 Hz (0x5)         normal mode
	A_ODR_416 = 0x06 << 4,      // 416 Hz (0x6)         high performance
	A_ODR_833 = 0x07 << 4,      // 833 Hz (0x7)         high performance
	A_ODR_1660 = 0x08 << 4,     // 1.66 kHz (0x8)       high performance
	A_ODR_3330 = 0x09 << 4,     // 3.33 kHz (0x9)       high performance
	A_ODR_6660 = 0x0A << 4    // 6.66 kHz (0xA)       high performance
} XL_ODR;

typedef enum
{
	A_SCALE_2G = 0x00 << 2,
	A_SCALE_16G = 0x01 << 2,
	A_SCALE_4G = 0x02 << 2,
	A_SCALE_8G = 0x03 << 2
} XL_FS;

typedef enum //in Hz
{
	A_BW_400 = 0x00,
	A_BW_200 = 0x01,
	A_BW_100 = 0x02,
	A_BW_50 = 0x03
} XL_BW;

#define CTRL2_G 	0x11
#define CTRL3_C 	0x12
#define CTRL4_C 	0x13
#define CTRL5_C 	0x14
#define CTRL6_C 	0x15
#define CTRL7_G 	0x16
#define CTRL8_XL 	0x17
#define CTRL9_XL 	0x18
#define CTRL10_C 	0x19

#define	MASTER_CONFIG 	0x1A
#define WAKE_UP_SRC 	0x1B
#define TAP_SRC 	0x1C
#define D6D_SRC 	0x1D
#define STATUS_REG 	0x1E

#define OUT_TEMP_L 	0x20
#define OUT_TEMP_H 	0x21

#define OUTX_L_G 	0x22
#define OUTX_H_G 	0x23
#define OUTY_L_G 	0x24
#define OUTY_H_G 	0x25
#define OUTZ_L_G 	0x26
#define OUTZ_H_G 	0x27
#define OUTX_L_XL 	0x28
#define OUTX_H_XL 	0x29
#define OUTY_L_XL 	0x2A
#define OUTY_H_XL 	0x2B
#define OUTZ_L_XL 	0x2C
#define OUTZ_H_XL 	0x2D

#define	SENSORHUB1_REG		0x2E
#define SENSORHUB2_REG		0x2F
#define SENSORHUB3_REG		0x30
#define SENSORHUB4_REG 		0x31
#define SENSORHUB5_REG 		0x32
#define SENSORHUB6_REG 		0x33
#define SENSORHUB7_REG 		0x34
#define SENSORHUB8_REG 		0x35
#define SENSORHUB9_REG 		0x36
#define SENSORHUB10_REG 	0x37
#define SENSORHUB11_REG 	0x38
#define SENSORHUB12_REG 	0x39

#define	FIFO_STATUS1 	0x3A
#define FIFO_STATUS2 	0x3B
#define FIFO_STATUS3 	0x3C
#define FIFO_STATUS4 	0x3D
#define FIFO_DATA_OUT_L 	0x3E
#define FIFO_DATA_OUT_H 	0x3F

#define TIMESTAMP0_REG 	0x40
#define TIMESTAMP1_REG 	0x41
#define TIMESTAMP2_REG 	0x42

#define STEP_TIMESTAMP_L 	0x49
#define STEP_TIMESTAMP_H 	0x4A
#define STEP_COUNTER_L		0x4B
#define STEP_COUNTER_H		0x4C

#define SENSORHUB13_REG 	0x4D
#define SENSORHUB14_REG 	0x4E
#define SENSORHUB15_REG 	0x4F
#define SENSORHUB16_REG 	0x50
#define SENSORHUB17_REG 	0x51
#define SENSORHUB18_REG 	0x52

#define FUNC_SRC 	0x53
#define TAP_CFG 	0x58
#define TAP_THS_6D 	0x59
#define INT_DUR2 	0x5A

#define WAKE_UP_THS 	0x5B
#define WAKE_UP_DUR 	0x5C

#define FREE_FALL 	0x5D

#define MD1_CFG 	0x5E
#define MD2_CFG 	0x5F

#define OUT_MAG_RAW_X_L 	0x66
#define OUT_MAG_RAW_X_H 	0x67
#define OUT_MAG_RAW_Y_L 	0x68
#define OUT_MAG_RAW_Y_H 	0x69
#define OUT_MAG_RAW_Z_L 	0x6A
#define OUT_MAG_RAW_X_H 	0x6B


#endif /* LSM6DS3_H_ */
