# Algorithm: Laboratory Access Control System

1. Start the program.
2. Display the system title.
3. Ask the user to enter a non-empty full name.
4. Ask the user to enter a non-empty ID number.
5. Display the four supported roles: Student, Lecturer, Technician, and Visitor.
6. Ask for a role number and repeat the prompt until the choice is valid.
7. Set the selected role and mark Visitors as requiring supervision.
8. Set the number of access-code attempts used to zero.
9. Ask the user to enter the access code and increase the attempt count.
10. If the code is `BEE208LAB`, grant access and record the current date and time.
11. Otherwise, if fewer than three attempts have been used, show the remaining attempts and return to step 9.
12. If all three attempts are incorrect, deny access.
13. Display an access report containing the name, ID, role, attempts used, and final status.
14. If the user is an authorised Visitor, display that supervision is required.
15. If access was granted, append the successful record to `access_log.txt`; otherwise, do not write a record.
16. Ask whether another user should be processed.
17. If yes, return to step 3. If no, display the closing message.
18. Stop the program.
