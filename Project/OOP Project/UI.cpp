#include<iostream>
#include "UI.h"
#include "Admin.h"

using namespace std;

UI::UI() {
	cout << "Welcome" << endl;
}

void UI::register_ui(string &username, string &password, string &role) {
	string x, y, z;
	cout << "Type your username | Password | Role" << endl;
	cin >> x >> y >> z;
	cout << endl;
	for (char& c : x) {
		c = tolower(c);
	}
	for (char& c : y) {
		c = tolower(c);
	}
	for (char& c : z) {
		c = tolower(c);
	}
	username = x;
	password = y;
	role = z;
}

int UI::FirstLogin() {
	int logNum;
	cout << "Hospital System" << endl << "choose your login method" << endl << "[1] Register" << endl << "[2] Login" << endl << "[3] Exit" << endl;
	cin >> logNum;
	cout << endl;
	return logNum;
}

void UI::login_ui(string &tempuser, string &tempPass, int i) {
	string x, y;
	switch (i)
	{
	case 1:
		cout << "Type your username | Password" << endl;
		cin >> x >>  y;
		cout << endl;
		for (char& c : x) {
			c = tolower(c);
		}
		for (char& c : y) {
			c = tolower(c);
		}
		tempuser = x;
		tempPass = y;
		break;
	case 2:
		cout << "logged in successfully" << endl;
		break;
	case 3:
		cout << "wrong password" << endl;
		break;
	case 4:
		cout << "no user found" << endl;
		break;
	case 5:
		cout << "error type a real number from the ones provided";
		break;
	default:
		break;
	}
}

// Doctor UI functions
int UI::DoctorWin() {
	int x;
	cout << "[1] View Schedule" << endl <<
		"[2] Remove Time" << endl <<
		"[3] addPrecreption" << endl <<
		"[4] update info" << endl <<
		"[5] View Profile" << endl <<
		"[6] Exit" << endl;
	cin >> x;
	return x;
}
int UI::RemoveTimeUI() {
	int x;
	cout << "Write the index of the time you want to remove: " << endl;
	cin >> x;
	cout << endl << "Time removed succefully" << endl;
	return x;
}
void UI::viewScheduleUI(int x, int* &list, int size) {
	switch (x)
	{
	case 1:
		cout << "there are no times in the schedule" << endl;
		break;
	case 2:
		cout << "Times occupied are: " << endl;
		for (int i = 0; i < size; i++) {
			cout << list[i] << " PM" << endl;
		}
	}
}
string UI::setspecialUI() {
	string x;
	cout << "Please Enter Your speciality (Cardiologist/Neurologist/Dermatologist/Pediatrician/Orthopedic/Psychiatrist/GeneralPractitioner)" << endl;
	cin >> x;
	cout << endl;
	for (char& c : x) {
		c = tolower(c);
	}
	return x;
}
void UI::setdoctimes(int &min, int& max) {
	int x, y;
	cout << "Enter the Starting time of your job: ";
	cin >> x;
	cout << endl << "Enter the ending time of your job: ";
	cin >> y; cout << endl;
	min = x;
	max = y;
}
string UI::setDocNameUI() {
	string x;
	cout << "please type the desired new name: ";
	cin >> x;
	for (char& c : x) {
		c = tolower(c);
	}
	return x;
}
void UI::PrintdocInfo(string name, string special, int id) {
	cout << "Name: " << name << endl
		<< "ID: " << id << endl
		<< "Speciality: " << special << endl;
}
void UI::errorUI() {
	cout << "Error occured typing a number" << endl;
}
void UI::addPrecreptionUI(int x) {
	switch (x)
	{
	case 1:
		cout << "No patients available for this doctor." << endl;
		break;
	default:
		break;
	}
}
void UI::addPrecreptionUI2(const vector<Patient>& names, int& y, string& z) {
	cout << "patients available for you are: " << endl;
	for (int i = 0; i < names.size(); i++) {
		cout << i + 1 << ": " << names[i].checkName() << " at "
			<< names[i].timeRequest << "PM" << endl;
	}

	cout << "Please choose the patient you want to add a precreption for: ";
	cin >> y; cout << endl;
	cout << "What does the patient have? (illness): ";
	cin >> z; cout << endl;
	for (char& c : z) {
		c = tolower(c);
	}
}

// Patient UI functions
string UI::setSpecialistsRequestUI() {
	string x;
	cout << "Please Enter Your desired specialists (Cardiologist/Neurologist/Dermatologist/Pediatrician/Orthopedic/Psychiatrist/GeneralPractitioner): " << endl;
	cin >> x;
	cout << endl;
	for (char& c : x) {
		c = tolower(c);
	}
	return x;
}
int UI::PatientWin() {
	int x;
	cout << "[1] Book Apointment" << endl <<
		"[2] Check Out" << endl <<
		"[3] update info" << endl <<
		"[4] View Profile" << endl <<
		"[5] Exit" << endl;
	cin >> x;
	return x;
}
void UI::PrintPatInfo(Patient& x) {
	cout << "Name: " << x.checkName() << endl
		<< "ID: " << x.getID() << endl
		<< "Illness: " << x.getIllness() << endl
		<< "Specialist Request: " << x.specialistRequest << endl
		<< "Time Request: " << x.timeRequest << endl;
}
string UI::setPatNameUI() {
	string x;
	cout << "please type the desired new name: ";
	cin >> x;
	for (char& c : x) {
		c = tolower(c);
	}
	return x;
}
int UI::setBookingTimeUI() {
	int x;
	cout << "Please enter the time you want to book: " << endl;
	cin >> x;
	return x;
}
void UI::BookApointment(int x) {
	switch (x)
	{
	case 1:
		cout << "you already have a request" << endl;
		break;
	case 2:
		cout << "your request has been sent" << endl;
		break;
	default:
		break;
	}
}
void UI:: check_out(int x) {
	switch (x){
	case 1:
		cout << "you have still didn't check with the doctor" << endl;
		break;
	default:
		break;
	}
}
void UI::returnPrecreption(const Doctor& x,const  Patient& y, int cost) {
	cout << "doctor's name: " << x.getname() << endl
		<< "doctor's id: " << x.getID() << endl
		<< "Doctor's speciality: " << x.checkSpeciality() << endl
		<< "patient's name: " << y.checkName() << endl
		<< "patient's id: " << y.getID() << endl
		<< "Illness: " << y.getIllness() << endl
		<< "Total fees: " << cost << endl
		<< "please procced to the checkout." << endl;
}

// Admin UI dunctions
int UI::AdminWin() {
	int x;
	cout << "[1] Remove Patient" << endl <<
		"[2] Check For Requests" << endl <<
		"[3] UpdateInfo" << endl <<
		"[4] View Profile" << endl <<
		"[5] Exit" << endl;
	cin >> x;
	cout << endl;
	return x;
}
int UI::RemovePatientUI(const vector<Patient>& names) {
	int x;
	cout << "choose a patient to remove" << endl;
	for (int i = 0; i < names.size(); i++) {
		cout << i + 1 << ": " << names[i].checkName() << endl;
	}
	cin >> x;
	return x - 1;
}
void UI::OtherPatientUI(int x) {
	switch (x)
	{
	case 1:
		cout << "patient removed successfully" << endl;
		break;
	case 2:
		cout << "Name changed successfully " << endl;
		break;
	case 3:
		cout << "Updated Patients with their doctors successfully" << endl;
		break;
	case 4:
		cout << "no patients found with requests" << endl;
		break;
	case 5:
		cout << "no doctor was found with this speciality" << endl;
		break;
	case 6:
		cout << "selected time doesn't suit the doctor found" << endl;
		break;
	case 7:
		cout << "time set successfully with doctor " << endl;
		break;
	case 8:
		cout << "time already taken" << endl;
		break;
	default:
		break;
	}
}
void UI::PrintAdminInfo(Admin& x) {
	cout << "Name: " << x.getName() << endl
		<< "ID: " << x.getID() << endl;
}
string UI::UpdateAdminInfo(){
	string x;
	cout << "please type the desired new name: ";
	cin >> x;
	for (char& c : x) {
		c = tolower(c);
	}
	return x;
}