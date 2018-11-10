#include <MMA8652.h>

uint32_t MMA8652_Write(uint32_t address, uint32_t data)
{
    uint32_t error = 0;
    
    if ((error = I2C_I2CMasterSendStart(MMA8652_ADDR, I2C_WRITE, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    if ((error = I2C_I2CMasterWriteByte(address, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    if ((error = I2C_I2CMasterWriteByte(data, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }  
    
    error = I2C_I2CMasterSendStop(I2C_TIMEOUT);
    return error;
}

   
uint32_t MMA8652_Read(uint32_t address, uint8_t* received)
{
    uint32_t error = 0;
    
    if ((error = I2C_I2CMasterSendStart(MMA8652_ADDR, I2C_WRITE, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    if ((error = I2C_I2CMasterWriteByte(address, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    if ((error = I2C_I2CMasterSendRestart(MMA8652_ADDR, I2C_READ, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    if ((error = I2C_I2CMasterReadByte(I2C_NACK, received, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    error  = I2C_I2CMasterSendStop(I2C_TIMEOUT);
    return error;
}

uint32_t MMA8652_Initialize(void)
{
    uint32_t error;

    error = MMA8652_StandByMode();
    if (error) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }

    // Accelerometer range of +/-2g range with high pass output filter disabled
    // 1024 counts/g = 1 mg/LSB
    error = MMA8652_Write(MMA8652_XYZ_DATA_CFG, 0x00);
    if (error) {
        return error;
    }
    
    // Data rate = 400 Hz, sleep rate = 12.5 Hz
    error = MMA8652_Write(MMA8652_CTRL_REG1, 0x48);
    if (error) {
        return error;
    }
    
    // Active mode: low power, auto-sleep: disabled
    error = MMA8652_Write(MMA8652_CTRL_REG2, 0x03);
    if (error) {
        return error;
    }
    
    // Enable interrupts - Push-pull output, ACTIVE low
    // Pulse function interrupt can wake-up system
    // Orientation interrupt can wake-up system
    // Free-fall/motion function interrupt can wake-up system
    error = MMA8652_Write(MMA8652_CTRL_REG3, 0x79);
    if (error) {
        return error;
    }
    
    // Enable Pulse detection Interrupt
    // Enable Free-fall/motion Interrupt
    error = MMA8652_Write(MMA8652_CTRL_REG4, 0x0C);
    if (error) {
        return error;
    }
    
    // Orientation Interrupt and Free-fall/motion Interrupt to INT1 pin
    // Pulse detection Interrupt to INT2 pin
    error = MMA8652_Write(MMA8652_CTRL_REG5, 0x08);
    if (error) {
        return error;
    }
    
    error = MMA8652_ActiveMode();
    return error;
}

uint32_t MMA8652_ActiveMode(void)
{
    uint8_t received;
    uint32_t error = 0;
    
    // Set ACTIVE bit to 1
    error = MMA8652_Read(MMA8652_CTRL_REG1, &received);
    if (error) {
        return error;
    }
    
    error = MMA8652_Write(MMA8652_CTRL_REG1, received | ACTIVE_MASK);
    return error;
}

uint32_t MMA8652_StandByMode(void)
{
    uint8_t received;
    uint32_t error = 0;
    
    // Set ACTIVE bit to 0
    error = MMA8652_Read(MMA8652_CTRL_REG1, &received);
    if (error) {
        return error;
    }
    
    error = MMA8652_Write(MMA8652_CTRL_REG1, received & ~ACTIVE_MASK);
    return error;
}
    
uint32_t MMA8652_Reset(void)
{
    uint32_t error;
    uint8_t received;
    
    error = MMA8652_Write(MMA8652_CTRL_REG2, RST_MASK);
    if (error) {
        return error;
    }
    
    CyDelay(1);
    
    do {
        error = MMA8652_Read(MMA8652_CTRL_REG2, &received);
    } while ((error == 0) && ((received & RST_MASK) != 0));
    
    return error;
}

uint32_t MMA8652_ReadAcc(int16_t* acc)
{
    uint16_t acc_count[3];
    uint8_t temp;
    uint32_t error;

    // Read X, Y, Z data in continuous mode 
    if ((error = I2C_I2CMasterSendStart(MMA8652_ADDR, I2C_WRITE, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    if ((error = I2C_I2CMasterWriteByte(0x01, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }

    if ((error = I2C_I2CMasterSendRestart(MMA8652_ADDR, I2C_READ, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }

    if ((error = I2C_I2CMasterReadByte(I2C_ACK, &temp, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    acc_count[0] = temp << 8;

    if ((error = I2C_I2CMasterReadByte(I2C_ACK, &temp, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    acc_count[0] |= temp;

    if ((error = I2C_I2CMasterReadByte(I2C_ACK, &temp, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    acc_count[1] = temp << 8;

    if ((error = I2C_I2CMasterReadByte(I2C_ACK, &temp, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    acc_count[1] |= temp;

    if ((error = I2C_I2CMasterReadByte(I2C_ACK, &temp, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    acc_count[2] = temp << 8;

    if ((error = I2C_I2CMasterReadByte(I2C_NACK, &temp, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    acc_count[2] |= temp;

    if ((error = I2C_I2CMasterSendStop(I2C_TIMEOUT)) != 0) {
        return error;
    }

    // Count is stored in 2 complementers, convert to signed mg
    MMA8652_ConvertCountToMg(acc, acc_count);
    
    return error;
}

void MMA8652_ConvertCountToMg(int16_t* acceleration, uint16_t* raw_count)
{
    unsigned int i;
    int sign;
    
    for (i = 0; i < 3; ++i) {
        sign = 1;
        if ((raw_count[i] >> 8) > 0x7F) {
            sign = -1;
            raw_count[i] = ~raw_count[i] + 1;
        }
        raw_count[i] = raw_count[i] >> 4;
        acceleration[i] = sign * ((uint32_t)(1000 * raw_count[i] + 512) >> 10);
    }
}

uint32_t MMA8652_ReadMultipleBytes(uint8_t register_addr, uint8_t* data, size_t data_len)
{
    unsigned int i;
    uint32_t error;
    uint8_t ack;

    if ((error = I2C_I2CMasterSendStart(MMA8652_ADDR, I2C_WRITE, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    if ((error = I2C_I2CMasterWriteByte(register_addr, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    if ((error = I2C_I2CMasterSendRestart(MMA8652_ADDR, I2C_READ, I2C_TIMEOUT)) != 0) {
        I2C_I2CMasterSendStop(I2C_TIMEOUT);
        return error;
    }
    
    for (i = 0; i < data_len; ++i) {
        if (i == data_len - 1) {
            ack = I2C_NACK;
        } else {
            ack = I2C_ACK;
        }
        
        if ((error = I2C_I2CMasterReadByte(ack, &data[i], I2C_TIMEOUT)) != 0) {
            I2C_I2CMasterSendStop(I2C_TIMEOUT);
            return error;
        }
    }
    
    error = I2C_I2CMasterSendStop(I2C_TIMEOUT);
    return error;
}

uint32_t MMA8652_PulseSetup(uint8_t thresholdx, uint8_t thresholdy, uint8_t thresholdz, uint8_t timelimit)
{
    uint32_t error;
    
    error = MMA8652_StandByMode();
    if (error) {
        return error;
    }
   
    //Enable Single Pulse on X, Y, Z
    error = MMA8652_Write(MMA8652_PULSE_CFG, 0x15);
    if (error) {
        return error;
    }

    // Threshold X, Y, Z 0 - 127 (7 bits unsigned ), 63mg / LSB
    error = MMA8652_Write(MMA8652_PULSE_THSX, thresholdx);
    if (error) {
        return error;
    }

    error = MMA8652_Write(MMA8652_PULSE_THSY, thresholdy);
    if (error) {
        return error;
    }

    error = MMA8652_Write(MMA8652_PULSE_THSZ, thresholdz);
    if (error) {
        return error;
    }

    // 0 - 255 8 bits, 0.625 ms/step, max: 0.159 sec
    error = MMA8652_Write(MMA8652_PULSE_TMLT, timelimit);
    if (error) {
        return error;
    }

    // 0 - 255 8 bits, 1.25 ms/step, max: 0.318 sec - only for double taps?
    error = MMA8652_Write(MMA8652_PULSE_LTCY, 0);
    if (error) {
        return error;
    }
    
    // Enter active mode
    error = MMA8652_ActiveMode();
    return error;
}

uint32_t MMA8652_MotionSetup(uint8_t threshold, uint8_t debounce_count)
{
    uint32_t error;    
    
    error = MMA8652_StandByMode();
    if (error) {
        return error;
    }
   
    // Event values not latched, set motion OR freefal events on X, Y, Z-t nem
    error = MMA8652_Write(MMA8652_FF_MT_CFG, 0x58);
    if (error) {
        return error;
    }

    // Set debounce counter to increments/decrements, set acceleration threshold
    // 0 - 127, 7 bits, 0.063 g/LSB max range is +/-8 g
    error = MMA8652_Write(MMA8652_FF_MT_THS, threshold);
    if (error) {
        return error;
    }
    
    // Set debounce counter value
    // 0 - 255 8 bits 2.5 ms / step @ 400 Hz
    error = MMA8652_Write(MMA8652_FF_MT_COUNT, debounce_count);
    if (error) {
        return error;
    }
    
    
    // Enter active mode
    error = MMA8652_ActiveMode();
    return error;
}

uint32_t MMA8652_TransientSetup(uint8_t threshold, uint8_t debounce_count)
{
    uint32_t error;
    
    error = MMA8652_StandByMode();
    if (error) {
        return error;
    }
   
    // Event values not latched, set transient detection on X, Y, Z
    error = MMA8652_Write(MMA8652_TRANSIENT_CFG, 0x0E);
    if (error) {
        return error;
    }

    // set debounce counter to increments/decrements, set transient threshold
    // 0 - 127, 7 bits, 0.063 g/LSB max range is +/-8 g
    error = MMA8652_Write(MMA8652_TRANSIENT_THS, threshold);
    if (error) {
        return error;
    }
    
    // Set tranisent debounce counter value
    // 0 - 255 8 bits 2.5 ms / step @ 400 Hz
    error = MMA8652_Write(MMA8652_TRANSIENT_COUNT, debounce_count);
    if (error) {
        return error;
    }
    
    // Enter active mode
    error = MMA8652_ActiveMode();
    return error;
}

uint32_t MMA8652_WhoAmI(uint8_t* id)
{
    return MMA8652_Read(MMA8652_WHO_AM_I, id);
}

/* [] END OF FILE */  