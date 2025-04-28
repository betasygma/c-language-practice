/*
 * =============================
 * PRIORITY QUEUE IMPLEMENTATION
 * -----------------------------
 * Description:
 * This program implements a dynamic priority queue using an array.
 * Each job has a job number and a priority (lower number = higher priority).
 * Jobs are inserted into the queue maintaining priority order.
 * 
 * Specifications:
 * - Maximum number of jobs: theoretically unlimited (dynamically resized).
 * - Priority order: lower number means higher priority.
 * - Job numbers may not be unique (duplicates allowed).
 * - Memory is managed dynamically using malloc/realloc.
 * - If multiple jobs have the same priority, the one that was added earlier will be placed earlier in the queue (FIFO for equal priorities).
 * 
 * Functions:
 *  - initQueue       : Initializes an empty queue.
 *  - addJob          : Adds a new job in its correct priority order.
 *  - removeHead      : Removes the job with the highest priority.
 *  - removeJob       : Removes ALL jobs with a given job number.
 *  - printQueue      : Prints the contents of the queue.
 *  - freeQueue       : Frees memory used by the queue.
 * ======================================
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int job_number, priority;
} Job;

typedef struct {
    Job *data;
    int size, capacity;
} PriorityQueue;

void initQueue(PriorityQueue *q);
void resizeQueue(PriorityQueue *q);
void addJob(PriorityQueue *q, int job_number, int priority);
void removeHead(PriorityQueue *q);
void removeJob(PriorityQueue *q, int job_number);
void printQueue(PriorityQueue *q);
void freeQueue(PriorityQueue *q);

int main() {
    PriorityQueue queue;
    initQueue(&queue);

    // add some jobs
    addJob(&queue, 301, 3);
    addJob(&queue, 304, 2);
    addJob(&queue, 302, 1);
    addJob(&queue, 303, 2);
    addJob(&queue, 304, 4);
    printQueue(&queue);
    printf("\n");

    // remove head (the highest priority job)
    removeHead(&queue);
    printQueue(&queue);
    printf("\n");

    // remove all jobs with job number 304
    removeJob(&queue, 304);
    printQueue(&queue);
    printf("\n");

    // try removing a job that does not exist
    removeJob(&queue, 999);
    printQueue(&queue);
    printf("\n");

    // add more jobs
    addJob(&queue, 305, 0);
    addJob(&queue, 306, 5);
    printQueue(&queue);

    freeQueue(&queue);
    return 0;
}

void initQueue(PriorityQueue *q) {
    q->capacity = 10;
    q->size = 0;
    q->data = (Job*) malloc(sizeof(Job) * q->capacity);
}

void resizeQueue(PriorityQueue *q) {
    q->capacity *= 2;
    q->data = (Job*) realloc(q->data, sizeof(Job) * q->capacity);
}

void addJob(PriorityQueue *q, int job_number, int priority) {
    if (q->size == q->capacity) resizeQueue(q);

    int i = q->size - 1;
    while (i >= 0 && q->data[i].priority > priority) {
        q->data[i + 1] = q->data[i];
        i--;
    }

    q->data[i + 1].job_number = job_number;
    q->data[i + 1].priority = priority;
    q->size++;
}

void removeHead(PriorityQueue *q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Removing job %d (Priority %d)\n", q->data[0].job_number, q->data[0].priority);

    for (int i = 1; i < q->size; i++) {
        q->data[i - 1] = q->data[i];
    }
    q->size--;
}

void removeJob(PriorityQueue *q, int job_number) {
    int i = 0, found = 0;
    while (i < q->size) {
        if (q->data[i].job_number == job_number) {
            for (int j = i + 1; j < q->size; j++) {
                q->data[j - 1] = q->data[j];
            }
            q->size--;
            found = 1;
        } else {
            i++;
        }
    }

    if (found) printf("All jobs with job number %d have been removed from queue.\n", job_number);
    else printf("No job with job number %d found in the queue.\n", job_number);
}

void printQueue(PriorityQueue *q) {
    if (q->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue contents:\n");
    for (int i = 0; i < q->size; i++) {
        printf("  Job %d (Priority %d)\n", q->data[i].job_number, q->data[i].priority);
    }
}

void freeQueue(PriorityQueue *q) {
    free(q->data);
}