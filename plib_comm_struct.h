/**
 * @file plib_comm_struct.h
 * @author Ramiro Najera
 * @brief Définitions de structures nécessaires pour communication et périphériques
 * du microcontrôleur
 * @version 1.0.7
 * @date 2025-04-23
 */


#ifndef PLIB_COMM_STRUCT_H
#define PLIB_COMM_STRUCT_H

#include <stdint.h>     // uint_t variables
#include <stddef.h>     // size_t
#include <stdbool.h>    // bool

/** 
 * @struct GPIO_t
 * @brief Structure de functions pour périphérique GPIO
 */
typedef struct 
{
    void(*Set)(void);   /**< Function qui met GPIO à 1 */
    void(*Clear)(void); /**< Function qui met GPIO à 0 */
}GPIO_t;

/** 
 * @struct SPI_t
 * @brief Structure de configuration pour périphérique SPI
 */
typedef struct
{
    uint8_t address;  /**< Adresse SPI */
    bool (*Write)(void* tx, size_t len);    /**< Function qui écrit des données sur port SPI */
    bool (*Read)(void* rx, size_t len);     /**< Function qui lit des données du port SPI */
    GPIO_t pinCS;   /**< GPIO pour Chip Select */
    GPIO_t pinEN;   /**< GPIO pour Enable */
}SPI_t;

#endif  // PLIB_COMM_STRUCT_H