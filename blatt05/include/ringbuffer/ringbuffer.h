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

typedef struct ringbuffer
{
    size_t size, count, head;
    void **elems;
    void (*free_callback)(void *p);
} ring_buffer;

int free_buffer(ring_buffer *cb);
void write_buffer(ring_buffer *cb, void *data);
void *read_buffer(ring_buffer *cb);

#endif ringbuffer_H