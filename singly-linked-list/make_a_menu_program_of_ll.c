#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node
{
    int data;
    struct node* next;
};

// Function prototypes
void traversal(struct node* ptr);
struct node* insert_at_beginning(struct node* head, int data);
struct node* insert_between_array(struct node* head, int data, int index);
struct node* insert_at_end(struct node* head, int data);
struct node* delete_at_beginning(struct node* head);
struct node* delete_between_array(struct node* head, int index);
struct node* delete_end_element(struct node* head);
struct node* delete_value(struct node* head, int value);
void display_menu();
int display_list(struct node** head_ref);

int main()
{
    struct node* first = NULL; // Initialize the linked list as empty
    int choice;
    int data, index, value;

    do
    {
        display_menu();
        printf("\033[1;35m"); // 1;35 represents bold magenta text
        printf("Enter your choice ");
        printf("\033[0m");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\033[1;32mEnter the data to insert at the beginning: \033[0m");
            scanf("%d", &data);
            first = insert_at_beginning(first, data);
            break;

        case 2:
            printf("\033[1;32mEnter the data to insert: \033[0m");
            scanf("%d", &data);
            printf("\033[1;32mEnter the index to insert at: \033[0m");
            scanf("%d", &index);
            first = insert_between_array(first, data, index);
            break;

        case 3:
            printf("\033[1;32mEnter the data to insert at the end: \033[0m");
            scanf("%d", &data);
            first = insert_at_end(first, data);
            break;

        case 4:
            first = delete_at_beginning(first);
            break;

        case 5:
            printf("\033[1;32mEnter the index to delete: \033[0m");
            scanf("%d", &index);
            if (index < 0)
            {
                printf("\033[1;31mInvalid index. Index must be non-negative.\033[0m\n");
            }
            else
            {
                first = delete_between_array(first, index);
            }
            break;

        case 6:
            first = delete_end_element(first);
            break;

        case 7:
            printf("\033[1;32mEnter the value to delete: \033[0m");
            scanf("%d", &value);
            first = delete_value(first, value);
            break;

        case 8:
            display_list(&first);
            break;

        case 0:
            printf("\033[1;31mExiting the program.\033[0m\n");
            break;

        default:
            printf("\033[1;31mInvalid choice. Please enter a valid option.\033[0m\n");
        }

    } while (choice != 0);

    return 0;
}

void display_menu()
{
    // ANSI escape code for blue text
    printf("\033[1;34m"); 

    printf("\nLinked List Operations Menu:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert between array\n");
    printf("3. Insert at the end\n");
    printf("4. Delete at the beginning\n");
    printf("5. Delete between array\n");
    printf("6. Delete end element\n");
    printf("7. Delete value\n");
    printf("8. Display list\n");
    printf("0. Exit\n");

    // Reset color to default
    printf("\033[0m");
}
// Function definitions (user-defined functions)
void traversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("\033[1;31mYour number is: %d\033[0m\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* insert_at_beginning(struct node* head, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->next = head;
    temp->data = data;
    head = temp;
    return temp;
}

struct node* insert_between_array(struct node* head, int data, int index) {
    if (index < 0) {
        printf("\033[1;31mInvalid index. Index must be non-negative.\033[0m\n");
        return head;
    }

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\033[1;31mMemory allocation failed. Unable to insert node.\033[0m\n");
        return head;
    }

    temp->data = data;
    temp->next = NULL;

    if (index == 0) {
        // Insert at the beginning
        temp->next = head;
        return temp;
    }

    struct node* p = head;
    int i = 0;

    while (i < index - 1 && p != NULL) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        // Index out of bounds
        printf("\033[1;31mIndex out of bounds. Unable to insert node.\033[0m\n");
        free(temp);
        return head;
    }

    // Insert between nodes
    temp->next = p->next;
    p->next = temp;

    return head;
}

struct node* insert_at_end(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\033[1;31mMemory allocation failed, Unable to insert node.\033[0m\n");
        return head;
    }

    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        // If the list is empty, set the new node as the head
        head = ptr;
        return head;
    }

    struct node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = ptr;
    return head;
}

struct node* delete_at_beginning(struct node* head) {
    struct node* temp = head;
    head = head->next;
    temp->next = NULL;

    free(temp);
    return head;
}

struct node* delete_between_array(struct node* head, int index) {
    if (index < 0) {
        printf("\033[1;31mInvalid index. Index must be non-negative.\033[0m\n");
        return head;
    }

    // If the list is empty and the index is 0, return without any modification
    if (head == NULL && index == 0) {
        printf("\033[1;31mList is empty. Nothing to delete.\033[0m\n");
        return head;
    }

    if (head == NULL) {
        printf("\033[1;31mList is empty. Cannot delete at index %d.\033[0m\n", index);
        return head;
    }

    struct node* p = head;
    struct node* q = head->next;
    int i = 0;

    while (i != index - 1) {
        if (q == NULL) {
            // Index is out of bounds
            printf("\033[1;31mIndex out of bound, unable to delete a node\033[0m\n");
            return head;
        }

        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);
    return head;
}

struct node* delete_end_element(struct node* head) {
    if (head == NULL) {
        printf("\033[1;31mList is empty, cannot delete an element\033[0m\n");
        return NULL;
    }

    struct node* p = head;
    struct node* q = head->next;

    // Check if there is only one element in the list
    if (q == NULL) {
        free(p);
        return NULL;
    }

    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

struct node* delete_value(struct node* head, int value) {
    if (head == NULL) {
        printf("\033[1;31mList is empty, cannot delete\033[0m\n");
        return head;
    }

    struct node* p = head;
    struct node* q = head->next;

    // Check if the first node contains the value
    if (p->data == value) {
        head = delete_at_beginning(head);
        return head;
    }

    while (q != NULL && q->data != value) {
        p = p->next;
        q = q->next;
    }

    if (q == NULL) {
        printf("\033[1;31mValue not found in the list, cannot delete\033[0m\n");
        return head;
    }

    p->next = q->next;
    free(q);
    return head;
}

int display_list(struct node** head_ref) {
    if (head_ref == NULL)
        return 1;

    struct node* temp = *head_ref;
    while (temp != NULL) {
        printf("\033[1;31m%d\033[0m \033[1;31m->\033[1;31m \033[0m", temp->data);
        temp = temp->next;
    }
    printf("\033[1;31mNULL\033[0m\n");
    return 0;
}