#include<iostream>
#include "Doctor.h"
#include "Patient.h"
#include "System.h"
#include "Admin.h"

using namespace std;

void Admin::setName(string newName) { name = newName; }
string Admin::getName() { return name; }
void Admin::setID(int newID) { id = newID; }
int Admin::getID() { return id; }

void Admin::secondLoop(System& x,int i ,int j) {
	for (int k = 0; k < x.doctorsList[j].Schedule.size(); k++) { // loops for the doctor's schedule
		if (x.patientsList[i].timeRequest == x.doctorsList[j].Schedule[k]) {
			inUIAdimn.OtherPatientUI(8);
			break;
		} else {
			if (x.doctorsList[j].Schedule[0] == -1) {
				x.doctorsList[j].Schedule.clear();
			}
			x.doctorsList[j].Schedule.push_back(x.patientsList[i].timeRequest);
			cout << "HERE: " << x.doctorsList[j].Schedule[0] << endl;
			inUIAdimn.OtherPatientUI(7);
			break;
		}
	}
}

void Admin::firstLoop(System& x, int i) {
	for (int j = 0; j < x.doctorsList.size(); j++) { // loops for each doctor
		if (x.patientsList[i].specialistRequest == x.doctorsList[j].checkSpeciality()) { // checks if the rquested specialist is in this doctor
			if (x.patientsList[i].timeRequest < x.doctorsList[j].MaxavailableTime &&
				x.patientsList[i].timeRequest > x.doctorsList[j].MinavailableTime) { // checks if the requested time suits the doctor
				secondLoop(x, i, j);
			}
			else { inUIAdimn.OtherPatientUI(6); }
		}
		else { inUIAdimn.OtherPatientUI(5); }
	}
	
}

void Admin:: checkForRequests(System& x) {
		for (int i = 0; i < x.patientsList.size(); i++) { // loops for every patient
			if (x.patientsList[i].checkRequest()) { // checks if the patient has request
				firstLoop(x, i);
			}
			else { inUIAdimn.OtherPatientUI(4); }
		}
	}

