#pragma once
#include "Doctor.h"
#include "SaveToFileClass.h"
#include <vector>
#define SYSTEM_H
#define MYDOCTOR_H

class System {
	std::string systemName;
	SaveToFile systemFile;
public:
	std::vector<Doctor> doctorsList;
	std::vector<Patient> patientsList;
	System(std::string x);
	std::vector<Doctor> getAllDoctors();
	std::vector<Patient> getAllPatients();
};