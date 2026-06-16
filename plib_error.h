#ifndef PLIB_ERROR_H
#define PLIB_ERROR_H

/**
 * @file plib_error.h
 * @brief Définitions des erreurs
 * @author Ramiro Najera
 * @version 1.0.7
 * @date 2025-11-07
 */

#include <stdint.h>

typedef struct
{
    uint8_t error0;
    uint8_t error1;
    uint8_t error2;
    uint8_t error3;
}ErrorCode_t;

typedef union
{
    ErrorCode_t code;
    uint32_t raw;
}ErrorCodeUnion_t;

#endif  // PLIB_ERROR_H