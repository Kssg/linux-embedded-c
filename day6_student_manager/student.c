#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "student.h"

bool isEmpty(Student *s) {
    return s == NULL;
}

Student* addStudent(Student **head, int id, char *name, int score) {
    Student *newStudent = malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);  // fix
    newStudent->score = score;
    newStudent->next = NULL;

    while (*head) {
        head = &((*head)->next);    
    }
    *head = newStudent;
    return newStudent;
}

void deleteStudent(Student **head, int id) {
    if (isEmpty(*head)) {
        printf("\n*** No Student! ***\n");
        return;
    }
    while(*head && (*head)->id != id) {
        head = &(*head)->next; 
    }

    if (*head == NULL) {
        printf("\n*** Student not found! ***\n");
        return;
    }
    printf("\n*** Delete student %s! ***\n", (*head)->name);
    Student *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void printStudent(Student *head) {
    if (isEmpty(head)) {
        printf("\n*** No student to print! ***\n");
        return;
    }
    printf("\n=== Student Infomation ===\n\n");
    while (head) {
        printf("Id: %d, Name: %s, Score: %d\n",
                head->id, head->name, head->score);
        head = head->next;
    }
}

void eraseStudentList(Student **head) {
    if (isEmpty(*head)) {
        printf("\n*** Student list is empty! ***\n");
        return;
    }
    Student *tmp;
    while (*head) {
        tmp = *head;
        *head = (*head)->next;  // 我為何用 head = &(*head)->next; 指標指標
        free(tmp);
    }
    *head = NULL;
    printf("\n*** Clear all student list! ***\n\n");
}

void saveToFile(Student *head, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("\n*** Error opening file while writing! ***\n");
        return;
    }

    fprintf(fp, "ID,Name,Score\n");
    for (Student *cur = head; cur != NULL; cur = cur->next) {
        fprintf(fp, "%d,%s,%d\n", cur->id, cur->name, cur->score);
    }

    fclose(fp);
    printf("\n*** Data saved to %s ***\n", filename);
}

void loadFromFile(Student **head, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("\n*** No existing file found. Starting fresh. ***\n");
        return;
    }

    char line[256];
    fgets(line, sizeof(line), fp);

    int id, score;
    char name[256];

    while (fscanf(fp, "%d,%99[^,],%d\n", &id, name, &score) == 3) {
        addStudent(head, id, name, score);
    }
    
    fclose(fp);
    printf("\n*** Data loaded from %s ***\n", filename);
}
