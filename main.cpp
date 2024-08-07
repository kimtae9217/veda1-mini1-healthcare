/*
:검은색_작은_정사각형: 데이터 관리 구조, 책임 중심의 설계 기법 익힘
   - 6개의 클래스를 이용해서 고객 관리, 상품 관리, 제품 관리 클래스를 제작
   - 클래스별로 각각의 데이터를 관리하여 책임 중심의 설계 기법을 적용
   - 클래스 간의 메소드 통신을 이용해서 데이터를 전달
:검은색_작은_정사각형: 파일 저장 포맷 설계 및 구현
   - CSV(Comma Separated Value)를 이용해서 파일을 저장
   - 클래스별로 각각의 데이터를 저장하여 책임 중심의 설계 기법을 적용
:검은색_작은_정사각형: STL 사용하여 자료 관리 및 검색 구현
   - STL의 Vector나 Map 등의 클래스를 이용해서 데이터를 저장
   - STL의 검색 등의 알고리즘을 사용
:검은색_작은_정사각형: CLI 설계 및 구현
   - 콘솔을 이용한 입력과 출력
   - 메뉴 화면의 구현
입출력 화면
*** 쇼핑물 프로그램 ***
1. 쇼핑몰
2. 고객 관리
3. 제품 관리
어떤 메뉴를 선택하시겠습니까? 2
*** 고객 관리 ***
1. 입력
2. 수정
3. 삭제
0. 메인 메뉴로 돌아가기
어떤 항목을 선택하시겠습니까?
*/

#include <iostream>
#include "customer_manage.h"
#include "meal_manage.h"

using namespace std;

void menu(mealmanage& mealmanager) {
    int choice;
    do {
        cout << "\n*** 식사 관리 ***" << endl;
        cout << "1. 입력" << endl;
        cout << "2. 수정" << endl;
        cout << "3. 삭제" << endl;
        cout << "4. 표시" << endl;
        cout << "0. 메인 메뉴로 돌아가기" << endl;
        cout << "선택: ";
        cin >> choice;

        if (choice == 1) {
            int id, totalCalories;
            string name, food;
            cout << "ID: ";
            cin >> id;
            cout << "이름: ";
            cin >> name;
            cout << "음식: ";
            cin >> food;
            cout << "합계 칼로리: ";
            cin >> totalCalories;
            mealmanager.addMeal(meal(id, name, food, totalCalories));
        }
        else if (choice == 2) {
            int id, totalCalories;
            string name, food;
            cout << "수정할 식사의 ID: ";
            cin >> id;
            cout << "새 이름: ";
            cin >> name;
            cout << "새 음식: ";
            cin >> food;
            cout << "새 합계 칼로리: ";
            cin >> totalCalories;
            mealmanager.modifyMeal(id, meal(id, name, food, totalCalories));
        }
        else if (choice == 3) {
            int id;
            cout << "삭제할 식사의 ID: ";
            cin >> id;
            mealmanager.deleteMeal(id);
        }
        else if (choice == 4) {
            mealmanager.displayMeals();
        }
        else if (choice != 0) {
            cout << "잘못된 선택입니다." << endl;
        }
    } while (choice != 0);
}

int main() {

    int main_num;
    int meal_num;

    string meal_filename = "meal.csv";

    mealmanage mealmanager;
    mealmanager.loadFromCSV(meal_filename);

    cout << "---VEDA 헬스케어에 오신 것을 환영합니다.---" << endl;
    cout << "1. 고객관리" << endl;
    cout << "2. 운동관리" << endl;
    cout << "3. 식단관리" << endl;
    cin >> main_num;

    if (main_num == 1) {
        string filename = "customers.csv";
        vector<Customer> customers = readCustomersFromCSV(filename);

        cout << "CSV 파일에서 읽은 고객 정보:" << endl;
        for (const auto& customer : customers) {
            customer.display();
        }
    }

    else if (main_num == 3) {

        mealmanager.loadFromCSV(meal_filename);
        menu(mealmanager);
    }

    mealmanager.saveToCSV(meal_filename);

    return 0;
}