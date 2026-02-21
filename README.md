🚀 Office Hour Appointment System
CSE2002 Project | 2023-2024

A robust, file-based management system written in C to streamline the scheduling process between students and faculty. This project utilizes Linked Lists and Binary File I/O to manage office hours and appointments efficiently.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
📌 Features
The system provides tailored functionalities for two types of users:

👨‍🏫 For Teachers
Insert Office Hours: Add new availability slots. The system automatically sorts them by ID using a linked list.

Update Records: Modify the day, start time, or end time of existing slots.

Persistent Storage: Save the entire schedule to a teacher-specific binary file (.dat) for data integrity.

Inventory View: Print a clean, tabular summary of all currently registered office hours.

🎓 For Students
View Availability: Load a specific teacher's schedule from their records.

Book Appointments: Search for a slot by ID and create a formal appointment.

Appointment Logging: The system generates an appointment.txt file as a persistent record of the booking.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
🛠 Technical Implementation
This project demonstrates several core Computer Engineering concepts:

Data Structures: Custom struct definitions and dynamic Linked Lists for memory-efficient data management.

File Handling: Implementation of both Binary (wb, rb) for data storage and Text file processing for logs.

Sorting Algorithms: Insertion logic that maintains a sorted list based on id_number.

Input Validation: Safe string handling via custom read_line functions to prevent buffer overflows.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
<img width="686" height="295" alt="Capture" src="https://github.com/user-attachments/assets/1a313209-2511-4df4-b1bb-f4b6f3678117" />

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
👤 Developer
Ferdaws Computer Engineering Student at Istanbul Kultur University (IKU)
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Pictures

<img width="957" height="1010" alt="Teacher jpeg" src="https://github.com/user-attachments/assets/dada11e2-e902-4c42-855d-bf145d7b4666" />
<img width="952" height="820" alt="Student jpeg" src="https://github.com/user-attachments/assets/1cd6dcb0-2b74-439a-9924-663483d7c635" />


