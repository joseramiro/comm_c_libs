/**
 * @file plib_delay.h
 * @brief Définitions des fonctions de délai
 * @author Ramiro Najera
 * @version 1.0.7
 * @date 2025-04-23
 */

#ifndef PLIB_DELAY_H
#define PLIB_DELAY_H

#include <stdint.h>

/**
 * @brief Fonction de délai en 100 ns
 * @param ns100 100 ns d'attente
 */
void Wait100ns(uint32_t ns100);

/**
 * @brief Fonction de délai en µs
 * @param us µs d'attente
 */
void Wait1us(uint32_t us);

/**
 * @brief Fonction pour rédemarrer PIC
 * @return unsigned int Lecture de registre reset
 */
uint16_t ResetPIC();

#endif  // PLIB_DELAY_H