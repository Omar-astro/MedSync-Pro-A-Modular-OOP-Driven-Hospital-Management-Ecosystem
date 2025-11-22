#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "SaveToFileClass.h"
#include "Doctor.h"
#include "Patient.h"

using namespace std;

void SaveToFile::createLoginFile() {
    ifstream infile("loginData.text");
    if (!infile.good()) {
        ofstream loginData("loginData.text");
        loginData.close();
    }
}
void SaveToFile::add_user(string username, string password, string role) {
    createLoginFile();
    ofstream loginData("loginData.text", ios::app);
    loginData << username << endl << password << endl << role << endl;
    loginData.close();
}
string* SaveToFile::loadUser(int index) {
    ifstream loginData("loginData.text");
    string* profile = new string[3];
    string line;
    int currentLine = 0;
    int profileIndex = 0;

    if (!loginData.is_open()) {
        cerr << "Failed to open file." << endl;
        // Fill with empty or default values
        for (int i = 0; i < 3; i++) profile[i] = "";
        return profile;
    }

    int startLine = (index - 1) * 3;
    int endLine = startLine + 3;

    while (getline(loginData, line)) {
        if (currentLine >= startLine && currentLine < endLine) {
            if (profileIndex < 3) {
                profile[profileIndex++] = line;
            }
        }
        currentLine++;
    }

    loginData.close();

    
    for (int i = profileIndex; i < 3; i++) {
        profile[i] = "";
    }

    return profile;
}
string SaveToFile::return_name(int i) {
    string line;
    int currentLine = 0;
    int targetLine = (i - 1) * 3 + 0;

    ifstream loginData("loginData.text");
    if (!loginData.is_open()) {
        cerr << "Failed to open file. (return_name)" << endl;
        return "";
    }

    while (getline(loginData, line)) {
        if (currentLine == targetLine) {
            loginData.close();
            return line;  // This is the username
        }
        currentLine++;
    }

    loginData.close();
    cerr << "Profile user index out of range. (return_name)" << endl;
    return "";
}
string SaveToFile::return_password(int i) {
    string line;
    int currentLine = 0;
    int targetLine = (i -1) * 3 + 1;

    ifstream loginData("loginData.text");
    if (!loginData.is_open()) {
        cerr << "Failed to open file." << endl;
        return "";
    }

    while (getline(loginData, line)) {
        if (currentLine == targetLine) {
            loginData.close();
            return line;  // This is the username
        }
        currentLine++;
    }

    loginData.close();
    cerr << "Profile pass index out of range." << endl;
    return "";
}
string SaveToFile::return_role(int i) {
    string line;
    int currentLine = 0;
    int targetLine = (i - 1) * 3 + 2;

    ifstream loginData("loginData.text");
    if (!loginData.is_open()) {
        cerr << "Failed to open file. (return_role)" << endl;
        return "";
    }

    while (getline(loginData, line)) {
        if (currentLine == targetLine) {
            loginData.close();
            return line;  // This is the username
        }
        currentLine++;
    }

    loginData.close();
    cerr << "Profile pass index out of range. (return_role)" << endl;
    return "";
}
int SaveToFile::count_profiles() {
    ifstream loginData("loginData.text");
    if (!loginData.is_open()) {
        cerr << "Failed to open file." << endl;
        return 0;
    }

    int lineCount = 0;
    string line;

    while (getline(loginData, line)) {
        lineCount++;
    }

    loginData.close();

    int profileCount = lineCount / 3;
    return profileCount;
}

//Doctor
int SaveToFile::countDoctorProfiles() {
    ifstream file("DoctorsFile.text");
    if (!file.is_open()) {
        cerr << "Error: Could not open file (countDoctorProfiles) " << "DoctorFile.text" << endl;
        return 0;
    }

    int lineCount = 0;
    string line;

    // Count total number of lines
    while (getline(file, line)) {
        if (!line.empty()) {
            ++lineCount;
        }
    }

    file.close();

    // Each doctor takes 5 lines
    int doctorCount = lineCount / 5;
    return doctorCount;
}
string SaveToFile::return_doctor_name(int index) {
    ifstream file("DoctorsFile.text");
    if (!file.is_open()) {
        cout << "Could not open DoctorsFile.text!" << endl;
        return "";
    }
    string line;
    int targetLine = (index - 1) * 5 + 0;
    int currentLine = 0;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return line;
        }
        currentLine++;
    }

    file.close();
    cout << "didn't return doctor name" << endl;
    return "";  // if not found
}
string SaveToFile::return_doctor_speciality(int index) {
    ifstream file("DoctorsFile.text");
    string line;
    int targetLine = (index - 1) * 5 + 1;
    int currentLine = 0;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return line;
        }
        currentLine++;
    }

    file.close();
    cout << "didn't return doctor special" << endl;
    return "";  // if not found
}
int SaveToFile::return_doctor_id(int index) {
    ifstream file("DoctorsFile.text");
    string line;
    int targetLine = (index - 1) * 5 + 2;
    int currentLine = 0;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return std::stoi(line);
        }
        currentLine++;
    }

    file.close();
    cout << "didn't return doctor id" << endl;
    return -1;  // if not found
}
int SaveToFile::return_doctor_Maxtimes(int index) {
    ifstream file("DoctorsFile.text");
    if (!file.is_open()) {
        cout << "Could not open DoctorsFile.txt!" << endl;
    }
    string line;
    int targetLine = (index - 1) * 5 + 3;
    int currentLine = 0, maxTime;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            size_t commaPos = line.find(',');

            if (commaPos != std::string::npos) {
                std::string firstPart = line.substr(0, commaPos);
                std::string secondPart = line.substr(commaPos + 1);

                //minTime = std::stoi(firstPart);
                maxTime = std::stoi(secondPart);
                return maxTime;
            }

            break;
        }
        currentLine++;
    }

    file.close();
}
int SaveToFile::return_doctor_Mintime(int index) {
    ifstream file("DoctorsFile.text");
    if (!file.is_open()) {
        cout << "Could not open DoctorsFile.txt!" << endl;
    }
    string line;
    int targetLine = (index - 1) * 5 + 3;
    int currentLine = 0, minTime;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            size_t commaPos = line.find(',');

            if (commaPos != std::string::npos) {
                std::string firstPart = line.substr(0, commaPos);
                std::string secondPart = line.substr(commaPos + 1);

                minTime = std::stoi(firstPart);
                //maxTime = std::stoi(secondPart);

                return minTime;
            }

            break;
        }
        currentLine++;
    }

    file.close();
}
vector<int> SaveToFile::return_doctor_schedule(int index) {
    std::vector<int> schedule;
    std::ifstream file("DoctorsFile.text");
    std::string line;
    int targetLine = (index - 1) * 5 + 4;
    int currentLine = 0;

    if (!file.is_open()) {
        std::cerr << "Could not open DoctorsFile.text!" << std::endl;
        return schedule; // Return empty vector
    }

    while (std::getline(file, line)) {
        if (currentLine == targetLine) {
            size_t start = 0, end;
            while ((end = line.find(',', start)) != std::string::npos) {
                schedule.push_back(std::stoi(line.substr(start, end - start)));
                start = end + 1;
            }
            if (start < line.size()) {
                schedule.push_back(std::stoi(line.substr(start)));
            }
            break;
        }
        currentLine++;
    }

    if (schedule.empty()) {
        std::cerr << "Didn't return doctor schedule" << std::endl;
    }

    return schedule;
}
void SaveToFile::saveAllDoctors(const vector<Doctor>& doctors) {
    ofstream outFile("DoctorsFile.text"); // Open a file to save doctor data

    if (!outFile) {
        cerr << "Error: Could not open file for writing.\n";
        cerr << "Check if the file path is correct and writable.\n";
        return;
    }

    if (doctors.empty()) {
        cerr << "Warning: The doctors vector is empty. No data to save.\n";
        return;
    }

    cout << "Saving the following doctors:\n";
    for (const auto& doctor : doctors) {
        // Write doctor details to the file
        outFile << doctor.getname() << endl // Use getter for name
            << doctor.checkSpeciality() << endl // Use getter for specialty
            << doctor.getID() << endl   // Use getter for ID
            << doctor.MinavailableTime << "," // Replace with getter if needed
            << doctor.MaxavailableTime << endl; // Replace with getter if needed

        // Write the schedule as a comma-separated list
        for (size_t i = 0; i < doctor.Schedule.size(); ++i) {
            outFile << doctor.Schedule[i];
            if (i < doctor.Schedule.size() - 1) {
                outFile << ","; // Add a comma between schedule entries
            }
        }
        outFile << "\n";
    }

    if (outFile.fail()) {
        cerr << "Error: Failed to write to the file.\n";
    }
    else {
        cout << "Doctors saved successfully to DoctorsFile.text.\n";
    }

    outFile.close(); // Close the file
}

//Patient
int SaveToFile::countPatientProfiles() {
    ifstream file("PatientFile.text");
    if (!file.is_open()) {
        cerr << "Error: Could not open file (countDoctorProfiles) " << "DoctorFile.text" << endl;
        return 0;
    }

    int lineCount = 0;
    string line;

    // Count total number of lines
    while (getline(file, line)) {
        if (!line.empty()) {
            ++lineCount;
        }
    }

    file.close();

    // Each doctor takes 5 lines
    int doctorCount = lineCount / 6;
    return doctorCount;
}

string SaveToFile::return_Patient_name(int index) {
	ifstream file("PatientFile.text");
	if (!file.is_open()) {
		cout << "Could not open DoctorsFile.text!" << endl;
		return "";
	}
	string line;
	int targetLine = (index - 1) * 7 + 0;
	int currentLine = 0;
	while (getline(file, line)) {
		if (currentLine == targetLine) {
			file.close();
			return line;
		}
		currentLine++;
	}
	file.close();
	cout << "didn't return doctor name" << endl;
	return "";  // if not found
}
int SaveToFile::return_Patient_ID(int index) {
    ifstream file("PatientFile.text");
    string line;
    int targetLine = (index - 1) * 7 + 2;
    int currentLine = 0;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return std::stoi(line);
        }
        currentLine++;
    }

    file.close();
    cout << "didn't return doctor id" << endl;
    return -1;  // if not found
}
string SaveToFile::return_Patient_illness(int index) {
    ifstream file("PatientFile.text");
    if (!file.is_open()) {
        cout << "Could not open DoctorsFile.text!" << endl;
        return "";
    }
    string line;
    int targetLine = (index - 1) * 7 + 1;
    int currentLine = 0;
    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return line;
        }
        currentLine++;
    }
    file.close();
    cout << "didn't return doctor name" << endl;
    return "none";  // if not found
}
string SaveToFile::return_Patient_specialistsRequest(int index) {
    ifstream file("PatientFile.text");
    if (!file.is_open()) {
        cout << "Could not open DoctorsFile.text!" << endl;
        return "";
    }
    string line;
    int targetLine = (index - 1) * 7 + 4;
    int currentLine = 0;
    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return line;
        }
        currentLine++;
    }
    file.close();
    cout << "didn't return doctor name" << endl;
    return "none";  // if not found
}
int SaveToFile::return_Patient_Request(int index) {
    ifstream file("PatientFile.text");
    string line;
    int targetLine = (index - 1) * 7 + 3;
    int currentLine = 0;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return std::stoi(line);
        }
        currentLine++;
    }

    file.close();
    cout << "didn't return doctor id" << endl;
    return -1;  // if not found
}
int SaveToFile::return_Patient_TimeRequest(int index) {
    ifstream file("PatientFile.text");
    string line;
    int targetLine = (index - 1) * 7 + 5;
    int currentLine = 0;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return std::stoi(line);
        }
        currentLine++;
    }

    file.close();
    cout << "didn't return doctor id" << endl;
    return -1;  // if not found
}
int SaveToFile::return_Patient_TotalCost(int index) {
    ifstream file("PatientFile.text");
    string line;
    int targetLine = (index - 1) * 7 + 6;
    int currentLine = 0;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return std::stoi(line);
        }
        currentLine++;
    }

    file.close();
    cout << "didn't return doctor id" << endl;
    return -1;  // if not found
}
void SaveToFile::updatePatientTotalCostInFile(const string& patientName, int newTotalCost) {
    ifstream infile("PatientFile.text");
    vector<string> lines;
    string line;
    while (getline(infile, line)) {
        lines.push_back(line);
    }
    infile.close();

    // Each patient profile is 7 lines (assuming you added total cost as the 7th line)
    for (size_t i = 0; i + 6 < lines.size(); i += 7) {
        if (lines[i] == patientName) {
            lines[i + 6] = to_string(newTotalCost); // Update total cost line
            break;
        }
    }

    ofstream outfile("PatientFile.text");
    for (const auto& l : lines) {
        outfile << l << endl;
    }
}
void SaveToFile::updatePatientIllnessInFile(const string& patientName, string newIllness) {
    ifstream infile("PatientFile.text");
    vector<string> lines;
    string line;
    while (getline(infile, line)) {
        lines.push_back(line);
    }
    infile.close();

    // Each patient profile is 7 lines (assuming you added total cost as the 7th line)
    for (size_t i = 0; i + 6 < lines.size(); i += 7) {
        if (lines[i] == patientName) {
            lines[i + 1] = newIllness; // Update total cost line
            break;
        }
    }

    ofstream outfile("PatientFile.text");
    for (const auto& l : lines) {
        outfile << l << endl;
    }
}
void SaveToFile::saveAllPatients(const vector<Patient>& patients) {
    ofstream outFile("PatientFile.text"); // Open a file to save patient data

    if (!outFile) {
        cerr << "Error: Could not open file for writing.\n";
        cerr << "Check if the file path is correct and writable.\n";
        return;
    }

    if (patients.empty()) {
        cerr << "Warning: The patients vector is empty. No data to save.\n";
        return;
    }

    cout << "Saving the following patients:\n";
    for (const auto& patient : patients) {
        // Write patient details to the file, one per line
        outFile << patient.checkName() << endl // Name
            << patient.getIllness() << endl // Illness
            << patient.getID() << endl      // ID
            << patient.getRequest() << endl      // Request (int)
            << patient.specialistRequest << endl // Specialist Request (string)
            << patient.timeRequest << endl
            << patient.totalCost<< endl; // Time Request (int)
    }

    outFile.close(); // Close the file
}

//Admin
string SaveToFile::return_admin_name(int index) {
    ifstream file("AdminFile.text");
    if (!file.is_open()) {
        cout << "Could not open DoctorsFile.text!" << endl;
        return "";
    }
    string line;
    int targetLine = (index - 1) * 2 + 0;
    int currentLine = 0;
    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return line;
        }
        currentLine++;
    }
    file.close();
    cout << "didn't return doctor name" << endl;
    return "";  // if not found
}
int SaveToFile::return_admin_ID(int index) {
    ifstream file("AdminFile.text");
    string line;
    int targetLine = (index - 1) * 2 + 1;
    int currentLine = 0;

    while (getline(file, line)) {
        if (currentLine == targetLine) {
            file.close();
            return std::stoi(line);
        }
        currentLine++;
    }

    file.close();
    cout << "didn't return doctor id" << endl;
    return -1;  // if not found
}

//precreption
int SaveToFile::return_value_of_item(string name) {
    ifstream file("PrecreptionValues.text");
    string line;
    while (getline(file, line)) {
        if (line == name) {
            if (getline(file, line)) {
                file.close();
                cout << line << endl;
                return stoi(line);
            }
        }
    }
    file.close();
    cout << "didn't find any connections" << endl;
    return -1;  // if not found
}