#ifndef EXERCISE_H
#define EXERCISE_H 

#include <string>
#include <vector>
#include <map>

using namespace std;

class Exercise {
public:
    string type; // 운동 유형
    int duration; // 운동 시간

    // Exercise 객체를 생성하는 생성자 함수
    Exercise(const string& type, int duration)
        : type(type), duration(duration) {}

    void display() const; // 운동 기록 정보를 출력하는 멤버 함수
};

// 운동 기록들을 관리하는 ExerciseManager 클래스
class ExerciseManager {
private:
    vector<Exercise> exercises; //  모든 운동 기록을 저장하는 벡터
    map<string, vector<Exercise>> exercisesByType; // 운동 종류별로 운동 기록을 저장하는 맵 컨테이너

public:
    void loadFromCSV(const string& filename); // 운동 기록 데이터 불러오기
    void saveToCSV(const string& filename); // 운동 기록 데이터 저장

    void addExercise(const Exercise& exercise); // 운동 기록 추가
    void modifyExercise(int index, const Exercise& newExercise); // 운동 기록 수정
    void deleteExercise(int index); // 운동 기록 삭제

    void displayExercises() const; // 운동 기록 출력
    const vector<Exercise>& getExercisesByType(const string& type) const; // 특정 운동 종류에 해당하는 운동 기록들을 반환하는 멤버 함수
};

#endif 