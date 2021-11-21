/**
 * @file speicherverwaltung.h
 * @author Finn Bechinka
 * @author Michel-Andre Witt
 * @brief TODO
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef speicherverwaltung_H
#define speicherverwaltung_H

/**
 * @brief Definiert die groesse des simulierten heaps.
 * 
 */
#define MEM_POOL_SIZE 4069
/**
 * @brief Bloecke werden als belegt makiert idem der next-Pointer diesen wert zugewiesen bekommt.
 * 
 */
#define MAGIC_INT 0xacdcacdc

/**
 * @brief Stellt die Verwaltungsstrucktur der Speicherblöcke dar. 
 * 
 */
typedef struct memblock 
{
size_t size;            // Für User nutzbare Länge des Blocks [Bytes]
struct memblock *next;  // Zeiger auf Anfang des nächsten freien Blocks (oder NULL)
unsigned short id;      // Fortlaufende und eindeutige Nummer des Blockes
} memblock;

/**
 * @brief Stellt den simulierten heap dar.
 * 
 */
extern char mempool[MEM_POOL_SIZE];
/**
 * @brief Zeigt auf den Anfang der Freispeicherliste.
 * 
 * Ist auf NULL gesetzt, wenn es keine freien Blöcke mehr gibt.
 */
extern memblock* freemem;

#endif