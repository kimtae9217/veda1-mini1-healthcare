#ifndef EXERCISE_H
#define EXERCISE_H 

#include <string>
#include <vector>
#include <map>

using namespace std;

class Exercise {
public:
    string type; // � ����
    int duration; // � �ð�

    // Exercise ��ü�� �����ϴ� ������ �Լ�
    Exercise(const string& type, int duration)
        : type(type), duration(duration) {}

    void display() const; // � ��� ������ ����ϴ� ��� �Լ�
};

// � ��ϵ��� �����ϴ� ExerciseManager Ŭ����
class ExerciseManager {
private:
    vector<Exercise> exercises; //  ��� � ����� �����ϴ� ����
    map<string, vector<Exercise>> exercisesByType; // � �������� � ����� �����ϴ� �� �����̳�

public:
    void loadFromCSV(const string& filename); // � ��� ������ �ҷ�����
    void saveToCSV(const string& filename); // � ��� ������ ����

    void addExercise(const Exercise& exercise); // � ��� �߰�
    void modifyExercise(int index, const Exercise& newExercise); // � ��� ����
    void deleteExercise(int index); // � ��� ����

    void displayExercises() const; // � ��� ���
    const vector<Exercise>& getExercisesByType(const string& type) const; // Ư�� � ������ �ش��ϴ� � ��ϵ��� ��ȯ�ϴ� ��� �Լ�
};

#endif 