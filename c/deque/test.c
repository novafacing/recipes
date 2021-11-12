#include "deque.h"

#include <assert.h>

void test_emplace_pop(void) {
    deque *dq = new_deque();
    for (size_t i = 0; i < 16; i++) {
        dq->emplace_back(dq, &i, sizeof(i));
    }
    for (size_t i = 0; i < 16; i++) {
        void *d = dq->pop_front(dq);
        assert(d != NULL);
        assert(*(size_t *)d == i);
        free(d);
    }
    delete_deque(dq);
}

void test_push_pop(void) {
    const char *test = "TEST STRING";
    deque *dq = new_deque();
    for (size_t i = 0; i < 16; i++) {
        dq->push_front(dq, strdup(test));
    }
    for (size_t i = 0; i < 16; i++) {
        void *d = dq->pop_back(dq);
        assert(d != NULL);
        assert(strcmp(test, d) == 0);
        free(d);
    }
    delete_deque(dq);
}

void test_both_ends(void) {
    deque *dq = new_deque();
    size_t ctr = 0;
    for (size_t i = 0; i < 8; i++) {
        dq->emplace_front(dq, &ctr, sizeof(ctr));
        ctr++;
        dq->emplace_back(dq, &ctr, sizeof(ctr));
        ctr++;
    }
    for (size_t i = 0; i < 8; i++) {
        void *f = dq->pop_front(dq);
        void *b = dq->pop_back(dq);
        assert(f != NULL);
        assert(b != NULL);
        assert(*(size_t *)f == (*(size_t *)b) - 1);
        free(f);
        free(b);
    }
    delete_deque(dq);
}

int main(void) {
    test_emplace_pop();
    test_push_pop();
    test_both_ends();
    return 0;
}