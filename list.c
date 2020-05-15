/**
 * Various list operations
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"

// add a new task to the list of tasks
void insert(struct node **head, Task *newTask) {
  // add the new task to the list
  struct node *newNode = malloc(sizeof(struct node));
  newNode->task = newTask;
  if (*head == NULL || strcmp(newNode->task->name, (*head)->task->name) <= 0) {
    newNode->next = *head;
    *head = newNode;
  } else {
    struct node *curr = *head;
    while (curr->next != NULL && strcmp(curr->task->name, newNode
        ->task->name) <= 0) {
      curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
  }
}

// add a new task to the list of tasks
void insertEnd(struct node **head, Task *newTask) {
  // add the new task to the list
  struct node *newNode = malloc(sizeof(struct node));
  newNode->task = newTask;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
  } else {
    struct node *curr = *head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

// delete the selected task from the list
void delete(struct node **head, Task *task) {
  struct node *temp;
  struct node *prev;
  struct node *todelete;

  temp = *head;
  // special case - beginning of list
  if (strcmp(task->name, temp->task->name) == 0) {
    todelete = *head;
    *head = (*head)->next;
  } else {
    // interior or last element in the list
    prev = *head;
    temp = temp->next;
    while (strcmp(task->name, temp->task->name) != 0) {
      prev = temp;
      temp = temp->next;
    }
    todelete = temp;
    prev->next = temp->next;
  }
  free(todelete);
}

// traverse the list
void traverse(struct node *head) {
  struct node *temp;
  temp = head;

  while (temp != NULL) {
    printf("[%s] [%d] [%d]\n",
           temp->task->name,
           temp->task->priority,
           temp->task->burst);
    temp = temp->next;
  }
}
