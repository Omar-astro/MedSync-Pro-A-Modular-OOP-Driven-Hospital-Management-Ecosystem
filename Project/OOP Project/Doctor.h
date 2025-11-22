#pragma once
#define MYDOCTOR_H
#include <vector> // Include vector

class Patient;

class Doctor {
private:
    std::string name, specialists;
    int id;
public:
    std::vector<int> Schedule; // Replace dynamic array with std::vector
    int MinavailableTime, MaxavailableTime;

    // Default constructor
    Doctor();

    // Copy constructor
    Doctor(const Doctor& other);

    // Copy assignment operator
    Doctor& operator=(const Doctor& other);

    // Destructor
    ~Doctor();

    void setName(std::string x);
    std::string getname() const;
    void setID(int x);
    std::string checkSpeciality() const;
    int getID() const;
    void viewSchedule();
    void addPrecrecption(Patient& x, std::string illness);
    void setTime(int minTime, int maxTime);
    void setSpecialists(std::string x);
    void updateInfo(std::string x, std::string y);
    void addToSchedule(int newValue); // Updated to use std::vector
    void removeFromSchedule(int indexToRemove); // Updated to use std::vector
};
