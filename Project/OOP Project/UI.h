#pragma once
#include "Patient.h"
#define UI_H

class Admin;

class UI {
private:

public:
	UI();
	int FirstLogin();
	void register_ui(std::string &username, std::string &password, std::string &role);
	void login_ui(std::string &tempuser,std::string &tempPass,int i);
	int DoctorWin();
	std::string setspecialUI();
	void setdoctimes(int& min, int& max);
	void viewScheduleUI(int x, int*& list, int size);
	int RemoveTimeUI();
	std::string setDocNameUI();
	void PrintdocInfo(std::string name, std::string special, int id);
	void errorUI();
	std::string setSpecialistsRequestUI();
	int PatientWin();
	void PrintPatInfo(Patient& x);
	std::string setPatNameUI();
	void BookApointment(int x);
	int setBookingTimeUI();
	void check_out(int x);
	void returnPrecreption(const Doctor& x, const Patient& y, int cost);
	void addPrecreptionUI(int x);
	void addPrecreptionUI2(const std::vector<Patient>& names, int& y, std::string& z);
	int AdminWin();
	int RemovePatientUI(const std::vector<Patient>& names);
	void OtherPatientUI(int x);
	void PrintAdminInfo(Admin& x);
	std::string UpdateAdminInfo();
};