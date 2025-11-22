#include<iostream>
#include "LoginClass.h"
#include "PatientWin.h"
#include "AdminWin.h"
#include "DoctorWin.h"
using namespace std;

void loginwin::loginwin1() {
	logNum = ui.FirstLogin();
}

void loginwin::register_in() {
	string username, password, role;
	ui.register_ui(username, password, role);
	file1.add_user(username, password, role);
}

void loginwin::log_in() {
	ui.login_ui(tempUser, tempPass, 1);
	for (int i = 1; i <= file1.count_profiles(); i++) {
		if (file1.return_name(i) == tempUser) {
			if (file1.return_password(i) == tempPass) {
				ui.login_ui(tempUser, tempPass, 2);
				profileNum = i;
				check_for_win();
				break;
			}
			else {
				ui.login_ui(tempUser, tempPass, 3);}
			break;
		}
		else { if (i == 20) { ui.login_ui(tempUser, tempPass, 4); } }
	}
}

void loginwin:: check_for_win() {
	string role = file1.return_role(profileNum);
	for (char& c : role) {
		c = tolower(c);
	}
	if (role == "doctor") {
		DoctorWin docwin(file1.return_name(profileNum));
	} else if (role == "patient") {
		PatientWin patwin(file1.return_name(profileNum));
	} else if (role == "admin") {
		AdminWin admWin(file1.return_name(profileNum));
	} else {
		cout << "error opening a window" << endl;
	}
}

void loginwin::exit_app() {
	exit(0);
}

void loginwin::loginfunc() {
	while (true) {
		loginwin1();
		chose_log_in();
	}
}

loginwin::loginwin() {
	loginfunc();
}

void loginwin:: chose_log_in() {
	switch (logNum)
	{
	case 1:
		register_in();
		break;
	case 2:
		log_in();
		break;
	case 3:
		exit_app();
		break;
	default:
		ui.login_ui(tempUser, tempPass, 5);
	}
}
	