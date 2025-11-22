#pragma once
#include <vector>
#include "System.h"
#include "SaveToFileClass.h"
#include "UI.h"
#include "Doctor.h"
#include "Patient.h"
#define ADMIN_H

class Admin {
	std::string name;
	int id;
	UI inUIAdimn;
public:
	void setName(std::string newName);
	std::string getName();
	void setID(int newID);
	int getID();
	/*void addDocotor(System x, Doctor y);
	void removePatinet(System x, Patient y); */
	void checkForRequests(System& y);
	void firstLoop(System& x, int i);
	void secondLoop(System& x, int i ,int j);
};