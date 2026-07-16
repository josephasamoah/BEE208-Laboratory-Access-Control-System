#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace {
const string APPROVED_ACCESS_CODE = "BEE208LAB";
const int MAX_ATTEMPTS = 3;

string trim(const string& value) {
    const auto first = find_if_not(value.begin(), value.end(),
                                   [](unsigned char ch) { return isspace(ch); });
    const auto last = find_if_not(value.rbegin(), value.rend(),
                                  [](unsigned char ch) { return isspace(ch); }).base();
    return first < last ? string(first, last) : "";
}

string currentTimestamp() {
    const time_t now = time(nullptr);
    tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &now);
#else
    localtime_r(&now, &localTime);
#endif
    ostringstream output;
    output << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return output.str();
}

string readRequiredLine(const string& prompt) {
    string value;
    while (true) {
        cout << prompt;
        if (!getline(cin, value)) {
            cout << "\nInput ended. Closing the system safely.\n";
            exit(0);
        }
        value = trim(value);
        if (!value.empty()) {
            return value;
        }
        cout << "Input cannot be empty. Please try again.\n";
    }
}

int readChoice(const string& prompt, int minimum, int maximum) {
    string input;
    while (true) {
        cout << prompt;
        if (!getline(cin, input)) {
            cout << "\nInput ended. Closing the system safely.\n";
            exit(0);
        }

        stringstream parser(trim(input));
        int choice = 0;
        char extra = '\0';
        if ((parser >> choice) && !(parser >> extra) &&
            choice >= minimum && choice <= maximum) {
            return choice;
        }
        cout << "Invalid choice. Enter a number from " << minimum << " to "
             << maximum << ".\n";
    }
}
}  // namespace

class AccessUser {
private:
    string fullName;
    string userID;
    string userRole;
    string accessCode;
    bool accessGranted = false;
    bool supervisionRequired = false;
    int attemptsUsed = 0;
    string accessTime;

public:
    void setUserDetails();
    bool validateRole(int roleChoice);
    bool verifyAccessCode();
    void displayAccessStatus() const;
    bool saveAccessLog() const;
};

void AccessUser::setUserDetails() {
    static const vector<string> roles = {
        "Student", "Lecturer", "Technician", "Visitor"
    };

    fullName = readRequiredLine("Enter full name: ");
    userID = readRequiredLine("Enter ID number: ");

    cout << "\nSelect role:\n"
         << "1. Student\n"
         << "2. Lecturer\n"
         << "3. Technician\n"
         << "4. Visitor\n";

    int roleChoice = readChoice("Enter choice: ", 1, 4);
    if (validateRole(roleChoice)) {
        userRole = roles.at(static_cast<size_t>(roleChoice - 1));
        supervisionRequired = (userRole == "Visitor");
    }
}

bool AccessUser::validateRole(int roleChoice) {
    return roleChoice >= 1 && roleChoice <= 4;
}

bool AccessUser::verifyAccessCode() {
    while (attemptsUsed < MAX_ATTEMPTS) {
        accessCode = readRequiredLine("\nEnter access code: ");
        ++attemptsUsed;

        if (accessCode == APPROVED_ACCESS_CODE) {
            accessGranted = true;
            accessTime = currentTimestamp();
            return true;
        }

        const int remaining = MAX_ATTEMPTS - attemptsUsed;
        if (remaining > 0) {
            cout << "Incorrect access code. " << remaining
                 << (remaining == 1 ? " attempt" : " attempts")
                 << " remaining.\n";
        }
    }

    accessGranted = false;
    return false;
}

void AccessUser::displayAccessStatus() const {
    cout << "\n========================================\n"
         << "              ACCESS REPORT\n"
         << "========================================\n"
         << "Name: " << fullName << '\n'
         << "ID Number: " << userID << '\n'
         << "Role: " << userRole << '\n'
         << "Attempts Used: " << attemptsUsed << " of " << MAX_ATTEMPTS << '\n'
         << "Access Status: " << (accessGranted ? "Access Granted" : "Access Denied")
         << '\n';

    if (accessGranted && supervisionRequired) {
        cout << "Condition: Visitor supervision is required.\n";
    }
    if (accessGranted) {
        cout << "Access Time: " << accessTime << '\n';
    }
    cout << "========================================\n";
}

bool AccessUser::saveAccessLog() const {
    if (!accessGranted) {
        return false;
    }

    bool needsHeader = true;
    ifstream existingFile("access_log.txt", ios::binary | ios::ate);
    if (existingFile && existingFile.tellg() > 0) {
        needsHeader = false;
    }

    ofstream logFile("access_log.txt", ios::app);
    if (!logFile) {
        cerr << "Warning: The access record could not be saved.\n";
        return false;
    }

    if (needsHeader) {
        logFile << "Timestamp | Full Name | ID Number | Role | Status | Condition\n";
        logFile << "--------------------------------------------------------------------------\n";
    }

    logFile << accessTime << " | " << fullName << " | " << userID << " | "
            << userRole << " | Access Granted | "
            << (supervisionRequired ? "Supervision Required" : "Standard Access")
            << '\n';
    return true;
}

int main() {
    cout << "========================================\n"
         << "  LABORATORY ACCESS CONTROL SYSTEM\n"
         << "========================================\n";

    bool processAnotherUser = true;
    while (processAnotherUser) {
        cout << '\n';
        AccessUser user;
        user.setUserDetails();
        user.verifyAccessCode();
        user.displayAccessStatus();

        if (user.saveAccessLog()) {
            cout << "Record saved to access_log.txt\n";
        } else {
            cout << "No access record saved because access was denied.\n";
        }

        const int nextAction = readChoice(
            "\nProcess another user? (1 = Yes, 2 = No): ", 1, 2);
        processAnotherUser = (nextAction == 1);
    }

    cout << "\nThank you for using the Laboratory Access Control System.\n";
    return 0;
}
