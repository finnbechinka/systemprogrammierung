/**
 * @file ringbuffer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ringbuffer_H
#define ringbuffer_H

#include <stdlib.h>

/**
 * @brief Stellt den ringbuffer dar.
 * 
 */

typedef struct ringbuffer
{
    size_t size, count, head;
    void **elems;
    void (*free_callback)(void *p);
} ring_buffer;

/**
 * @brief initialisiert den ringbuffer.
 * 
 * @param n 
 * @param f 
 * @return ring_buffer* 
 */
ring_buffer *init_buffer(const size_t n, void (*f)(void *p));

/**
 * @brief gibt das aelteste element aus dem buffer zurueck.
 * 
 * @param cb 
 * @return void* 
 */
void *read_buffer(ring_buffer *cb);

/**
 * @brief fuegt ein element in den buffer ein.
 * 
 * @param cb 
 * @param data 
 */
void write_buffer(ring_buffer *cb, void *data);

/**
 * @brief leert den buffer.
 * 
 * @param cb 
 * @return int 
 */
int free_buffer(ring_buffer *cb);

#endif