#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main() {
    Student *s = NULL;

    while (1) {
        printf("\n================\n1. Add student\n");
        printf("2. Delete student\n");
        printf("3. Print all studnet\n");
        printf("4. Save to csv file\n");
        printf("5. Load from csv file\n");
        printf("6. Exit\n================\n");

        int index;
        printf("What to do? "); scanf("%d", &index);

        switch (index) {
            case 1: {
                printf("Please enter student info\n");
                int id, score;
                char name[100];
                printf("ID: "); scanf("%d", &id);
                // scanf 不會吃掉 \n
                getchar();
                // 原本方式
                printf("Name: "); 
                // scanf("%s", name);
                // 改進方式一
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                // 改進方式二
                // scanf(" %99[^\n]", name);
                printf("Score: "); scanf("%d", &score);
                addStudent(&s, id, name, score);
                break;
            }
            case 2: {
                if (isEmpty(s)) {
                    printf("\n*** No student to delete! ***\n");
                    break;
                }
                printf("Enter student id to delete: ");
                int deleteId; scanf("%d", &deleteId);
                deleteStudent(&s, deleteId);
                break;
            }
            case 3:
                printStudent(s);
                break;
            case 4:
                saveToFile(s, "students.csv");
                break;
            case 5:
                loadFromFile(&s, "students.csv");
                break;
            case 6:
                if (!isEmpty(s)) {
                    eraseStudentList(&s);
                }
                return 0;
            default:
               printf("Invalid input!\n");
               break;
        }
    }
}
