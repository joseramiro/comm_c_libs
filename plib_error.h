#ifndef PLIB_ERROR_H
#define PLIB_ERROR_H

/**
 * @file plib_error.h
 * @brief Définitions des erreurs
 * @author Ramiro Najera
 * @version 1.0.7
 * @date 2025-11-07
 */

typedef struct
{
    unsigned char error0;
    unsigned char error1;
    unsigned char error2;
    unsigned char error3;
}ErrorCode_t;

typedef union
{
    ErrorCode_t code;
    unsigned long raw;
}ErrorCodeUnion_t;

#endif  // PLIB_ERROR_H