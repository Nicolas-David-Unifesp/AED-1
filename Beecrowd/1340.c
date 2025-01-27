/*
  * nome: 1340.c
  * descrição: Eu Posso Advinhar a Estrutura de Dados
  * data: 27/01/2025
  *Resolvido por Nicolas David da Cruz Santos
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_OPERATIONS 1000

typedef struct {
    int arr[MAX_OPERATIONS];
    int top;
} Stack;

void stack_init(Stack *s) {
    s->top = -1;
}

bool stack_push(Stack *s, int value) {
    if (s->top >= MAX_OPERATIONS - 1) return false;
    s->arr[++(s->top)] = value;
    return true;
}

bool stack_pop(Stack *s, int *value) {
    if (s->top == -1) return false;
    *value = s->arr[(s->top)--];
    return true;
}

typedef struct {
    int arr[MAX_OPERATIONS];
    int front, rear;
} Queue;

void queue_init(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

bool queue_push(Queue *q, int value) {
    if (q->rear >= MAX_OPERATIONS - 1) return false;
    q->arr[++(q->rear)] = value;
    return true;
}

bool queue_pop(Queue *q, int *value) {
    if (q->front > q->rear) return false;
    *value = q->arr[(q->front)++];
    return true;
}

typedef struct {
    int arr[MAX_OPERATIONS];
    int size;
} PriorityQueue;

void pq_init(PriorityQueue *pq) {
    pq->size = 0;
}

void pq_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pq_heapify_up(PriorityQueue *pq, int index) {
    while (index > 0 && pq->arr[(index - 1) / 2] < pq->arr[index]) {
        pq_swap(&pq->arr[(index - 1) / 2], &pq->arr[index]);
        index = (index - 1) / 2;
    }
}

bool pq_push(PriorityQueue *pq, int value) {
    if (pq->size >= MAX_OPERATIONS) return false;
    pq->arr[pq->size] = value;
    pq_heapify_up(pq, pq->size);
    pq->size++;
    return true;
}

void pq_heapify_down(PriorityQueue *pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < pq->size && pq->arr[left] > pq->arr[largest]) largest = left;
    if (right < pq->size && pq->arr[right] > pq->arr[largest]) largest = right;

    if (largest != index) {
        pq_swap(&pq->arr[largest], &pq->arr[index]);
        pq_heapify_down(pq, largest);
    }
}

bool pq_pop(PriorityQueue *pq, int *value) {
    if (pq->size == 0) return false;
    *value = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    pq_heapify_down(pq, 0);
    return true;
}

int main() {
    int n, op, x;
    while (scanf("%d", &n) != EOF) {
        Stack stack;
        Queue queue;
        PriorityQueue pq;

        stack_init(&stack);
        queue_init(&queue);
        pq_init(&pq);

        bool is_stack = true, is_queue = true, is_pq = true;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d", &x);
                if (is_stack) stack_push(&stack, x);
                if (is_queue) queue_push(&queue, x);
                if (is_pq) pq_push(&pq, x);
            } else if (op == 2) {
                scanf("%d", &x);
                int value;
                if (is_stack) {
                    if (!stack_pop(&stack, &value) || value != x) is_stack = false;
                }
                if (is_queue) {
                    if (!queue_pop(&queue, &value) || value != x) is_queue = false;
                }
                if (is_pq) {
                    if (!pq_pop(&pq, &value) || value != x) is_pq = false;
                }
            }
        }

        if (is_stack && !is_queue && !is_pq) {
            printf("stack\n");
        } else if (!is_stack && is_queue && !is_pq) {
            printf("queue\n");
        } else if (!is_stack && !is_queue && is_pq) {
            printf("priority queue\n");
        } else if (is_stack || is_queue || is_pq) {
            printf("not sure\n");
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}
