#include "deque.h"

dnode *new_dnode(void *data) {
    dnode *node = (dnode *)calloc(1, sizeof(dnode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

dnode *new_dnode_e(void *data, size_t sz) {
    dnode *node = (dnode *)calloc(1, sizeof(dnode));
    node->data = calloc(1, sz);
    memcpy(node->data, data, sz);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int deque_push_front(deque *d, void *data) {
    int rv = 1;
    dnode *node = new_dnode(data);
    pthread_mutex_lock(&d->lock);
    if (d->head == NULL && d->tail == NULL) {
        d->head = node;
        d->tail = node;
        d->sz++;
    } else if (d->head != NULL && d->tail != NULL) {
        d->head->prev = node;
        node->next = d->head;
        d->head = node;
        d->sz++;
    } else {
        rv = -1;
    }
    pthread_mutex_unlock(&d->lock);
    return rv;
}

int deque_push_back(deque *d, void *data) {
    int rv = 1;
    dnode *node = new_dnode(data);
    pthread_mutex_lock(&d->lock);
    if (d->head == NULL && d->head == NULL) {
        d->head = node;
        d->tail = node;
        d->sz++;
    } else if (d->tail != NULL && d->head != NULL) {
        d->tail->next = node;
        d->tail = node;
        d->sz++;
    } else {
        rv = -1;
    }
    pthread_mutex_unlock(&d->lock);
    return rv;
}

void *deque_pop_front(deque *d) {
    dnode *node = NULL;
    void *data = NULL;
    pthread_mutex_lock(&d->lock);
    if (d->head != NULL && d->tail != NULL) {
        node = d->head;
        d->head = d->head->next;
        data = node->data;
        free(node);
    }
    pthread_mutex_unlock(&d->lock);
    return data;
}

void *deque_pop_back(deque *d) {
    dnode *node = NULL;
    void *data = NULL;
    pthread_mutex_lock(&d->lock);
    if (d->head != NULL && d->tail != NULL) {
        node = d->tail;
        d->tail = d->tail->prev;
        data = node->data;
        free(node);
    }
    pthread_mutex_unlock(&d->lock);
    return data;
}

int deque_emplace_front(deque *d, void *data, size_t sz) {
    int rv = 1;
    dnode *node = new_dnode_e(data, sz);
    pthread_mutex_lock(&d->lock);
    if (d->head == NULL && d->tail == NULL) {
        d->head = node;
        d->tail = node;
        d->sz++;
    } else if (d->head != NULL && d->tail != NULL) {
        d->head->prev = node;
        node->next = d->head;
        d->head = node;
        d->sz++;
    } else {
        rv = -1;
    }
    pthread_mutex_unlock(&d->lock);
    return rv;
}

int deque_emplace_back(deque *d, void *data, size_t sz) {
    int rv = 1;
    dnode *node = new_dnode_e(data, sz);
    pthread_mutex_lock(&d->lock);
    if (d->head == NULL && d->tail == NULL) {
        d->head = node;
        d->tail = node;
        d->sz++;
    } else if (d->tail != NULL && d->head != NULL) {
        node->prev = d->tail;
        d->tail->next = node;
        d->tail = node;
        d->sz++;
    } else {
        rv = -1;
    }
    pthread_mutex_unlock(&d->lock);
    return rv;
}

deque *new_deque(void) {
    deque *d = (deque *)calloc(1, sizeof(deque));
    pthread_mutex_init(&d->lock, NULL);
    d->push_back = deque_push_back;
    d->push_front = deque_push_front;
    d->pop_back = deque_pop_back;
    d->pop_front = deque_pop_front;
    d->emplace_back = deque_emplace_back;
    d->emplace_front = deque_emplace_front;
    return d;
}

void delete_deque(deque *d) {
    pthread_mutex_destroy(&d->lock);
    free(d);
}