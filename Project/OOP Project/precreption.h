#pragma once
#include <string>
#include "SaveToFileClass.h"
#define PRECREPTION_H

class precreption {
	std::string illness;
	int cost;
	SaveToFile precFile;
public:
	precreption();
	void illnessCost(std::string x);
	void doctorCost(std::string x);
	int totalCost();
};