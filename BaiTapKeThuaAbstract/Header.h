#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <ctime>
#include <iomanip>

using namespace std;

// Ham kiem tra ngay vao lam hop le
bool isValidDate(const string& date);

// Ham kiem tra so dien thoai hop le
bool isValidPhoneNumber(const string& phoneNumber);

class Employee {
protected:
    string id;
    string name;
    string startDate;
    string phoneNumber;
    double basicSalary;

public:
    Employee(const string& id, const string& name, const string& startDate, const string& phoneNumber, double basicSalary);

    virtual double calculateSalary() const = 0; // Lop tru tuong

    // Getters
    string getId() const;
    string getName() const;
    string getStartDate() const;
    string getPhoneNumber() const;
    double getBasicSalary() const;

    // Setters
    void setName(const string& name);
    void setPhoneNumber(const string& phoneNumber);
    void setBasicSalary(double basicSalary);

    virtual void display() const;
};

class FullTimeEmployee : public Employee {
private:
    double salaryCoefficient;
    int experienceYears;

public:
    FullTimeEmployee(const string& id, const string& name, const string& startDate, const string& phoneNumber, double basicSalary, double salaryCoefficient, int experienceYears);

    double calculateSalary() const override;

    void display() const override;
};

class PartTimeEmployee : public Employee {
private:
    int hoursPerWeek;
    double hourlyRate;

public:
    PartTimeEmployee(const string& id, const string& name, const string& startDate, const string& phoneNumber, double basicSalary, int hoursPerWeek, double hourlyRate);

    double calculateSalary() const override;

    void display() const override;

    // Setters
    void setHoursPerWeek(int hours);
};

#endif
