#ifndef PLIB_COMM_STRUCT_H
#define PLIB_COMM_STRUCT_H

/**
 * @file plib_comm_struct.h
 * @brief Définitions de structures pour communications
 * @author Ramiro Najera
 * @version 1.0.7
 * @date 2025-04-23
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/** 
 * @struct GPIO_t
 * @brief Structure de functions GPIO (set et reset)
 */
typedef struct 
{
    /** @brief Functions pour mettre à jour Chip Select à 1 */
    void(*Set)(void);
    /** @brief Functions pour mettre à jour Chip Select à 0 */
    void(*Clear)(void);
}GPIO_t;

/** 
 * @struct SPI_t
 * @brief Structure de configuration SPI
 */
typedef struct
{
    /** @brief Adresse SPI */
    uint8_t address;  /**< Adresse SPI */
    bool (*Write)(void* tx, size_t len);
    bool (*Read)(void* rx, size_t len);
    /** @brief Fonctions pour mettre à jour Chip Select */
    GPIO_t pinCS;
    /** @brief Fonctions pour mettre à jour Enable (Opto-coupler) */
    GPIO_t pinEN;
}SPI_t;

#endif  // PLIB_COMM_STRUCT_H