/*
:������_����_���簢��: ������ ���� ����, å�� �߽��� ���� ��� ����
   - 6���� Ŭ������ �̿��ؼ� �� ����, ��ǰ ����, ��ǰ ���� Ŭ������ ����
   - Ŭ�������� ������ �����͸� �����Ͽ� å�� �߽��� ���� ����� ����
   - Ŭ���� ���� �޼ҵ� ����� �̿��ؼ� �����͸� ����
:������_����_���簢��: ���� ���� ���� ���� �� ����
   - CSV(Comma Separated Value)�� �̿��ؼ� ������ ����
   - Ŭ�������� ������ �����͸� �����Ͽ� å�� �߽��� ���� ����� ����
:������_����_���簢��: STL ����Ͽ� �ڷ� ���� �� �˻� ����
   - STL�� Vector�� Map ���� Ŭ������ �̿��ؼ� �����͸� ����
   - STL�� �˻� ���� �˰����� ���
:������_����_���簢��: CLI ���� �� ����
   - �ܼ��� �̿��� �Է°� ���
   - �޴� ȭ���� ����
����� ȭ��
*** ���ι� ���α׷� ***
1. ���θ�
2. �� ����
3. ��ǰ ����
� �޴��� �����Ͻðڽ��ϱ�? 2
*** �� ���� ***
1. �Է�
2. ����
3. ����
0. ���� �޴��� ���ư���
� �׸��� �����Ͻðڽ��ϱ�?
*/

#include <iostream>
#include "customer_manage.h"
#include "meal_manage.h"

using namespace std;

void menu(mealmanage& mealmanager) {
    int choice;
    do {
        cout << "\n*** �Ļ� ���� ***" << endl;
        cout << "1. �Է�" << endl;
        cout << "2. ����" << endl;
        cout << "3. ����" << endl;
        cout << "4. ǥ��" << endl;
        cout << "0. ���� �޴��� ���ư���" << endl;
        cout << "����: ";
        cin >> choice;

        if (choice == 1) {
            int id, totalCalories;
            string name, food;
            cout << "ID: ";
            cin >> id;
            cout << "�̸�: ";
            cin >> name;
            cout << "����: ";
            cin >> food;
            cout << "�հ� Į�θ�: ";
            cin >> totalCalories;
            mealmanager.addMeal(meal(id, name, food, totalCalories));
        }
        else if (choice == 2) {
            int id, totalCalories;
            string name, food;
            cout << "������ �Ļ��� ID: ";
            cin >> id;
            cout << "�� �̸�: ";
            cin >> name;
            cout << "�� ����: ";
            cin >> food;
            cout << "�� �հ� Į�θ�: ";
            cin >> totalCalories;
            mealmanager.modifyMeal(id, meal(id, name, food, totalCalories));
        }
        else if (choice == 3) {
            int id;
            cout << "������ �Ļ��� ID: ";
            cin >> id;
            mealmanager.deleteMeal(id);
        }
        else if (choice == 4) {
            mealmanager.displayMeals();
        }
        else if (choice != 0) {
            cout << "�߸��� �����Դϴ�." << endl;
        }
    } while (choice != 0);
}

int main() {

    int main_num;
    int meal_num;

    string meal_filename = "meal.csv";

    mealmanage mealmanager;
    mealmanager.loadFromCSV(meal_filename);

    cout << "---VEDA �ｺ�ɾ ���� ���� ȯ���մϴ�.---" << endl;
    cout << "1. ������" << endl;
    cout << "2. �����" << endl;
    cout << "3. �Ĵܰ���" << endl;
    cin >> main_num;

    if (main_num == 1) {
        string filename = "customers.csv";
        vector<Customer> customers = readCustomersFromCSV(filename);

        cout << "CSV ���Ͽ��� ���� �� ����:" << endl;
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