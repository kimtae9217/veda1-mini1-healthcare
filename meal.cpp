#include "meal_manage.h"
#include <fstream>
#include <sstream>
#include <iostream>

void mealmanage::loadFromCSV(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "파일을 열 수 없습니다: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, food, totalCaloriesStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, food, ',');
        getline(ss, totalCaloriesStr, ',');

        if (!idStr.empty() && !name.empty() && !food.empty() && !totalCaloriesStr.empty()) {
            int id = stoi(idStr);
            int totalCalories = stoi(totalCaloriesStr);
            meals.emplace_back(id, name, food, totalCalories);
        }
    }

    file.close();
}

void mealmanage::saveToCSV(const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "파일을 열 수 없습니다: " << filename << endl;
        return;
    }

    for (const auto& meal : meals) {
        file << meal.id << "," << meal.name << "," << meal.food << "," << meal.totalCalories << endl;
    }

    file.close();
}

void mealmanage::addMeal(const meal& meal) {
    meals.push_back(meal);
}

void mealmanage::modifyMeal(int id, const meal& meal) {
    for (auto& m : meals) {
        if (m.id == id) {
            m.name = meal.name;
            m.food = meal.food;
            m.totalCalories = meal.totalCalories;
            return;
        }
    }
    cout << "ID에 해당하는 식사가 없습니다." << endl;
}

void mealmanage::deleteMeal(int id) {
    meals.erase(remove_if(meals.begin(), meals.end(), [id](const meal& m) { return m.id == id; }), meals.end());
}

void mealmanage::displayMeals() const {
    for (const auto& meal : meals) {
        meal.display();
    }
}
