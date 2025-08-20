/*Write a menu-driven C program using structures to implement the following operations on a
singly linked list:
➢ Insert an element before another specified element in the list
(Example: Insert 10 before 25)
➢ Insert an element after another specified element in the list
(Example: Insert 40 after 25)
➢ Delete a specified element from the list
(Example: Delete node containing 15)
➢ Traverse the list and display all elements
➢ Reverse the linked list
(Modify the links such that the list is reversed)
➢ Sort the list in ascending order
(Using Bubble Sort or any appropriate algorithm on linked list)
➢ Delete every alternate node in the list
(Starting from the second node)
➢ Insert an element into a sorted linked list while maintaining the sorted order
(Example: Insert 28 into a list that is already sorted)
Requirements
Use dynamic memory allocation (malloc/free) for node creation and deletion.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert before specified element
void insertBefore(struct Node** head, int dataToInsert, int beforeData) {
    struct Node* newNode = createNode(dataToInsert);

    if (*head == NULL) {
        printf("List is empty. Cannot insert before %d\n", beforeData);
        free(newNode);
        return;
    }

    if ((*head)->data == beforeData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* prev = NULL;
    struct Node* curr = *head;

    while (curr != NULL && curr->data != beforeData) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Element %d not found.\n", beforeData);
        free(newNode);
        return;
    }

    prev->next = newNode;
    newNode->next = curr;
}

// Insert after specified element
void insertAfter(struct Node* head, int dataToInsert, int afterData) {
    if (head == NULL) {
        printf("List is empty. Cannot insert after %d\n", afterData);
        return;
    }

    struct Node* curr = head;
    while (curr != NULL && curr->data != afterData) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Element %d not found.\n", afterData);
        return;
    }

    struct Node* newNode = createNode(dataToInsert);
    newNode->next = curr->next;
    curr->next = newNode;
}

// Delete a specified element
void deleteElement(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;

    // If head needs to be deleted
    if (curr->data == data) {
        *head = curr->next;
        free(curr);
        printf("Deleted element %d\n", data);
        return;
    }

    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Element %d not found.\n", data);
        return;
    }

    prev->next = curr->next;
    free(curr);
    printf("Deleted element %d\n", data);
}

// Display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
    printf("List reversed.\n");
}

// Sort the linked list using Bubble Sort
void sortList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("List sorted in ascending order.\n");
}

// Delete every alternate node starting from second node
void deleteAlternateNodes(struct Node* head) {
    if (head == NULL) return;

    struct Node* prev = head;
    struct Node* curr = head->next;

    while (prev != NULL && curr != NULL) {
        prev->next = curr->next;
        free(curr);
        prev = prev->next;
        if (prev != NULL)
            curr = prev->next;
    }
    printf("Deleted every alternate node starting from second node.\n");
}

// Insert element into sorted list maintaining order
void insertIntoSorted(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    while (curr->next != NULL && curr->next->data < data)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;
    printf("Inserted %d into sorted list.\n", data);
}

int main() {
    struct Node* head = NULL;
    int n, data, choice, refData;

    // Create initial linked list
    printf("Enter the number of nodes to create initially: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &data);
            insertAtEnd(&head, data);
        }
    }

    displayList(head);

    // Menu-driven operations
    while (1) {
        printf("\n----- Menu -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert element before specified element\n");
        printf("4. Insert element after specified element\n");
        printf("5. Delete specified element\n");
        printf("6. Traverse and display list\n");
        printf("7. Reverse the list\n");
        printf("8. Sort the list\n");
        printf("9. Delete every alternate node\n");
        printf("10. Insert element into sorted list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                displayList(head);
                break;

            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                displayList(head);
                break;

            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter element before which to insert: ");
                scanf("%d", &refData);
                insertBefore(&head, data, refData);
                displayList(head);
                break;

            case 4:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter element after which to insert: ");
                scanf("%d", &refData);
                insertAfter(head, data, refData);
                displayList(head);
                break;

            case 5:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteElement(&head, data);
                displayList(head);
                break;

            case 6:
                displayList(head);
                break;

            case 7:
                reverseList(&head);
                displayList(head);
                break;

            case 8:
                sortList(head);
                displayList(head);
                break;

            case 9:
                deleteAlternateNodes(head);
                displayList(head);
                break;

            case 10:
                printf("Enter element to insert into sorted list: ");
                scanf("%d", &data);
                insertIntoSorted(&head, data);
                displayList(head);
                break;

            case 11:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
