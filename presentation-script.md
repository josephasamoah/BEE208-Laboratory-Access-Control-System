# Group 1.11 Presentation Script

Use this script with `BEE208-Laboratory-Access-Control-System-Presentation.pptx`.
Speak naturally rather than reading too quickly. The full presentation, including
the demonstration, should take approximately 8–10 minutes.

## Opening

> Good day. We are Group 1.11, and our project is the Laboratory Access Control
> System. It is a C++ terminal application that verifies laboratory users,
> limits access-code attempts, displays the access decision, and keeps a
> persistent record of successful access.

## Slide 1 — Laboratory Access Control System

> Our project addresses access control and accountability in an engineering
> laboratory. The system provides a simple software-based way to determine who
> requested entry, whether the person was authorised, and when access was
> granted.

Transition:

> To understand why the system is necessary, we first considered the weaknesses
> of manual laboratory records.

## Slide 2 — Manual records leave accountability gaps

> When access is controlled manually, important information may be incomplete or
> difficult to retrieve. A lecturer or laboratory assistant may not be able to
> confirm who entered, when access was granted, or why the person was allowed
> inside.
>
> Our system addresses these questions by collecting the user's identity,
> checking permission, and creating a clear access report.

Transition:

> We converted those requirements into one controlled software workflow.

## Slide 3 — One workflow verifies, limits, and records access

> The program performs three main operations.
>
> First, it verifies the user's full name, ID, role, and access code.
>
> Second, it decides whether access should be granted. A user receives a maximum
> of three code attempts.
>
> Third, it displays the result and records successful access in
> `access_log.txt`.
>
> Visitors who enter the correct code are marked as requiring supervision.

Transition:

> The complete decision process can be explained in five steps.

## Slide 4 — Every request follows the same controlled path

> The program begins by collecting a valid name and ID. The user then selects
> one of four roles: Student, Lecturer, Technician, or Visitor.
>
> The access code is checked inside a loop. A correct code grants access, while
> three incorrect attempts cause access to be denied.
>
> The program displays an access report. Successful access is saved to the log,
> while denied access is not added to the successful-access record.

Transition:

> The next slide shows the output from a real successful run.

## Slide 5 — A successful request produces a timestamped report

> In this example, Ama Mensah enters a valid student ID and the approved code,
> `BEE208LAB`.
>
> The report shows the user's name, ID, role, number of attempts, access status,
> and the exact access time. The system then confirms that the record was saved
> to `access_log.txt`.

Pause the slideshow here for the live demonstration.

### Successful demonstration

Say:

> I will now demonstrate the successful-access path.

Enter:

```text
Ama Mensah
BEE208/045/2026
1
BEE208LAB
2
```

After the result appears, say:

> The correct code granted access on the first attempt. The program displayed a
> complete report and saved the record.

### Denied demonstration

Say:

> I will also demonstrate the three-attempt security limit.

Enter:

```text
Test User
TEST/001
3
WRONG1
WRONG2
WRONG3
2
```

After the result appears, say:

> The system denied access after three incorrect attempts. It did not save this
> person in the successful-access log.

Open `access_log.txt`, point to the successful entry, and say:

> The log contains successful access information, including the timestamp,
> identity, role, status, and access condition.

Return to the slideshow.

## Slide 6 — The AccessUser class keeps each request self-contained

> The main class is called `AccessUser`. It stores the state of one access
> request using private data members.
>
> `setUserDetails` collects the identity and role. `validateRole` checks the
> selected role. `verifyAccessCode` controls the three attempts.
> `displayAccessStatus` prints the report, and `saveAccessLog` writes successful
> access to the file.
>
> This class structure keeps the program organised and demonstrates
> encapsulation.

Transition:

> The implementation also demonstrates every major C++ concept required by the
> project.

## Slide 7 — The implementation demonstrates the required C++ concepts

> Input and output are handled with `getline`, `cout`, and `cerr`.
>
> The program uses strings, integers, Booleans, conditions, and several loops.
> Functions divide the work into reusable operations.
>
> The `AccessUser` class represents each user request, a vector stores the four
> roles, and file handling appends successful records to `access_log.txt`.

Transition:

> All source code and supporting evidence are organised for submission on
> GitHub.

## Slide 8 — One repository contains the full submission evidence

> The GitHub repository contains the C++ source code, README, algorithm,
> pseudocode, flowchart, report, test data, screenshots, access log, group
> contribution document, and this presentation.
>
> GitHub gives the group one source of truth, preserves the project history, and
> supports collaboration among members.

Transition:

> We tested more than the successful demonstration shown earlier.

## Slide 9 — Testing confirms both the happy path and failure paths

> Our tests covered first-attempt success, third-attempt success, three
> incorrect codes, supervised Visitor access, invalid input, and multiple users
> in one session.
>
> All six tests passed. We also verified that a denied user does not appear in
> the successful-access log.

Transition:

> During implementation, several challenges helped us improve the system's
> reliability.

## Slide 10 — The challenges improved reliability and shaped future work

> One challenge was safely combining full-line text input with numeric menu
> choices. We solved this by reading complete lines and parsing choices
> separately.
>
> We also trimmed whitespace so that spaces alone could not be accepted as a
> name or ID.
>
> The project allowed Visitors to be restricted or supervised, so we selected
> supervised access after successful verification and made that condition
> visible in both the report and log.
>
> Future improvements include hidden code entry, secure password hashing,
> role-specific permissions, a database, denied-attempt logging, and physical
> ID-card or biometric integration.

## Slide 11 — Conclusion

> In conclusion, the Laboratory Access Control System converts access decisions
> into accountable records.
>
> It verifies identity, limits incorrect attempts, distinguishes supervised
> Visitor access, reports the final decision, and preserves successful access
> information.
>
> The project satisfies the required C++ concepts and provides a foundation
> that could be extended into a real laboratory security system.
>
> Thank you. We are ready for your questions and any requested demonstration.

## Quick Defence Answers

### Why did you use a class?

> The class keeps each user's data and access operations together. It also
> demonstrates encapsulation and makes the code easier to organise.

### Why did you use a vector?

> The vector stores the supported roles in one collection and allows the
> numeric role choice to be mapped safely to its role name.

### Why are denied users not saved?

> The project specifically requires successful access records in
> `access_log.txt`. Denied attempts could be added later through a separate
> security-audit log.

### How is invalid input handled?

> Empty text is rejected after whitespace is removed. Menu choices are read as
> complete lines, parsed, and checked against the permitted range.

### What happens to a Visitor?

> A Visitor must enter the correct code and is then marked as requiring
> supervision in both the report and access log.

### What is the approved code?

> The approved demonstration code is `BEE208LAB`.

### What prevents unlimited attempts?

> `verifyAccessCode` uses a loop controlled by `MAX_ATTEMPTS`, which is set to
> three.
