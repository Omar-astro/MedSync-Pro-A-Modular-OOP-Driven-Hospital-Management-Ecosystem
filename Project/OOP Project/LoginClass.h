#pragma once
#define LOGINCLASS_H
#include<string>
#include "UI.h"
#include "SaveToFileClass.h"

class loginwin {
private:
	int logNum, userNum, profileNum;
	std::string tempUser, tempPass;
	UI ui;
	SaveToFile file1;
public:
	loginwin();
	void loginfunc();
	void loginwin1();
	void chose_log_in();
	void log_in();
	void register_in();
	void exit_app();
	void check_for_win();
};