#include "Employee.h"

// Ham kiem tra ngay vao lam hop le
bool isValidDate(const string& date) {
    // Gia su dinh dang ngay la YYYY-MM-DD
    struct tm tm;
    return strptime(date.c_str(), "%Y-%m-%d", &tm);
}

// Ham kiem tra so dien thoai hop le
bool isValidPhoneNumber(const string& phoneNumber) {
    return phoneNumber.length() == 10 && phoneNumber[0] == '0';
}

Employee::Employee(const string& id, const string& name, const string& startDate, const string& phoneNumber, double basicSalary) {
    if (isValidDate(startDate)) {
        this->startDate = startDate;
    }
    else {
        throw invalid_argument("Ngay vao lam khong hop le.");
    }

    if (isValidPhoneNumber(phoneNumber)) {
        this->phoneNumber = phoneNumber;
    }
    else {
        throw invalid_argument("So dien thoai khong hop le.");
    }

    if (basicSalary < 0) {
        throw invalid_argument("Luong can ban khong hop le.");
    }

    this->id = id;
    this->name = name;
    this->basicSalary = basicSalary;
}

// Getters
string Employee::getId() const { return id; }
string Employee::getName() const { return name; }
string Employee::getStartDate() const { return startDate; }
string Employee::getPhoneNumber() const { return phoneNumber; }
double Employee::getBasicSalary() const { return basicSalary; }

// Setters
void Employee::setName(const string& name) { this->name = name; }
void Employee::setPhoneNumber(const string& phoneNumber) {
    if (isValidPhoneNumber(phoneNumber)) {
        this->phoneNumber = phoneNumber;
    }
    else {
        throw invalid_argument("So dien thoai khong hop le.");
    }
}
void Employee::setBasicSalary(double basicSalary) {
    if (basicSalary < 0) {
        throw invalid_argument("Luong can ban khong hop le.");
    }
    this->basicSalary = basicSalary;
}

void Employee::display() const {
    cout << setw(10) << id << setw(20) << name << setw(15) << startDate << setw(15) << phoneNumber << setw(15) << basicSalary;
}

FullTimeEmployee::FullTimeEmployee(const string& id, const string& name, const string& startDate, const string& phoneNumber, double basicSalary, double salaryCoefficient, int experienceYears)
    : Employee(id, name, startDate, phoneNumber, basicSalary) {
    if (salaryCoefficient < 1.65 || salaryCoefficient > 8.00) {
        throw invalid_argument("He so luong khong hop le.");
    }
    if (experienceYears < 0) {
        throw invalid_argument("So nam kinh nghiem khong hop le.");
    }

    this->salaryCoefficient = salaryCoefficient;
    this->experienceYears = experienceYears;
}

double FullTimeEmployee::calculateSalary() const {
    double salary = basicSalary * salaryCoefficient;
    salary += (experienceYears * 0.05 * salary);
    return salary;
}

void FullTimeEmployee::display() const {
    Employee::display();
    cout << setw(15) << salaryCoefficient << setw(15) << experienceYears << setw(15) << calculateSalary() << endl;
}

PartTimeEmployee::PartTimeEmployee(const string& id, const string& name, const string& startDate, const string& phoneNumber, double basicSalary, int hoursPerWeek, double hourlyRate)
    : Employee(id, name, startDate, phoneNumber, basicSalary) {
    if (hoursPerWeek < 0) {
        throw invalid_argument("So gio lam viec khong hop le.");
    }
    if (hourlyRate < 0) {
        throw invalid_argument("Muc luong moi gio khong hop le.");
    }

    this->hoursPerWeek = hoursPerWeek;
    this->hourlyRate = hourlyRate;
}

double PartTimeEmployee::calculateSalary() const {
    double productSalary = hoursPerWeek * hourlyRate;
    if (hoursPerWeek > 40) {
        productSalary += (hoursPerWeek - 40) * hourlyRate * 0.5;
    }
    double salary = 0.3 * basicSalary + productSalary;
    return salary;
}

void PartTimeEmployee::display() const {
    Employee::display();
    cout << setw(15) << hoursPerWeek << setw(15) << hourlyRate << setw(15) << calculateSalary() << endl;
}

void PartTimeEmployee::setHoursPerWeek(int hours) {
    if (hours < 0) {
        throw invalid_argument("So gio lam viec khong hop le.");
    }
    this->hoursPerWeek = hours;
}
