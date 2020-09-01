#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct linked_list {
    struct node *head;
};

void print_list(struct node *head) {
    struct node *current = head;

    if (current->value == -1) {
        printf("No elements in the list.\n");
        return;
    }

    printf("Current linked list:\n");
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void insert_node(struct node *head, int position, int value) {
    struct node *previous = NULL;
    struct node *current = head;

    // insert to the head
    if (position == 0) {
        if (head->value == -1) {
            head->value = value;
        } else {
            struct node *new_node = (struct node *) malloc(sizeof(struct node));
            new_node->value = head->value;
            new_node->next = head->next;
            head->value = value;
            head->next = new_node;
        }
        printf("Success!\n");
        return;
    }

    int counter = 0;
    while (current != NULL) {
        if (counter == position) { // insertion
            struct node *new_node = (struct node *) malloc(sizeof(struct node));
            new_node->value = value;
            new_node->next = current;
            previous->next = new_node;
            printf("Success!\n");
            return;
        } else {
            previous = current;
            current = current->next;
        }
        counter++;
    }

    // insert to the tail
    if (position == counter && previous->value != -1) {
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        new_node->value = value;
        new_node->next = NULL;
        previous->next = new_node;
        printf("Success!\n");
        return;
    }

    printf("Error. Invalid position.\n");
}

void delete_node(struct node *head, int position) {
    struct node *previous = NULL;
    struct node *current = head;

    // delete first node
    if (position == 0) {
        if (head->value == -1) {
            printf("Error. Invalid position.\n");
        } else {
            if (head->next == NULL) {
                head->value = -1;
            } else {
                head->value = head->next->value;
                head->next = head->next->next;
            }
        }
        printf("Success!\n");
        return;
    }

    // delete other nodes
    int counter = 0;
    while (current != NULL) {
        if (counter == position) {
            previous->next = current->next;
            printf("Success!\n");
            return;
        } else {
            previous = current;
            current = current->next;
        }
        counter++;
    }

    printf("Error. Invalid position.\n");
}

int main() {
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->value = -1;
    head->next = NULL;

    struct linked_list *my_linked_list = (struct linked_list *) malloc(sizeof(struct linked_list));
    my_linked_list->head = head;

    printf("Enter the number of operations you want to test, please\n");
    int n;
    scanf("%d", &n);

    printf("1 is for printing the list\n2 is for inserting to the list\n3 is for deleting from the list\n");

    for (int i = 0; i < n; i++) {
        printf("Enter the number of the current operation you want to test, please\n");
        int current;
        scanf("%d", &current);
        if (current == 1) {
            print_list(my_linked_list->head);
        } else if (current == 2) {
            printf("Enter the position (starting from 0) at which you want to insert the element, please\n");
            int position;
            scanf("%d", &position);

            printf("Enter the value of the element that you want to insert, please\n");
            int value;
            scanf("%d", &value);

            insert_node(my_linked_list->head, position, value);
        } else {
            printf("Enter the position (starting from 0) from which you want to delete the element, please\n");
            int position;
            scanf("%d", &position);

            delete_node(my_linked_list->head, position);
        }
    }

    return 0;
}
