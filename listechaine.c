#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    char data[50];
    struct Element* next;
};

struct Element* createNode(char* value) {
    struct Element* newNode = (struct Element*)malloc(sizeof(struct Element));
    strcpy(newNode->data, value);
    newNode->next = NULL;
    return newNode;
}

void append(struct Element** headRef, char* value) {
    struct Element* newNode = createNode(value);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Element* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void prepend(struct Element** headRef, char* value) {
    struct Element* newNode = createNode(value);
    newNode->next = *headRef;
    *headRef = newNode;
}

void displayList(struct Element* head) {
    while (head != NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void deleteList(struct Element** headRef) {
    struct Element* current = *headRef;
    struct Element* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

int main() {
    struct Element* head = NULL;

    append(&head, "Pomme");
    append(&head, "Banane");
    prepend(&head, "Orange");

    printf("Liste des fruits : ");
    displayList(head);

    deleteList(&head);

    return 0;
}
