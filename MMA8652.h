#if !defined(MMA8652_H)
#define MMA8652_H

#include <stdio.h> 
#include <device.h>
#include <stdint.h>
#include <I2C.h>
    
#define   MMA8652_STATUS_00  0x00
#define   MMA8652_OUT_X_MSB  0x01
#define   MMA8652_OUT_X_LSB  0x02
#define   MMA8652_OUT_Y_MSB  0x03
#define   MMA8652_OUT_Y_LSB  0x04
#define   MMA8652_OUT_Z_MSB  0x05
#define   MMA8652_OUT_Z_LSB  0x06
#define   MMA8652_F_SETUP  0x09
#define   MMA8652_TRIG_CFG  0x0A
#define   MMA8652_SYSMOD  0x0B
#define   MMA8652_INT_SOURCE  0x0C
#define   MMA8652_WHO_AM_I  0x0D
#define   MMA8652_XYZ_DATA_CFG  0x0E
#define   MMA8652_HP_FILTER_CUTOFF  0x0F
#define   MMA8652_PL_STATUS  0x10
#define   MMA8652_PL_CFG  0x11
#define   MMA8652_PL_COUNT  0x12
#define   MMA8652_PL_BF_ZCOMP  0x13
#define   MMA8652_PL_THS_REG  0x14
#define   MMA8652_FF_MT_CFG  0x15
#define   MMA8652_FF_MT_SRC  0x16
#define   MMA8652_FF_MT_THS  0x17
#define   MMA8652_FF_MT_COUNT  0x18
#define   MMA8652_TRANSIENT_CFG  0x1D
#define   MMA8652_TRANSIENT_SRC  0x1E
#define   MMA8652_TRANSIENT_THS  0x1F
#define   MMA8652_TRANSIENT_COUNT  0x20
#define   MMA8652_PULSE_CFG  0x21
#define   MMA8652_PULSE_SRC  0x22
#define   MMA8652_PULSE_THSX  0x23
#define   MMA8652_PULSE_THSY  0x24
#define   MMA8652_PULSE_THSZ  0x25
#define   MMA8652_PULSE_TMLT  0x26
#define   MMA8652_PULSE_LTCY  0x27
#define   MMA8652_PULSE_WIND  0x28
#define   MMA8652_ASLP_COUNT  0x29
#define   MMA8652_CTRL_REG1  0x2A
#define   MMA8652_CTRL_REG2  0x2B
#define   MMA8652_CTRL_REG3  0x2C
#define   MMA8652_CTRL_REG4  0x2D
#define   MMA8652_CTRL_REG5  0x2E
#define   MMA8652_OFF_X  0x2F
#define   MMA8652_OFF_Y  0x30
#define   MMA8652_OFF_Z  0x31

#define ST_MASK               0x80
#define RST_MASK              0x40
#define SMODS1_MASK           0x10
#define SMODS0_MASK           0x08
#define SLPE_MASK             0x04
#define MODS1_MASK            0x02
#define MODS0_MASK            0x01
#define SMODS_MASK            0x18
#define MODS_MASK             0x03
#define ZYXDR_MASK            0x08
#define ACTIVE_MASK           0x01

#define SMOD_NORMAL           0x00
#define SMOD_LOW_NOISE        (SMODS0_MASK)
#define SMOD_HIGH_RES         (SMODS1_MASK)
#define SMOD_LOW_POWER        (SMODS1_MASK+SMODS0_MASK)
//
#define MOD_NORMAL            0x00
#define MOD_LOW_NOISE         (MODS0_MASK)
#define MOD_HIGH_RES          (MODS1_MASK)
#define MOD_LOW_POWER         (MODS1_MASK+MODS0_MASK)

#define MMA8652_ADDR 0x1D
    
//	I2C ADDRESS DEFINITIONS

#define I2C_ACK             0x00
#define I2C_NACK            0xff
#define I2C_WRITE           0x00
#define I2C_READ            0xff
    
#define I2C_TIMEOUT         200    

uint32_t MMA8652_Write(uint32_t address, uint32_t data);
uint32_t MMA8652_Read(uint32_t address, uint8_t* received);
uint32_t MMA8652_Initialize(void);
uint32_t MMA8652_ActiveMode(void);
uint32_t MMA8652_StandByMode(void);
uint32_t MMA8652_Reset(void);
uint32_t MMA8652_ReadAcc(int16_t* acc);
uint32_t MMA8652_PulseSetup(uint8_t thresholdx, uint8_t thresholdy, uint8_t thresholdz, uint8_t timelimit);
uint32_t MMA8652_MotionSetup(uint8_t threshold, uint8_t debounce_count);
uint32_t MMA8652_Transient_Setup(uint8_t threshold, uint8_t debounce_count);
uint32_t MMA8652_ReadMultipleBytes(uint8_t register_addr, uint8_t* data, size_t data_len);
void MMA8652_ConvertCountToMg(int16_t* acceleration, uint16_t* raw_count);
uint32_t MMA8652_WhoAmI(uint8_t* id);

#endif
/* [] END OF FILE */