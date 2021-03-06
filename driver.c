/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE    100

int main(int argc, char *argv[]) {
  FILE *in;
  char *temp;
  char task[SIZE];

  char *name;
  int priority;
  int burst;
  if (argc != 2) {
    printf("usage: %s <schedule-file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  in = fopen(argv[1], "r");

  while (fgets(task, SIZE, in) != NULL) {
    temp = strdup(task);
    char *orinal_copy = temp;
    name = strsep(&temp, ",");
    priority = atoi(strsep(&temp, ","));
    burst = atoi(strsep(&temp, ","));

    // add the task to the scheduler's list of tasks
    add(name, priority, burst);

    free(orinal_copy);
  }

  fclose(in);

  // invoke the scheduler
  schedule();
  printf("Done\n");

  return 0;
}
