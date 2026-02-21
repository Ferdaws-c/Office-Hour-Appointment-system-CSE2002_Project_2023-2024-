//Ferdaws Qaem - 2300001530
#define _CRT_SECURE_NO_WARNINGS
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "teacher.h"// Custom header for teacher-related functions
#include "readline.h"// Custom header for reading lines of input




void insert_office_hour(void);//for inserting office hours
void store_office_hour(char teacher[]);//for storing office hours
void appointments(char teacher[]);//for handling appointments
void update_office_hour(void);//for updating office hours
struct office* find_office(int number);//for finding an office by number
void print_office_hour(void);//for printing office hours

struct office* inventory = NULL;   /* points to first part */ //inventory will point to the first node in the list

/**********************************************************
 * insert_office_hour: Prompts the user for information    *
 *         about a new office hour and inserts it into     *
 *         the inventory list in sorted order. Prints an   *
 *         error message if the office hour already exists *
 *         or if memory allocation fails.                  *
 **********************************************************/
void insert_office_hour(void) {
    struct office* cur, * prev, * new_node;

    new_node = malloc(sizeof(struct office));// Allocate memory for new node
    if (new_node == NULL) {// Check if memory allocation failed
        printf("Database is full; can't add more!.\n");
        return;
    }

    printf("Enter identification number: ");
    scanf("%d", &new_node->id_number);

    //The new version must determine where the new office belongs in the list and insert it there.
    //It will also check whether the office number is already present in the list.
    for (cur = inventory, prev = NULL; cur != NULL && new_node->id_number > cur->id_number; prev = cur, cur = cur->next);

    // Once the loop terminates, insert will check whether cur isn’t NULL and whether new_node->id_number equals cur->id_number.
    if (cur != NULL && new_node->id_number == cur->id_number) { // If both are true, the office number is already in the list
        printf("Office hour already exists.\n");
        free(new_node);// Free allocated memory
        return;
    }
    //Otherwise, insert will insert a new node between the nodes pointed to by prev and cur.
    printf("\tEnter a day: ");
    read_line(new_node->day, NAME_LEN);
    printf("\tEnter starting hour: ");
    read_line(new_node->start, NAME_LEN);
    printf("\tEnter ending hour: ");
    read_line(new_node->end, NAME_LEN);

    // Insert the new node into the list
    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}
/************************************************************
 * store_office_hour: Saves the current office hours to a   *
 *         specified file named after the teacher.          *
 ************************************************************/
void store_office_hour(char teacher[]) {
    FILE* fp;
    char filename[FILENAME_MAX + 1];
    struct office* p;

    sprintf(filename, "%s.txt", teacher);// Create filename

    if ((fp = fopen(filename, "wb")) == NULL) {// Open file for writing
        printf("Can't open %s\n", filename);
        return;
    }
    // Write office hours to file
    for (p = inventory; p != NULL; p = p->next)
        fwrite(p, offsetof(struct office, next), 1, fp);

    fclose(fp);
}

/**********************************************************
 * update_office_hour: Prompts the user to enter an office *
 *         ID number. If the office exists, prompts the    *
 *         user to update the day, start, or end time.     *
 *         Otherwise, prints an error message.             *
 **********************************************************/
void update_office_hour(void) {

    int id_number, choice;
    struct office* p;

    printf("Enter identification number: ");// Prompt for office ID number
    scanf("%d", &id_number);
    p = find_office(id_number);// Find the office by ID
    if (p != NULL) {
        printf("Enter 1 to update day, 2 to update start, 3 to update end: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1: {
            printf("Enter new day: ");
            read_line(p->day, NAME_LEN);
            break;
        }
        case 2: {
            printf("Enter new Start: ");
            read_line(p->start, NAME_LEN);
            break;
        }
        case 3: {
            printf("Enter new End: ");
            read_line(p->end, NAME_LEN);
            break;
        }
        default: {
            printf("invalid number please try again! ");
            break;
        }
        }


    }
    else
        printf("identification not found.\n");

}
/**********************************************************
 * print_office_hour: Prints a listing of all office hours *
 *         in the inventory, showing the ID number, day,   *
 *         start time, and end time.                       *
 **********************************************************/
void print_office_hour(void) {
    struct office* p;

    printf("\tID number\tDay\t\tStart\t\tEnd\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("\t%d\t\t%-9s\t%-7s\t\t%-7s\n", p->id_number, p->day, p->start, p->end);
}
/**********************************************************
 * find_office: Looks up an office ID number in the        *
 *         inventory list. Returns a pointer to the node   *
 *         containing the ID number; if the ID number is   *
 *         not found, returns NULL.                        *
 **********************************************************/

struct office* find_office(int number)
{
    struct office* p;
    //find_office search loop
    for (p = inventory; p != NULL && number > p->id_number; p = p->next);

    //When the loop terminates, we will need to test whether the office was found
    if (p != NULL && number == p->id_number)
        return p;
    return NULL;
}
/**********************************************************
 * appointments: Loads office hours for the specified      *
 *         teacher from a file and stores them in the      *
 *         inventory list.                                 *
 **********************************************************/
void appointments(char teacher[]) {

    FILE* fp;
    char filename[FILENAME_MAX + 1];
    struct office* head, * new_node, * tail = NULL;

    sprintf(filename, "%s.txt", teacher);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open appointment file for %s.\n", teacher);
        return;
    }
    // Free the existing inventory list
    while (inventory != NULL) {
        head = inventory;
        inventory = inventory->next;
        free(head);
    }
    // Load office hours from file
    for (;;) {
        new_node = malloc(sizeof(struct office));
        if (new_node == NULL) {
            printf("Database is full; can't add more parts.\n");
            break;
        }
        if (fread(new_node, offsetof(struct office, next), 1, fp) == 1) {
            new_node->next = NULL;
            if (tail == NULL) {
                inventory = new_node;
                tail = new_node;
            }
            else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        else {
            free(new_node);
            break;
        }
    }

    fclose(fp);

}
