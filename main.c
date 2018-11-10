#include <stdint.h>
#include <inttypes.h>
#include "device.h"
#include "MMA8652.h"

CY_ISR_PROTO(ACC_ISR_Hadler);

volatile uint8_t flag;

CY_ISR(ACC_ISR_Handler)
{
    uint8_t pin;
    
    flag = 0;
    
    // Reset interrupt components
    pin = ACC_ClearInterrupt();
    ACC_ISR_ClearPending();

    // Interrupt on ACC_INT2
    if (pin & 0x01) {
        
        // Put your code here
        flag = 2; 
        
        int16_t acc;
        uint32_t error;
        
        char tmp[100];
        
        error = MMA8652_ReadAcc(&acc);
        int16_t* accel=&acc;
        
        sprintf(tmp, "flag: %d x: %d, y: %d z: %d error: %" PRIu32 "\n" "\r" ,flag, accel[0], accel[1], accel[2] , error);
        
        UART_UartPutString(tmp);
        
        
    }
    
    // Interrupt on ACC_INT1
    if (pin & 0x02) {
        
        // Put your code here
        flag = 1;
    }
}


int main(void)
{
    CyGlobalIntEnable;
    
    // Start basic components
    UART_Start();
    I2C_Start();
   
   
    // Register interrupt handler function
    ACC_ISR_StartEx(ACC_ISR_Handler);
    
    
    MMA8652_Initialize();
    MMA8652_MotionSetup(1,3);
    
        
    
    
    
    // Main loop
    for(;;) {
        
        //unsigned int i;
        //uint32_t error;
        //uint8_t id;
        //int16_t acc;
        
        //char tmp[100];
        
        //error = MMA8652_ReadAcc(&acc);
        //int16_t* accel=&acc;
       
       
        //error = MMA8652_WhoAmI(&id);
        
        //sprintf(tmp, "flag: %d, id: %d, error: %" PRIu32 "\n", flag, id, error);
        
        //sprintf(tmp, "flag: %d x: %d, y: %d z: %d error: %" PRIu32 "\n" "\r" ,flag, accel[0], accel[1], accel[2] , error);
        
        //sprintf(tmp,"flag: %d" "\n" , flag);
        
        //UART_UartPutString(tmp);
        //RELAY1_Write(!RELAY1_Read());
       
        
        
        //CyDelay(500);
        
    }

    

    return 0;
}
