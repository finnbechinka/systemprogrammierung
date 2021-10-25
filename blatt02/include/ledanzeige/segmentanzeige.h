/** @file segmentanzeige.h */
#ifndef segmentanzeige_H
#define segmentanzeige_H
/**
 * Stellt einen Byte (8 Bit) dar.
 */
typedef unsigned char byte;

/**
 * Stellt die Segmente der Anzeige dar.
 */
typedef enum segment
{
    SEG1 = 0,
    SEG2 = 1,
    SEG3 = 2,
    SEG4 = 3
} segment;

/**
 * Stellt den Dezimalpunkt der Anzeige dar.
 */
typedef enum dot
{
    OFF = 0,
    ON = 1
} dot;

/**
 * Stellt die Helligkeitstufen der Anzeige dar.
 */
typedef enum brightness
{
    DARK = 0,
    MEDIUM = 1,
    BRIGHT = 7
} brightness;

#endif