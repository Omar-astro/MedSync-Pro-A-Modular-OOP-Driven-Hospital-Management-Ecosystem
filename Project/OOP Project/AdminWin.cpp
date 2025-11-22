#include <iostream>
#include "AdminWin.h"
#include "System.h"

using namespace std;

AdminWin::AdminWin(string name) :adminSystem("Admin_system") {
	loadData();
	checkNewAdmin(name);
	if (AdminList.empty()) {
		cerr << "Error: No doctors available in the system." << endl;
		return;
	}
	if (profileNum < 0 || profileNum >= AdminList.size()) {
		cerr << "Error: Invalid profile number." << endl;
		return;
	}
	mainWindow(AdminList[profileNum]);
}

void AdminWin::loadData() {
    AdminList.clear(); // Clear the vector before loading data
    int numProfiles = AdminList.size();

    for (int i = 0; i < numProfiles; i++) {
        int tempMin, tempMax;
        Admin admin;
        admin.setName(adminFile.return_admin_name(i + 1));
        admin.setID(adminFile.return_admin_ID(i + 1));
        AdminList.push_back(admin); // Add doctor to the vector
    }
}

void AdminWin::checkNewAdmin(string name) {
    bool found = false;
    for (size_t i = 0; i < AdminList.size(); i++) {
        if (AdminList[i].getName() == name) {
            found = true;
            profileNum = i;
            break;
        }
    }
    if (!found) {
        new_admin(name);
    }
}

void AdminWin::new_admin(string admName) {
    Admin admin;
    admin.setName(admName);
    int newID = rand() % 9001 + 1000;
    admin.setID(newID);
	AdminList.push_back(admin);
}

void AdminWin::mainWindow(Admin& x) {
	patientsList = adminSystem.getAllPatients();
	doctorsList = adminSystem.getAllDoctors();
    bool online = true;
    while (online) {
		int patToRemove;
		int win_num = uiadmin.AdminWin();
		switch (win_num) {
		case 1: 
			patToRemove = uiadmin.RemovePatientUI(patientsList);
			patientsList.erase(patientsList.begin() + patToRemove);
			uiadmin.OtherPatientUI(1);
			break;
		case 2:
			x.checkForRequests(adminSystem);
			uiadmin.OtherPatientUI(3);
			break;
		case 3:
			x.setName(uiadmin.UpdateAdminInfo());
			uiadmin.OtherPatientUI(2);
			break;
		case 4:
			uiadmin.PrintAdminInfo(x);
			break;
		case 5:
			online = false;
			break;
		default:
			uiadmin.errorUI();
			break;
		}
    }
}

AdminWin::~AdminWin() {
	//cout << doctorsList[0].Schedule[1] << endl;
	adminFile.saveAllPatients(patientsList);
	adminFile.saveAllDoctors(adminSystem.doctorsList);
}