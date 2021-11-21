/**
 * @file ringbuffer.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <ringbuffer.h>

void free_callback(void *p)
{
    free(p);
}

ring_buffer *init_buffer(const size_t n, void (*f)(void *p)) 
{
    void *array = (void*) malloc(n * sizeof(void));
    ring_buffer *buffer = (ring_buffer*) malloc(sizeof(ring_buffer));

    buffer->free_callback = f;
    buffer->elems = array;
    buffer->size = n;
    buffer->head = 0;
    buffer->count = 0;

    return buffer;
}

void *read_buffer(ring_buffer *cb)
{
    if(cb->count == 0)
    {
        return NULL;
    }
    if(cb->count > 0)
    {
        cb->count = cb->count -1;
        void* tmp = cb->elems[cb->head];
        if(cb->head == cb->size -1)
        {
            cb->head = 0;
        }else
        {
            cb->head= cb->head +1;
        }
        return tmp;
    }
}

void write_buffer(ring_buffer *cb, void *data)
{
    if(cb->count == cb->size)
    {
        cb->free_callback(cb->elems[cb->head]);
        cb->elems[cb->head] = data;
    }
    if(cb->count < cb->size)
    {
        size_t x = cb->head + cb->count;
        if(x > cb->size)
        {
            x = x - cb->size;
        }

        cb->elems[x] = data;

        cb->count = cb->count +1;
    }
}

int free_buffer(ring_buffer *cb)
{
    int i;
    for(i = 0; i < cb->size; i++)
    {
        cb->free_callback(cb->elems[i]);
    }
    free(cb);
}