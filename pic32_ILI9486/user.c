/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#ifdef __XC32
    #include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#endif

#include <plib.h>            /* Include to use PIC32 peripheral libraries     */
#include <stdint.h>          /* For uint32_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* TODO Initialize User Ports/Peripherals/Project here */

void InitApp(void)
{
    // LCD Backlight Low to Enable
    PORTSetPinsDigitalOut(IOPORT_G, BIT_14);
    PORTClearBits(IOPORT_G, BIT_14);

    // Configuring PMP Port
    unsigned int CONTROL = {PMP_OFF | PMP_IDLE_CON | PMP_MUX_OFF | PMP_ST |
                            PMP_READ_WRITE_EN | PMP_CS2_EN | PMP_LATCH_POL_LO |
                            PMP_CS2_POL_LO | PMP_WRITE_POL_HI};
    
    unsigned int MODE =    {PMP_IRQ_OFF | PMP_AUTO_ADDR_OFF | PMP_DATA_BUS_8 |
                            PMP_MODE_MASTER1 | PMP_WAIT_BEG_4 | PMP_WAIT_MID_1 |
                            PMP_WAIT_END_1};
    
    unsigned int PORT =    {PMP_PEN_7 | PMP_PEN_6 | PMP_PEN_5 | PMP_PEN_4 |
                            PMP_PEN_3 | PMP_PEN_2 | PMP_PEN_1 | PMP_PEN_0};
    
    unsigned int INTERRUPT = {PMP_INT_OFF | PMP_INT_PRI_7};

    mPMPOpen(CONTROL, MODE, PORT, INTERRUPT);
    Nop();
    Nop();
    Nop();
    mPMPEnable();
    
}

// EOF
