/**
 * @file segmentanzeige.h
 * @author Finn Bechinka (finn.bechinka@fh-bielefeld.de)
 * @author Michel-Andre Witt (michel-andre.witt@fh-bielefeld.de)
 * @author Dennis Edler (dennis.edler@fh-bielefeld.de)
 * @brief TODO
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef segmentanzeige_H
#define segmentanzeige_H

/**
 * @brief Stellt einen Byte (8 Bit) dar.
 * 
 */
typedef unsigned char byte;

/**
 * @brief Stellt die Segmente der Anzeige dar.
 * 
 */
typedef enum segment
{
    SEG1 = 0,
    SEG2 = 1,
    SEG3 = 2,
    SEG4 = 3
} segment;

/**
 * @brief Stellt den Dezimalpunkt der Anzeige dar.
 * 
 */
typedef enum dot
{
    OFF = 0,
    ON = 1
} dot;

/**
 * @brief Stellt die Helligkeitstufen der Anzeige dar.
 * 
 */
typedef enum brightness
{
    DARK = 0,
    MEDIUM = 1,
    BRIGHT = 7
} brightness;

#endif