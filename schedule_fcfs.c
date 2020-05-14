//
// Created by Estefano Felipa on 5/13/20.
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "schedulers.h"
#include "cpu.h"

struct node *g_head = NULL;

void add(char *name, int priority, int burst) {
  Task *newTask = malloc(sizeof(Task));
  newTask->priority = priority;
  newTask->burst = burst;
  newTask->name = strdup(name);
  printf("--> Added: %s\n", name);
  insert(&g_head, newTask);
}

Task *pickNextTask() {
  if (!g_head)
    return NULL;
  Task *t = g_head->task;
  delete(&g_head, t);
  return t;
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
