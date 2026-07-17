# Screen-Sharing Action Guide

Follow this guide in order during the presentation. The matching words to say
are in [presentation-script.md](presentation-script.md).

## 1. Prepare before joining

1. Restart the computer if it has been running for a long time.
2. Connect the charger.
3. Use a stable internet connection.
4. Disable notifications or turn on Windows Do Not Disturb.
5. Close private messages, email, banking pages, and unrelated browser tabs.
6. Set the display scale to a comfortable size.
7. Place the meeting controls where they will not cover the slides.
8. Keep a copy of the project on the computer even if the internet fails.

## 2. Open everything before sharing

Open these items in this order:

1. `BEE208-Laboratory-Access-Control-System-Presentation.pptx`
2. PowerShell
3. `access_log.txt`
4. `main.cpp`
5. The GitHub repository:
   `https://github.com/josephasamoah/BEE208-Laboratory-Access-Control-System`

Keep the PowerPoint window in front.

## 3. Prepare PowerShell

Run:

```powershell
cd "C:\Users\User\BEE208-Laboratory-Access-Control-System"
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o laboratory_access.exe
```

If the command finishes without an error, leave PowerShell open.

Clear old terminal text:

```powershell
Clear-Host
```

Do not start the application yet.

## 4. Share the correct screen

1. Click **Share screen** in the meeting application.
2. Select the PowerPoint window if the meeting application supports individual
   window sharing.
3. If switching between PowerPoint, PowerShell, the log, and GitHub is difficult,
   share the full screen instead.
4. Confirm that the audience can see the title slide.
5. Start the PowerPoint slideshow from slide 1.

## 5. Slide-by-slide actions

| Slide | What to show or do |
|---|---|
| 1 | Keep the title slide visible while introducing Group 1.11 and the project. |
| 2 | Point to **Who**, **When**, and **Why** while explaining the accountability problem. |
| 3 | Point from **Verify** to **Decide** to **Record**. |
| 4 | Follow steps 01–05 from left to right. Emphasise the three-attempt decision. |
| 5 | Explain the successful report, then leave the slideshow for the live demonstration. |
| 6 | Return to the slideshow and point to the five `AccessUser` member functions. |
| 7 | Move across the eight C++ concepts without reading every word. |
| 8 | Point to the repository tree, then briefly open GitHub if internet access is reliable. |
| 9 | Point to the denied and invalid-input tests as evidence beyond the happy path. |
| 10 | Explain three challenges, then point to the future improvements. |
| 11 | Deliver the conclusion and invite questions. |

## 6. Successful live demonstration

From slide 5, press `Alt+Tab` to switch to PowerShell.

Run:

```powershell
.\laboratory_access.exe
```

Enter each response and press Enter:

```text
Ama Mensah
BEE208/045/2026
1
BEE208LAB
2
```

Point out:

- `Attempts Used: 1 of 3`
- `Access Status: Access Granted`
- The access timestamp
- `Record saved to access_log.txt`

## 7. Denied live demonstration

Run the application again:

```powershell
.\laboratory_access.exe
```

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

Point out:

- The remaining-attempt messages
- `Attempts Used: 3 of 3`
- `Access Status: Access Denied`
- The message confirming that no successful-access record was saved

## 8. Show the log

Open the log from PowerShell:

```powershell
notepad .\access_log.txt
```

Show the successful record and explain the columns:

- Timestamp
- Full name
- ID number
- Role
- Status
- Access condition

Do not spend time reading every record.

Close Notepad and return to PowerPoint with `Alt+Tab`.

## 9. Optional code walkthrough

Only do this if the lecturer requests a code explanation.

Open the source:

```powershell
notepad .\main.cpp
```

Use Find (`Ctrl+F`) to locate:

1. `class AccessUser`
2. `setUserDetails`
3. `verifyAccessCode`
4. `displayAccessStatus`
5. `saveAccessLog`
6. `int main`

Explain the purpose of each section rather than reading the entire code.

## 10. GitHub walkthrough

If the internet is stable:

1. Open the repository.
2. Show `README.md`.
3. Show `main.cpp`.
4. Show `algorithm.md` and `pseudocode.md`.
5. Show `flowchart.png`.
6. Show `report.md`, `test-data.md`, and the screenshots folder.
7. Show the PowerPoint and presentation guides.

If the internet is unstable, stay in the local project folder and explain that
the same files are already available locally.

## 11. Emergency backup plan

If the C++ compiler fails:

1. Do not troubleshoot for several minutes.
2. Return to slide 5.
3. Use `sample-output.png` and the screenshots as demonstration evidence.

If PowerPoint fails:

1. Open the rendered project screenshots and `flowchart.png`.
2. Continue using the order in `presentation-script.md`.

If the internet fails:

1. Skip the live GitHub page.
2. Show the local repository folder.

If screen sharing stops:

1. Pause speaking.
2. Share the screen again.
3. Ask the audience to confirm visibility before continuing.

## 12. Final checklist

- [ ] Laptop charged
- [ ] Notifications disabled
- [ ] Presentation opens correctly
- [ ] PowerShell is in the project folder
- [ ] Program compiles
- [ ] Successful demo inputs available
- [ ] Denied demo inputs available
- [ ] `access_log.txt` opens
- [ ] GitHub repository opens
- [ ] Microphone works
- [ ] Screen sharing tested
- [ ] Every presenting member knows their assigned section
