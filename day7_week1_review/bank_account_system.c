#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Transaction {
    char type[10];  // "deposit" or "withdraw"
    int amount;
    struct Transaction *next;
} Transaction;

typedef struct {
    int balance;
    Transaction *history;
} Account;

void addTransaction(Account *a, const char *type, int amount) {
    Transaction *new_trans = malloc(sizeof(Transaction));
    strcpy(new_trans->type, type);
    new_trans->amount = amount;
    new_trans->next = NULL;

    Transaction **indirect = &a->history;
    while (*indirect) {
        indirect = &((*indirect)->next);
    }
    *indirect = new_trans;
}

void deposit(Account *a, int amount) {
    addTransaction(a, "deposit", amount);
    a->balance += amount;
}

void withdraw(Account *a, int amount) {
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    if (a->balance < amount) {
        printf("Insufficient balance!\n");
        return;
    }
    addTransaction(a, "withdraw", amount);
    a->balance -= amount;
}

void printHistory(Account *a) {
    Transaction *cur = a->history;
    while (cur) {
        if (strcmp(cur->type, "deposit") == 0) {
            printf("[%s] +%d\n", cur->type, cur->amount);
        } else if (strcmp(cur->type, "withdraw") == 0) {
            printf("[%s] -%d\n", cur->type, cur->amount);
        }
        cur = cur->next;
    }
}

void clearHistory(Account *a) {
    Transaction *cur = a->history;
    while (cur) {
        Transaction *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    a->history = NULL;  // ✅ 防止懸掛指標 (dangling pointer)
    printf("Clear all list\n");
}

void saveToFile(Account *a, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    Transaction *cur = a->history;
    while (cur) {
        fprintf(fp, "%s %d\n", cur->type, cur->amount);
        cur = cur->next;
    } 
    fprintf(fp, "BALANCE %d\n", a->balance);
    fclose(fp);
}

void loadFromFile(Account *a, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    char type[10];
    int amount;
    while (fscanf(fp, "%s %d", type, &amount) == 2) {
        if (strcmp(type, "deposit") == 0)
            deposit(a, amount);
        else if (strcmp(type, "withdraw") == 0)
            withdraw(a, amount);
        else if (strcmp(type, "BALANCE") == 0)
            a->balance = amount;
    }
    fclose(fp);
}

int main() {
    Account acc = {0, NULL};
    deposit(&acc, 500);
    withdraw(&acc, 200);
    printHistory(&acc);
    printf("Balance: %d\n", acc.balance);
    saveToFile(&acc, "transaction.txt");
    clearHistory(&acc);
}
