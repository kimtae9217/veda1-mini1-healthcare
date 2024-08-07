#ifndef MEAL_H
#define MEAL_H

#include <iostream>
#include <string>

using namespace std;

class meal {
public:
    int id;
    string name;
    string food;
    int totalCalories;

    meal(int id, string name, string food, int totalCalories)
        : id(id), name(name), food(food), totalCalories(totalCalories) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Food: " << food << ", Total Calories: " << totalCalories << endl;
    }
};

#endif // !MEAL_H
