# Pseudocode: Laboratory Access Control System

```text
CONSTANT APPROVED_CODE <- "BEE208LAB"
CONSTANT MAX_ATTEMPTS <- 3
ROLES <- ["Student", "Lecturer", "Technician", "Visitor"]

START
    DISPLAY system title
    processAnotherUser <- TRUE

    WHILE processAnotherUser = TRUE
        REPEAT
            INPUT fullName
        UNTIL fullName is not empty

        REPEAT
            INPUT userID
        UNTIL userID is not empty

        DISPLAY numbered ROLES
        REPEAT
            INPUT roleChoice
        UNTIL roleChoice is a number from 1 to 4

        userRole <- ROLES[roleChoice - 1]
        supervisionRequired <- (userRole = "Visitor")
        attemptsUsed <- 0
        accessGranted <- FALSE

        WHILE attemptsUsed < MAX_ATTEMPTS AND accessGranted = FALSE
            REPEAT
                INPUT accessCode
            UNTIL accessCode is not empty

            attemptsUsed <- attemptsUsed + 1

            IF accessCode = APPROVED_CODE THEN
                accessGranted <- TRUE
                accessTime <- current date and time
            ELSE IF attemptsUsed < MAX_ATTEMPTS THEN
                DISPLAY "Incorrect access code" and remaining attempts
            END IF
        END WHILE

        DISPLAY fullName, userID, userRole, attemptsUsed

        IF accessGranted = TRUE THEN
            DISPLAY "Access Granted"
            IF supervisionRequired = TRUE THEN
                DISPLAY "Visitor supervision is required"
            END IF
            OPEN access_log.txt in append mode
            IF file is empty THEN
                WRITE column headings
            END IF
            WRITE successful access record
            CLOSE access_log.txt
        ELSE
            DISPLAY "Access Denied"
            DISPLAY "No access record saved"
        END IF

        REPEAT
            INPUT nextAction
        UNTIL nextAction is 1 or 2
        processAnotherUser <- (nextAction = 1)
    END WHILE

    DISPLAY closing message
STOP
```
