#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "DoctorWin.h"

using namespace std;

DoctorWin::DoctorWin(string username) :DocSystem("Doctor_System"){
    loadData();
    CheckNewDoctor(username);

    if (DoctorList.empty()) {
        cerr << "Error: No doctors available in the system." << endl;
        return;
    }

    if (profilenum < 0 || profilenum >= DoctorList.size()) {
        cerr << "Error: Invalid profile number." << endl;
        return;
    }

    //cout << "check doctor finished" << endl;
    mainWindow(DoctorList[profilenum]);
}

void DoctorWin::addToDoctorList(const Doctor& newDoctor) {
    DoctorList.push_back(newDoctor); // Add new doctor to the vector
}

void DoctorWin::CheckNewDoctor(string username) {
    bool found = false;
    for (size_t i = 0; i < DoctorList.size(); i++) {
        if (DoctorList[i].getname() == username) {
            found = true;
            profilenum = i;
            break;
        }
    }
    if (!found) {
        new_doc(username);
    }
}

void DoctorWin::new_doc(string docname) {
    Doctor doctor;
    doctor.setName(docname);
    int newID = rand() % 9001 + 1000; // Generate random ID
    doctor.setID(newID);
    setSpecialWin(doctor);
    setMinNMaxTime(doctor);
    profilenum = DoctorList.size(); // Set the profile number to the current size
    addToDoctorList(doctor);
}

void DoctorWin::setMinNMaxTime(Doctor& x) {
    uidoc.setdoctimes(x.MinavailableTime, x.MaxavailableTime);
}

void DoctorWin::setSpecialWin(Doctor& x) {
    x.setSpecialists(uidoc.setspecialUI());
}

void DoctorWin::loadData() {
    DoctorList.clear(); // Clear the vector before loading data
    int numProfiles = doctorFile.countDoctorProfiles();

    for (int i = 0; i < numProfiles; i++) {
        int tempMin, tempMax;
        Doctor doctor;
        doctor.setName(doctorFile.return_doctor_name(i + 1));
        doctor.setID(doctorFile.return_doctor_id(i + 1));
        doctor.setSpecialists(doctorFile.return_doctor_speciality(i + 1));
        doctor.MinavailableTime = doctorFile.return_doctor_Mintime(i + 1);
        doctor.MaxavailableTime = doctorFile.return_doctor_Maxtimes(i + 1);
        doctor.Schedule = vector<int>(doctorFile.return_doctor_schedule(i + 1));
        DoctorList.push_back(doctor); // Add doctor to the vector
    }
}

void DoctorWin::viewschedule(Doctor& x) {
    if (x.Schedule.size() == 1 && x.Schedule[0] == -1) {
        int* scheduleData = x.Schedule.data(); // Temporary variable
        uidoc.viewScheduleUI(1, scheduleData, x.Schedule.size());
    }
    else {
        cout << x.Schedule.size() << "\t" << x.Schedule[0] << endl;
        int* scheduleData = x.Schedule.data(); // Temporary variable
        uidoc.viewScheduleUI(2, scheduleData, x.Schedule.size());
    }
}

void DoctorWin::RemoveTimes(Doctor& x) {
    int indexToRemove = uidoc.RemoveTimeUI();
    x.removeFromSchedule(indexToRemove);
}

void DoctorWin::Updateinfo(Doctor& x) {
    x.setName(uidoc.setDocNameUI());
    setSpecialWin(x);
    setMinNMaxTime(x);
}

void DoctorWin::addprecreption(Doctor& x) {
	PatientsList = DocSystem.getAllPatients();
    for (int i = 0; i < PatientsList.size(); i++) {
        if (PatientsList[i].specialistRequest == x.checkSpeciality()) {
			availablePatientsList.push_back(PatientsList[i]);
        }
    }

	int size = availablePatientsList.size();
	if (availablePatientsList.empty()) {
		uidoc.addPrecreptionUI(1);
	}

    int y; string z;
	uidoc.addPrecreptionUI2(availablePatientsList, y, z);
    availablePatientsList[y - 1].setPrecreption(z, x);
	cout <<availablePatientsList[y - 1].totalCost << endl;
	doctorFile.updatePatientTotalCostInFile(availablePatientsList[y - 1].checkName(),
                                            availablePatientsList[y - 1].totalCost);
    doctorFile.updatePatientIllnessInFile(availablePatientsList[y - 1].checkName(),
                                            z);
}

void DoctorWin::mainWindow(Doctor& x) {
    bool online = true;
    while (online) {
        int win_num = uidoc.DoctorWin();
        switch (win_num) {
        case 1:
            viewschedule(x);
            break;
        case 2:
            RemoveTimes(x);
            break;
        case 3:
            addprecreption(x);
            break;
        case 4:
            Updateinfo(x);
            break;
        case 5:
            uidoc.PrintdocInfo(x.getname(), x.checkSpeciality(), x.getID());
            break;
        case 6:
            online = false;
            break;
        default:
            uidoc.errorUI();
            break;
        }
    }
}

DoctorWin::~DoctorWin() {
    //cout << "destructro called" << endl;
    //cout << "times: " << DoctorList[0].MinavailableTime << DoctorList[0].MaxavailableTime << endl;
    doctorFile.saveAllDoctors(DoctorList);
}