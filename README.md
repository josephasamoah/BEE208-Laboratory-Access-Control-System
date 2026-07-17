# BEE208 Laboratory Access Control System

A terminal-based C++ application that verifies laboratory access codes, limits users to three attempts, classifies users by role, displays a clear access report, and saves successful access records to a text file.

## Project Details

- **Course:** BEE 208
- **Project:** Mid-Semester Practical Project Examination — Question 11
- **Group number:** 1.11
- **Approved access code:** `BEE208LAB`
- **Language standard:** C++17

## Group Members

| Student Name | Index Number | GitHub |
|---|---|---|
| Afloe Derrick Tetteh | 01243621B | [@afloederrick1-blip](https://github.com/afloederrick1-blip) |
| Joseph Oppong | 01242622B | Profile required |
| Arnold | 01242282B | [@comparerarnoldsteeve-prog](https://github.com/comparerarnoldsteeve-prog) |
| Sogbo Prosper Kekeli | 01245631B | [@Prosperkeke56](https://github.com/Prosperkeke56) |
| Quawu Micheal | 01242801B | [@qwawumicheal79-oss](https://github.com/qwawumicheal79-oss) |
| Detema Donne | 012443626 | [@DetemaDonne](https://github.com/DetemaDonne) |

## Features

- Validates empty names and ID numbers.
- Validates numeric role and menu choices.
- Supports Student, Lecturer, Technician, and Visitor roles.
- Allows a maximum of three access-code attempts per user.
- Marks authorised Visitors as requiring supervision.
- Processes multiple users in one program session.
- Writes only successful access records to `access_log.txt`.
- Records the date, time, identity, role, status, and access condition.

## Repository Contents

```text
BEE208-Laboratory-Access-Control-System/
├── README.md
├── main.cpp
├── algorithm.md
├── pseudocode.md
├── flowchart.png
├── report.md
├── BEE208-Laboratory-Access-Control-System-Presentation.pptx
├── sample-output.png
├── test-data.md
├── access_log.txt
├── group-contribution.md
└── screenshots/
    ├── input-screen.png
    ├── output-screen.png
    └── file-output.png
```

## Compile and Run

### Windows with g++

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o laboratory_access.exe
.\laboratory_access.exe
```

### Linux or macOS with g++

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o laboratory_access
./laboratory_access
```

Run the program from the repository folder so that `access_log.txt` is created or updated in the expected location.

## Access Rules

| Role | Rule after code verification |
|---|---|
| Student | Access granted when the correct code is entered. |
| Lecturer | Access granted when the correct code is entered. |
| Technician | Access granted when the correct code is entered. |
| Visitor | Access granted when the correct code is entered, with supervision required. |

All roles are denied after three incorrect access-code attempts.

## Program Design

The `AccessUser` class stores each user’s identity, role, access state, attempt count, supervision condition, and access time. Its member functions collect validated user details, verify the access code, display a report, and append successful records to the log. A `vector` stores the supported roles, while loops control validation, code attempts, and multiple-user processing.

## Documentation

- [Algorithm](algorithm.md)
- [Pseudocode](pseudocode.md)
- [Flowchart](flowchart.png)
- [Test data](test-data.md)
- [Full report](report.md)
- [Presentation deck](BEE208-Laboratory-Access-Control-System-Presentation.pptx)
- [Presentation script](presentation-script.md)
- [Screen-sharing action guide](presentation-actions.md)
- [Group contribution template](group-contribution.md)

## Sample Output

![Successful access sample](sample-output.png)

## Before Final Submission

1. Replace all bracketed placeholders in `README.md`, `report.md`, and `group-contribution.md`.
2. Confirm that individual contributions match the work actually completed.
3. Add the final GitHub repository link and submission date to the report.
4. Demonstrate at least one granted, one denied, and one supervised Visitor scenario.
