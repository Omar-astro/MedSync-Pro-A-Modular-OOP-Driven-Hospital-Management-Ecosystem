#pragma once
#include <vector>
class Doctor;
class Patient;
#define MYDOCTOR_H

class SaveToFile {
private:
    void createLoginFile();
public:
    void add_user(std::string username, std::string password, std::string role);
    std::string* loadUser(int index);
    std::string return_name(int i);
    std::string return_password(int i);
    int count_profiles();
    std::string return_role(int i);
    int countDoctorProfiles();
    int return_doctor_id(int index);
    std::string return_doctor_speciality(int index);
    std::string return_doctor_name(int index);
    int return_doctor_Maxtimes(int index);
    int return_doctor_Mintime(int index);
    std::vector<int> return_doctor_schedule(int index);
    void saveAllDoctors(const std::vector<Doctor>& doctors);
    int countPatientProfiles();
    std::string return_Patient_name(int index);
    int return_Patient_ID(int index);
    std::string return_Patient_illness(int index);
    std::string return_Patient_specialistsRequest(int index);
    int return_Patient_Request(int index);
    int return_Patient_TimeRequest(int index);
    int return_value_of_item(std::string name);
    int return_Patient_TotalCost(int index);
    void updatePatientTotalCostInFile(const std::string& patientName, int newTotalCost);
    void updatePatientIllnessInFile(const std::string& patientName, std::string newIllness);
    void saveAllPatients(const std::vector<Patient>& patients);
    std::string return_admin_name(int index);
	int return_admin_ID(int index);
};