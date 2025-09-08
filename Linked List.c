#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
struct Node {
    char roll_number[20];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(const char* roll_number) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newNode->roll_number, roll_number, sizeof(newNode->roll_number) - 1);
    newNode->roll_number[sizeof(newNode->roll_number) - 1] = '\0'; // Ensure null-termination
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void append(struct Node** head, const char* roll_number) {
    struct Node* newNode = createNode(roll_number);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to traverse and display the linked list with corrected spacing
void display(struct Node* head) {
    printf("Roll Numbers in Linked List: ");
    struct Node* current = head;

    // Check if the list is not empty
    if (current != NULL) {
        printf("%s", current->roll_number);
        current = current->next;
    }

    // Now, loop through the rest of the list and add the " → "
    while (current != NULL) {
        printf(" → %s", current->roll_number);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    // Your roll number
    const char* my_roll_number = "CS101";
    append(&head, my_roll_number);

    // Roll numbers of your team members
    const char* team_members[] = {"CS102", "CS103", "CS104"};
    int num_members = sizeof(team_members) / sizeof(team_members[0]);
    int i;
    for (i = 0; i < num_members; i++) {
        append(&head, team_members[i]);
    }

    // Display the linked list
    display(head);

    // Free the allocated memory
    freeList(&head);

    return 0;
}
