#include <stdbool.h>

typedef struct Student {
    int id;
    char name[50];
    int score;
    struct Student *next;
} Student;

bool isEmpty(Student *s);
Student* addStudent(Student **head, int id, char *name, int score);
void deleteStudent(Student **head, int id);
void printStudent(Student *head);
void eraseStudentList(Student **head);
void saveToFile(Student *head, const char *filename);
void loadFromFile(Student **head, const char *filename);
