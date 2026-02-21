void insert_office_hour(void);
This function prompts the user for information about a new office hour and inserts it into a linked list of office hours. The list is maintained in sorted order by the id_number of the office hours. It checks if the office hour already exists and prints an error message if it does. If the office hour is new, it allocates memory for the new office hour, fills in the details, and inserts it into the correct position in the list.
void store_office_hour(char teacher[]);
This function saves the current list of office hours to a file named after the teacher. The file is opened in binary write mode ("wb"), and each office hour is written to the file. The function iterates through the linked list of office hours and writes each one to the file, excluding the next pointer to maintain data integrity.
void update_office_hour(void);
This function allows the user to update an existing office hour. The user is prompted to enter the id_number of the office hour they wish to update. If the office hour is found in the list, the user can choose to update the day, start time, or end time of the office hour. The function then updates the relevant field with the new information.
struct office* find_office(int number);
This function searches for an office hour by its id_number. It traverses the linked list of office hours and returns a pointer to the office hour with the matching id_number. If no such office hour is found, it returns NULL.
void print_office_hour(void);
This function prints a list of all office hours in the current inventory. It iterates through the linked list of office hours and prints each office hour's id_number, day, start time, and end time in a tabular format.
void appointments(char teacher[]);
This function loads office hours for a specified teacher from a file and stores them in the linked list of office hours. It opens the file named after the teacher in binary read mode ("rb"), reads each office hour from the file, and inserts it into the linked list. The function first clears the existing list of office hours to ensure there are no duplicates.
void create_appointment(char student_name[], char teacher_name[]);
This function creates an appointment for a student with a specified teacher. The user is prompted to enter the id_number of the desired office hour. The function then searches for the office hour by id_number. If found, it updates the office hour with the student's and teacher's names and appends the appointment details to a file. The function handles any errors that occur while writing to or closing the file.


int read_line(char str[], int n);
This function reads a line of input from the user and stores it in the given character array str. It reads up to n-1 characters, ensuring that the input is null-terminated. The function discards any extra characters that exceed the limit. This is useful for safely reading strings from user input.
void print_info(void);
This function prints information about the project file, including the file name, date, time, and line number. It provides a welcome message to the user. This information can be helpful for debugging or providing context to the user.
int main(void);
This is the main function of the program. It handles user interaction, prompting the user to identify themselves as a teacher or student. Based on the user's choice, it directs the program flow to handle various tasks such as creating appointments, inserting, updating, and printing office hours. The main function serves as the entry point and orchestrates the overall functionality of the program.
void print_file_info(void);
Prints the Header for appointment.txt file. 
