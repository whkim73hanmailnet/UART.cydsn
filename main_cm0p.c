/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR); 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    mUART_Start();
    for(;;)
    {
        static float angle;
        angle++;
        if(angle >= 360) angle -= 360;
        int value = sin(angle * 3.14 / 180) * 100;
        int value2 = cos(angle * 3.14 / 180) * 100;
        printf("%d\t%d\n\r", value, value2);
        CyDelay(10);
    }
}

/* [] END OF FILE */
