/**
 * @file plib_delay.c
 * @brief Définitions des fonctions de délai
 * @author Ramiro Najera
 * @version 1.0.7
 * @date 2025-04-23
 */

#include <xc.h>
#include "plib_delay.h"

void Wait100ns(uint32_t ns100)
{
    for (uint32_t i = 0; i < ns100; i++)
    {
        asm("nop");
    }
}

void Wait1us(uint32_t us)
{
    for (uint32_t i = 0; i < us; i++)
    {
        for (uint32_t j = 0; j < 10; j++)
        {
            asm("nop");
        }
    }
}


uint16_t ResetPIC()
{
    /* Perform a system unlock sequence */
    SYSKEY = 0xaa996655; // write first unlock key to SYSKEY
    SYSKEY = 0x556699aa; // write second unlock key to SYSKEY
    /* Set SWRST bit to arm reset */
    RSWRSTSET = 1;
    /* Read RSWRST register to trigger reset */
    uint16_t dummy;
    dummy = RSWRST;
    /* Prevent any unwanted code execution until reset occurs*/
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    // Return dummy to avoid compilation warning
    return dummy;
}