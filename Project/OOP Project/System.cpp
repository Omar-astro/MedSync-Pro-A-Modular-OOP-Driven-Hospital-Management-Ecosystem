#include<iostream>
#include "Doctor.h"
#include "Patient.h"
#include "System.h"
using namespace std;

System:: System(string x) {
		systemName = x;
        
	}

vector<Doctor> System::getAllDoctors() {
    doctorsList.clear(); // Clear the vector before loading data
    int numProfiles = systemFile.countDoctorProfiles();

    for (int i = 0; i < numProfiles; i++) {
        Doctor doctor;
        doctor.setName(systemFile.return_doctor_name(i + 1));
        doctor.setID(systemFile.return_doctor_id(i + 1));
        doctor.setSpecialists(systemFile.return_doctor_speciality(i + 1));
        doctor.MinavailableTime = systemFile.return_doctor_Mintime(i + 1);
        doctor.MaxavailableTime = systemFile.return_doctor_Maxtimes(i + 1);
        doctor.Schedule = systemFile.return_doctor_schedule(i + 1);
        doctorsList.push_back(doctor);
    }
    return doctorsList;
}

vector<Patient> System::getAllPatients() {
    patientsList.clear(); // Clear the vector before loading data
    int numProfiles = systemFile.countPatientProfiles();

    for (int i = 0; i < numProfiles; i++) {
        Patient patient;
        patient.setName(systemFile.return_Patient_name(i + 1));
        patient.setID(systemFile.return_Patient_ID(i + 1));
        patient.setIllness(systemFile.return_Patient_illness(i + 1));
        patient.setSpecialistsRequest(systemFile.return_Patient_specialistsRequest(i + 1));
        patient.setRequest(systemFile.return_Patient_Request(i + 1));
        patient.setTimeRequest(systemFile.return_Patient_TimeRequest(i + 1));
        patientsList.push_back(patient);
    }
    return patientsList;
}