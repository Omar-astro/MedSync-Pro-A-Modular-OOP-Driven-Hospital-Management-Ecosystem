#include <iostream>
#include "Patient.h"
#include "Doctor.h"

using namespace std;

// Default constructor
Doctor::Doctor() {
    Schedule.push_back(-1); // Initialize with a single value
    MinavailableTime = -1;
    MaxavailableTime = -1;
}

// Copy constructor
Doctor::Doctor(const Doctor& other) {
    name = other.name;
    specialists = other.specialists;
    id = other.id;
    MinavailableTime = other.MinavailableTime;
    MaxavailableTime = other.MaxavailableTime;
    Schedule = other.Schedule; // std::vector handles deep copying
}

// Copy assignment operator
Doctor& Doctor::operator=(const Doctor& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Copy data members
    name = other.name;
    specialists = other.specialists;
    id = other.id;
    MinavailableTime = other.MinavailableTime;
    MaxavailableTime = other.MaxavailableTime;
    Schedule = other.Schedule; // std::vector handles deep copying

    return *this;
}

// Destructor
Doctor::~Doctor() {
    // No need to manually delete Schedule, std::vector handles it
}

string Doctor::checkSpeciality() const {
    return specialists;
}

int Doctor::getID() const {
    return id;
}

void Doctor::viewSchedule() {
    for (int time : Schedule) { // Use range-based for loop
        cout << time << " , ";
    }
    cout << endl;
}

void Doctor::addPrecrecption(Patient& x, string illness) {
    /*x.returnPrecreption(illness, specialists, name, id);*/
}

void Doctor::setTime(int minTime, int maxTime) {
    MinavailableTime = minTime;
    MaxavailableTime = maxTime;
}

void Doctor::setSpecialists(string x) {
    specialists = x;
}

void Doctor::updateInfo(string x, string y) {
    name = x;
    specialists = y;
}

void Doctor::setName(string x) {
    name = x;
}

string Doctor::getname() const {
    return name;
}

void Doctor::setID(int x) {
    id = x;
}

void Doctor::addToSchedule(int newValue) {
    Schedule.push_back(newValue); // Add new value to the vector
}

void Doctor::removeFromSchedule(int indexToRemove) {
    if (indexToRemove < 0 || indexToRemove >= Schedule.size()) {
        cout << "Invalid index!\n";
        return;
    }
    Schedule.erase(Schedule.begin() + indexToRemove); // Remove value at the specified index
}
