#include "EmployeeManager.h"

EmployeeManager::~EmployeeManager() {
    for (Employee* emp : employees) {
        delete emp;
    }
}

void EmployeeManager::addEmployee(Employee* emp) {
    for (Employee* e : employees) {
        if (e->getId() == emp->getId()) {
            throw invalid_argument("Nhan vien voi ma nay da ton tai.");
        }
    }
    employees.push_back(emp);
}

void EmployeeManager::addSampleEmployees() {
    try {
        addEmployee(new FullTimeEmployee("FT001", "Nguyen Van A", "2020-01-15", "0123456789", 1800000, 3.0, 5));
        addEmployee(new PartTimeEmployee("PT001", "Tran Thi B", "2021-03-20", "0987654321", 1000000, 45, 50000));
        addEmployee(new FullTimeEmployee("FT002", "Le Van C", "2019-02-10", "0909090909", 2000000, 2.5, 3));
        addEmployee(new PartTimeEmployee("PT002", "Hoang Thi D", "2022-04-05", "0912345678", 1200000, 30, 40000));
        addEmployee(new FullTimeEmployee("FT003", "Pham Van E", "2018-11-22", "0923456789", 2200000, 4.0, 7));
    }
    catch (const invalid_argument& e) {
        cout << "Loi: " << e.what() << endl;
    }
}

void EmployeeManager::displayAllEmployees() const {
    cout << left << setw(10) << "Ma" << setw(20) << "Ho ten" << setw(15) << "Ngay vao
