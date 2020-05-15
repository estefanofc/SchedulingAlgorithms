//
// Created by Estefano Felipa on 5/13/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "schedulers.h"
#include "cpu.h"

struct node *g_head = NULL;

// based on traverse from list.c
// finds the task whose name comes first in dictionary
Task *pickNextTask() {
  // if list is empty, nothing to do
  if (!g_head)
    return NULL;
  struct node *temp;
  temp = g_head;
  Task *best_sofar = temp->task;
  // delete the node from list, Task will get deleted later
  delete(&g_head, best_sofar);
  return best_sofar;
}

//adds task to list in sorted order
void add(char *name, int priority, int burst) {
  Task *newTask = malloc(sizeof(Task));
  newTask->priority = priority;
  newTask->burst = burst;
  newTask->name = strdup(name);
  printf("--> Added: %s\n", name);
  insert(&g_head, newTask);
}

//Round-robin (RR) scheduling, where each task is run for a time quantum (or
// for the remainder of its CPU burst).
void schedule() {
  int current_time = 0;
  int slice;
  Task *task = pickNextTask();
  while (task) {
    if (task->burst <= QUANTUM) {
      slice = task->burst;
    } else {
      slice = QUANTUM;
      Task *remainder = malloc(sizeof(Task));
      remainder->priority = task->priority;
      remainder->burst = task->burst - QUANTUM;
      remainder->name = strdup(task->name);
      insertEnd(&g_head, remainder);
    }
    run(task, slice);
    current_time += slice;
    printf("\tTime is now: %d\n", current_time);
    free(task->name);
    free(task);
    task = pickNextTask();
  }
}
