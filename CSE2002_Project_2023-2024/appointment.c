#define _CRT_SECURE_NO_WARNINGS// Disable secure warnings for standard C functions
#include <stdio.h>// Standard input/output functions
#include <stdlib.h>// Standard library functions
#include <string.h>// String manipulation functions

#include "student.h"// header for student-related functions
#include "readline.h"//header for reading lines of input
#include "teacher.h"// header for teacher-related functions

#define SIZE 100 // Define size for names

void print_info(void);// Function prototype for printing program info
/*void print_file_info(void);*/// Function prototype for printing file info 

int main(void) {
    print_info();// printing file info!
    //print_file_info();// Call function to print file info

    int user_type;// Variable to store user type (teacher or student)
    char code;// Variable to store operation code
    char student_name[SIZE + 1];// student name
    char teacher_name[SIZE + 1];// teacher name

    printf("Who are you? (Enter 1 for TEACHER, 2 for STUDENT): ");
    scanf("%d", &user_type);// Read user type

    if (user_type == 1) {// If user is a teacher
        printf("Enter your full name: ");
        read_line(teacher_name, sizeof(teacher_name));// Read teacher's name
        appointments(teacher_name);// opens appointments file for the teacher

        for (;;) {// Infinite loop
            printf("\nEnter operation code: ");
            scanf(" %c", &code);
            
            switch (code) {// Handle operation code
            case 'i': {
                insert_office_hour();// Insert new office hour
                break;
            }
            case 'u': {
                update_office_hour();// Update existing office hour
                break;
            }

            case 'p': {
                print_office_hour();// Print office hours
                break;
            }
            case 'q': {
                printf("saved successfully!\n");
                store_office_hour(teacher_name);// Save office hours
                return 0;// Exit program
            }
            default:  printf("Illegal code\n");// Invalid code message
            }
            printf("\n");
        }
    }
    else if (user_type == 2) {// If user is a student

        printf("Enter your full name: ");
        read_line(student_name, sizeof(student_name));// Read student's name

        for (;;) {// infinite loop
            printf("Enter Teacher's full name: ");
            read_line(teacher_name, sizeof(teacher_name));// Read teacher's name
            // Check if the input is 'q'
            if (strcmp(teacher_name, "q") == 0) break; // Exit the loop

            appointments(teacher_name);// Open the appointments file for the teacher
            print_office_hour();// Print office hours for the teacher
            create_appointment(student_name, teacher_name);// Create an appointment
        }
    }
    else {
        printf("Invalid user type.\n");
    }

    return 0;
}
void print_info(void) {
    printf("The project file information is given below.\n");
    printf("\tFile name: %s\n", __FILE__);
    printf("\tDate: %s\n", __DATE__);
    printf("\tTime: %s\n", __TIME__);
    printf("\tLine: %d\n\n", __LINE__);

    printf("*************************************************\n");
    printf("* WELCOME TO THE OFFICE HOUR APPOINTMENT SYSTEM *\n");
    printf("*************************************************\n");


}

/*void print_file_info(void) {
    FILE* fp;

    if ((fp = fopen(FILE_NAME, "a")) == NULL) {// Attempt to open file for appending
        printf("Can't open %s\n", FILE_NAME);// Error message if file cannot be opened
        return;
    }
    fprintf(fp,"Teacher\t\tStudent\t\tDay\t\tStart\t\tEnd\n");// Write header to file
    fclose(fp);// Close the file
}
*/