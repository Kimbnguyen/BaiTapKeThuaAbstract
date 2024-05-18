#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include <vector>
#include <algorithm>

class EmployeeManager {
private:
    vector<Employee*> employees;

public:
    ~EmployeeManager();

    void addEmployee(Employee* emp);

    void addSampleEmployees();

    void displayAllEmployees() const;

    double calculateTotalSalary() const;

    int countEmployeesByYear(int year) const;

    void updateHoursWorked(const string& id, int hours);

    void sortEmployeesByStartDate();
};

#endif
