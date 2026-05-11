#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node  {
    struct Node* next;
    char name[50];
    int score;

};

struct Node* add(struct Node* p, char* name, int score) {

    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (p == NULL) {
        return newNode;
    }

    struct Node* cur = p;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    return p;
}
struct Node* delete(struct Node *p, char* name) {
    if (p == NULL) {
        return NULL;
    }

    if (strcmp(p->name, name) == 0) {
        struct Node* temp = p->next;
        free(p);
        return temp;
    }

    struct Node* prev = p;
    struct Node* curr = p->next;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            prev->next = curr->next;
            free(curr);
            return p;
        }
        prev = curr;
        curr = curr->next;
    }
    return p;
}

void print(struct Node* p) {
    struct Node* cur = p;
    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}



int main() {
    char name[50];
    int score;
    char command[20];
    struct Node* head = NULL;

    while(1) {

        scanf("%s", command);

        if(strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            head = add(head, name, score);
        } else if(strcmp(command, "print") == 0) {
            print(head);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            head = delete(head, name);
        }
    }

    return 0;
}
