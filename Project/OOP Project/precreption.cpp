#include<iostream>
#include "precreption.h"

using namespace std;

precreption:: precreption() {
		cost = 50;
	}
void precreption::illnessCost(string x) {
	cost += precFile.return_value_of_item(x);
}

void precreption::doctorCost(string x) {
	cost += precFile.return_value_of_item(x);
}

int precreption::totalCost() {
		return cost;
	}