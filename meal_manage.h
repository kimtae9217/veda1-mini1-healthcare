#ifndef MEAL_MANAGER_H
#define MEAL_MANAGER_H

#include <vector>
#include <string>
#include "meal.h"

using namespace std;

class mealmanage {
public:
    vector<meal> meals;

    void loadFromCSV(const string& filename);
    void saveToCSV(const string& filename);
    void addMeal(const meal& meal);
    void modifyMeal(int id, const meal& meal);
    void deleteMeal(int id);
    void displayMeals() const;
};

#endif // !MEAL_MANAGER_H
