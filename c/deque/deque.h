#ifndef DEQUE_H
#define DEQUE_H

#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dnode {
    struct dnode *next;
    struct dnode *prev;
    void *data;
} dnode;

dnode *new_dnode(void *data);
dnode *new_dnode_e(void *data, size_t sz);

typedef struct deque {
    pthread_mutex_t lock;
    dnode *head;
    dnode *tail;
    size_t sz;
    int (*push_front)(struct deque *, void *);
    void *(*pop_back)(struct deque *);
    int (*push_back)(struct deque *, void *);
    void *(*pop_front)(struct deque *);
    int (*emplace_front)(struct deque *, void *, size_t sz);
    int (*emplace_back)(struct deque *, void *, size_t sz);
} deque;

deque *new_deque(void);
void delete_deque(deque *d);

#endif // DEQUE_H