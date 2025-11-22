#include<iostream>
#include "precreption.h"
#include "Patient.h"

using namespace std;

Patient:: Patient() {
		Request = false;
	}

//Patient:: Patient(string x, int y) {
//		name = x;
//		id = y;
//		illness = "";
//	}

string Patient::checkName() const  {
		return name;
	}

bool Patient::checkRequest() {
		return Request;
	}

//string Patient::specialistsrequest(string illnessReq) {
//		if (illness == "") return illness;
//		else return illnessReq;
//	}

void Patient::setPrecreption(string illness, Doctor& x) { //doctor calls this
	setIllness(illness);
	set_checked_with_doctor(x);
	totalCost = returnPrecreption();
}

int Patient::returnPrecreption() {
	patientPrecreption.illnessCost(illness);
	patientPrecreption.doctorCost(checkedWithDoctor.checkSpeciality());
	return patientPrecreption.totalCost();
}

void Patient::updateInfo(string newName, string newIllness) {
		name = newName;
		illness = newIllness;
	}

void Patient::bookAppointment() {
		Request = true;
	}

//setters
void Patient::setName(string newName) { name = newName; }
void Patient::setID(int newID) { id = newID; }
void Patient::setIllness(string newIllness) { illness = newIllness;}
void Patient::set_checked_with_doctor(Doctor x) { checkedWithDoctor = x; }
void Patient::setSpecialistsRequest(string newSpecialist) { specialistRequest = newSpecialist; }
void Patient::setRequest(bool newRequest) { Request = newRequest; }
void Patient::setTimeRequest(int newtimeRequest) { timeRequest = newtimeRequest; }

//getters
int Patient::getID() const { return id; }
string Patient::getIllness() const { return illness; }
const Doctor& Patient::getDoctor() const { return checkedWithDoctor; }
int Patient::getRequest() const {
	if (Request) {
		return 1;
	}
	else {
		return 0;
	}
}