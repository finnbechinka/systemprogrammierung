/** @file segmentanzeige.h */

/**
 * Stellt einen Byte (8 Bit) dar.
 */
typedef unsigned char byte;

/**
 * Stellt die Segmente der Anzeige dar.
 */
enum segment
{
    SEG1 = 0,
    SEG2 = 1,
    SEG3 = 2,
    SEG4 = 3
};

/**
 * Stellt den Dezimalpunkt der Anzeige dar.
 */
enum dot
{
    OFF = 0,
    ON = 1
};

/**
 * Stellt die Helligkeitstufen der Anzeige dar.
 */
enum brightness
{
    DARK = 0,
    MEDIUM = 1,
    BRIGHT = 7
};