# Test Data and Expected Results

| Test | Input summary | Expected result |
|---|---|---|
| 1. Valid student | Ama Mensah, BEE208/045/2026, Student, `BEE208LAB` | Access granted on attempt 1; successful record saved. |
| 2. Third-attempt success | Kojo Owusu, STAFF/014, Lecturer, wrong codes twice then `BEE208LAB` | Access granted on attempt 3; successful record saved. |
| 3. Three failed attempts | Efua Boateng, BEE208/099/2026, Technician, three wrong codes | Access denied; no record saved. |
| 4. Visitor | Akosua Nyarko, VIS/008, Visitor, `BEE208LAB` | Access granted and marked “Supervision Required”; record saved. |
| 5. Empty name | Blank name followed by Kofi Asante | Error displayed for blank input; valid name accepted after re-entry. |
| 6. Empty ID | Blank ID followed by BEE208/010/2026 | Error displayed for blank input; valid ID accepted after re-entry. |
| 7. Invalid role | Role entries `x`, `0`, `5`, then `1` | Invalid entries rejected; Student accepted. |
| 8. Invalid repeat choice | Repeat entry `3`, then `2` | Invalid entry rejected; program exits after `2`. |
| 9. Multiple users | Complete one record and choose `1`, then complete another | Both users processed in the same run. |

## Acceptance Criteria

- The program compiles without warnings using a C++17 compiler.
- Every prompt recovers from invalid or empty input without crashing.
- No more than three access-code attempts are accepted for one user.
- Only successful records appear in `access_log.txt`.
- Visitor records clearly state that supervision is required.
