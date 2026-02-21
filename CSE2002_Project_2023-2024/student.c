//Ferdaws Qaem - 2300001530
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"// Custom header for student-related functions
#include "teacher.h"// Custom header for teacher-related functions

#define SIZE 50

// Function to create an appointment
void create_appointment(char student_name[], char teacher_name[]) {

    int id_number;
    struct office* p;
    FILE* fp;


    printf("\n\tEnter desired identification number of office hour: ");
    scanf("%d", &id_number);// Read office hour ID
    printf("\n");
    p = find_office(id_number);// Find the office hour by ID

    if ((fp = fopen(FILE_NAME, "a")) == NULL) {
        printf("Can't open %s\n", FILE_NAME);// Print error message if file cannot be opened
        return;
    }

    if (p != NULL) {// Check if the office hour exists
        strcpy(p->student, student_name);// Copy student name to the office hour
        strcpy(p->teacher, teacher_name);// Copy teacher name to the office hour
        // Write appointment details to the file
        if (fprintf(fp, "%-16s%-16s%-16s%-16s%-16s\n", p->teacher, p->student, p->day, p->start, p->end) < 0) {
            // If fprintf fails, print an error message
            perror("Error writing to file");
            fclose(fp);
            return;
        }
    }
    else {
        printf("identification not found.\n");
    }

    if (fclose(fp) != 0) {// Close the file
        // If fclose fails, print an error message
        perror("Error closing file");
        return;
    }

}

