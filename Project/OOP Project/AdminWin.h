#pragma once
#include <vector>
#include "Admin.h"
#define ADMINWIN_H

class AdminWin {
private:
	System adminSystem;
	SaveToFile adminFile;
	UI uiadmin;
	std::vector<Admin> AdminList;
	std::vector<Doctor> doctorsList;
	std::vector<Patient> patientsList;
	int profileNum;
public:
	AdminWin(std::string name);
	~AdminWin();
	void loadData();
	void checkNewAdmin(std::string name);
	void mainWindow(Admin& x);
	void new_admin(std::string userName);
};