#ifndef PLIB_ERROR_H
#define PLIB_ERROR_H

/**
 * @file plib_error.h
 * @brief Définitions des erreurs
 * @author Ramiro Najera
 * @version 1.0.8
 * @date 2025-11-07
 */

typedef struct
{
    unsigned char ioExpanders;
    unsigned char motorBridges;
    unsigned char pwmExpanders;
    unsigned char reserved;
}BoardErrors_t;

typedef union
{
    unsigned long raw;
    BoardErrors_t modules;
}BoardErrorsUnion_t;

#endif  // PLIB_ERROR_H