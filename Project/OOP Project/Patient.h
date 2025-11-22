#pragma once
#include "precreption.h"
#include "Doctor.h"
#define MYPATIENT_H

//Illness is the one the doctor types for the precreption and then counts the cost in the precreption class
//specialistRequest is the one the patient types for the doctor

class Patient {
private:
	std::string name, illness;
	int id;
	bool Request;
	precreption patientPrecreption;
	Doctor checkedWithDoctor;
public:
	std::string specialistRequest;
	int timeRequest, totalCost;

	Patient();
	/*Patient(std::string x, int y);*/
	std::string checkName() const;
	bool checkRequest();
	/*std::string specialistsrequest(std::string illnessReq);*/
	int returnPrecreption();
	void updateInfo(std::string newName, std::string newIllness);
	void bookAppointment();
	void setName(std::string newName);
	void setID(int newID);
	void setIllness(std::string newIllness);
	void set_checked_with_doctor(Doctor x);
	void setPrecreption(std::string illness, Doctor& x);
	void setSpecialistsRequest(std::string newSpecialist);
	void setRequest(bool newRequest);
	void setTimeRequest(int newtimeRequest);
	int getID() const;
	int getRequest() const;
	const Doctor& getDoctor() const;
	std::string getIllness() const;
};