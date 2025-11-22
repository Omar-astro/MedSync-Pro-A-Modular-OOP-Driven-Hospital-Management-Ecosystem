#include<iostream>
#include "PatientWin.h"

using namespace std;

PatientWin::PatientWin(string name) {
    loadData();
    CheckNewPatient(name);

    if (PatientList.empty()) {
        cerr << "Error: No doctors available in the system." << endl;
        return;
    }

    if (profileNum < 0 || profileNum >= PatientList.size()) {
        cerr << "Error: Invalid profile number." << endl;
        return;
    }

    cout << "check doctor finished" << endl;
    mainWindow(PatientList[profileNum]);
}

void PatientWin::loadData() {
    PatientList.clear(); // Clear the vector before loading data
    int numProfiles = patientFile.countPatientProfiles();

    for (int i = 0; i < numProfiles; i++) {
        int tempMin, tempMax;
        Patient patient;
        patient.setName(patientFile.return_Patient_name(i + 1));
        patient.setID(patientFile.return_Patient_ID(i + 1));
        patient.setIllness(patientFile.return_Patient_illness(i + 1));
        patient.setSpecialistsRequest(patientFile.return_Patient_specialistsRequest(i + 1));
		patient.setRequest(patientFile.return_Patient_Request(i + 1));
		patient.setTimeRequest(patientFile.return_Patient_TimeRequest(i + 1));
        patient.totalCost = patientFile.return_Patient_TotalCost(i + 1);
        PatientList.push_back(patient); // Add doctor to the vector
    }
}

void PatientWin::CheckNewPatient(string username) {
    bool found = false;
    for (size_t i = 0; i < PatientList.size(); i++) {
        if (PatientList[i].checkName() == username) {
            found = true;
            profileNum = i;
            break;
        }
    }
    if (!found) {
        new_pat(username);
    }
}

void PatientWin::new_pat(string patname) {
    Patient patient;
    patient.setName(patname);
    int newID = rand() % 9001 + 1000;
    patient.setID(newID);
	patient.setIllness("none");
	patient.setSpecialistsRequest("none");
	patient.setRequest(false);
	patient.setTimeRequest(-1);
	PatientList.push_back(patient); 
}

void PatientWin::setSpecialistsRequestWin(Patient& x) {
	x.setSpecialistsRequest(uipat.setSpecialistsRequestUI());
}

void PatientWin::UpdateProfile(Patient& x) {
	x.setName(uipat.setPatNameUI());
}

void PatientWin::setBookingTime(Patient& x) {
	x.setTimeRequest(uipat.setBookingTimeUI());
}

void PatientWin::mainWindow(Patient& x) {
	bool online = true;
	while (online) {
		int win_num = uipat.PatientWin();
		switch (win_num) {
		case 1: // book appointment
			if (x.checkRequest()) {
				uipat.BookApointment(1);
			} else {
                setSpecialistsRequestWin(x);
                setBookingTime(x);
                x.bookAppointment();
				uipat.BookApointment(2);
			}
			break;
		case 2: //check out
            if (x.getIllness() == "none") {
				uipat.check_out(1);
            } else {
				totalcost = x.returnPrecreption();
				uipat.returnPrecreption(x.getDoctor(), x, totalcost);
            }
			break;
		case 3: // update info
			x.setName(uipat.setPatNameUI());
			break;
		case 4: //view profile
			uipat.PrintPatInfo(x);
			break;
		case 5: // exit
            online = false;
			break;
		default:
			uipat.errorUI();
			break;
		}
	}
}

PatientWin::~PatientWin() {
	patientFile.saveAllPatients(PatientList);
}