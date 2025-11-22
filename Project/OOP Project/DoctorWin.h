#pragma once
#define DOCTORWIN_H
#include "Doctor.h"
#include "UI.h"
#include "System.h"
#include "SaveToFileClass.h"
#include <vector> // Include vector

class DoctorWin {
private:
    SaveToFile doctorFile;
    System DocSystem;
    UI uidoc;
    std::vector<Doctor> DoctorList; // Replace dynamic array with std::vector
    std::vector<Patient> PatientsList;
    std::vector<Patient> availablePatientsList;
    int numOfProf, profilenum;

public:
    DoctorWin(std::string username);
    ~DoctorWin();
    void CheckNewDoctor(std::string username);
    void mainWindow(Doctor& x);
    void loadData();
    void new_doc(std::string docname);
    void setSpecialWin(Doctor& x);
    void setMinNMaxTime(Doctor& x);
    void viewschedule(Doctor& x);
    void RemoveTimes(Doctor& x);
    void Updateinfo(Doctor& x);
    void addprecreption(Doctor& x);
    void addToDoctorList(const Doctor& newDoctor);
};
