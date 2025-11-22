#pragma once
#define PATIENTWIN_H
#include "Patient.h"
#include "SaveToFileClass.h"
#include "UI.h"
#include <vector>

class PatientWin {
private:
	SaveToFile patientFile;
	UI uipat;
	int numOfProf, profileNum, totalcost;
	std::vector<Patient> PatientList;
public:
	PatientWin(std::string name);
	~PatientWin();
	void loadData();
	void CheckNewPatient(std::string username);
	void new_pat(std::string patname);
	void setSpecialistsRequestWin(Patient& x);
	void mainWindow(Patient& x);
	void UpdateProfile(Patient& x);
	void setBookingTime(Patient& x);
};