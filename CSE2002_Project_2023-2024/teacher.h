//Ferdaws Qaem - 2300001530
#ifndef TEACHER_H// Include guard to prevent multiple inclusions
#define TEACHER_H

#define NAME_LEN 100
// Structure to store office hour information
struct office {

    char teacher[NAME_LEN + 1];
    char student[NAME_LEN + 1];

    int id_number;
    char day[NAME_LEN + 1];
    char start[NAME_LEN + 1];
    char end[NAME_LEN + 1];
    struct office* next; // The office structure will contain an additional member (a pointer to the next node)
};

// Function prototypes for office hour management
void insert_office_hour(void);//to insert a new office hour
void store_office_hour(char teacher[]); //to store office hours in a file
void update_office_hour(void);//to update an existing office hour
struct office* find_office(int number);//to find an office hour by ID number
void print_office_hour(void);//to print all office hours
void appointments(char teacher[]);//to handle appointments

#endif // !TEACHER_H
