//
// Created by Estefano Felipa on 5/14/20.
//

//
// Created by Estefano Felipa on 5/14/20.
//

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "schedulers.h"
#include "cpu.h"

struct node *g_head = NULL;

bool comesBefore(Task *a, Task *b) {
  if (a->priority != b->priority)
    return a->priority > b->priority;
  return strcmp(a->name, b->name) < 0;
}

// based on traverse from list.c
// finds the task whose name comes first in dictionary
Task *pickNextTask() {
  // if list is empty, nothing to do
  if (!g_head)
    return NULL;

  struct node *temp;
  temp = g_head;
  Task *best_sofar = temp->task;

  while (temp != NULL) {
    if (comesBefore(temp->task, best_sofar))
      best_sofar = temp->task;
    temp = temp->next;
  }
  // delete the node from list, Task will get deleted later
  delete(&g_head, best_sofar);
  return best_sofar;
}

void add(char *name, int priority, int burst) {
  Task *newTask = malloc(sizeof(Task));
  newTask->priority = priority;
  newTask->burst = burst;
  newTask->name = strdup(name);
  printf("--> Added: %s\n", name);
  insert(&g_head, newTask);
}

void schedule() {
  int current_time = 0;
  Task *task = pickNextTask();
  while (task) {
    run(task, task->burst);
    current_time += task->burst;
    printf("\tTime is now: %d\n", current_time);
    free(task->name);
    free(task);
    task = pickNextTask();

  }
}
