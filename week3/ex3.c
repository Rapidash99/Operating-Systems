#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct linked_list {
    struct node* head;
    int size;
};

void print_list(struct linked_list* list) {
    struct node* current = (*list).head;
    int i;
    for (i = 0; i < (*list).size; i++) {
        printf("%d ", current -> data);
        current = current -> next;
    }
    printf("\n");
}

void insert_node(struct linked_list* list, int data) {
    struct node* current = (*list).head;
    if ((*list).size == 0) {
        (*list).head = malloc(sizeof((*list).head));
        (*list).head -> data = data;
        (*list).head -> next = NULL;
    }
    else {
        int i;
        for (i = 1; i < (*list).size; i ++) {
            current = current -> next;
        }
        current -> next = malloc(sizeof(current -> next));
        current -> next -> data = data;
        current -> next -> next = NULL;
    }
    (*list).size++;
}

void delete_node(struct linked_list* list, int data) {
    struct node* current = (*list).head;
    int i;
    if (current -> data == data) {
        if (current -> next == NULL) {
            (*list).head = NULL;
            return;
        }
    }
    for (i = 1; i < (*list).size; i++) {
        if (current -> next -> data == data) {
            if (current -> next -> next == NULL) {
                current -> next = NULL;
            }
            else {
                current -> next = current -> next -> next;
            }
            return;
        }
    }
}

int main() {
    struct linked_list list;
    list.size = 0;
    list.head = NULL;

    insert_node(&list, 7);
    insert_node(&list, 4);
    insert_node(&list, 17);

    print_list(&list);

    delete_node(&list, 4);

    print_list(&list);

    return 0;
}
