#include "Taxpayer.h"
#include <stdexcept>

const int MAX_SIZE = 12;

Taxpayer::Taxpayer(const std::string& inn, int year)
    : taxableIncome(0), nontaxableIncome(0), totalTax(0), totalIncome(0), taxRate(0.13) {
    validateINN(inn);
    this->inn = inn;
    validateYear(year);
    this->year = year;
}

Taxpayer::Taxpayer(const std::string& inn, int year, double taxableIncome, double nontaxableIncome)
    : taxableIncome(taxableIncome), nontaxableIncome(nontaxableIncome), totalTax(0), totalIncome(0), taxRate(0.13) {
    validateINN(inn);
    this->inn = inn;
    validateYear(year);
    this->year = year;

    totalTax = this->taxableIncome * taxRate;
    totalIncome = this->taxableIncome + this->nontaxableIncome;
}

Taxpayer::~Taxpayer() {}

Taxpayer::Taxpayer(const Taxpayer& other)
    : inn(other.inn), year(other.year),
    taxableIncome(other.taxableIncome), nontaxableIncome(other.nontaxableIncome),
    totalTax(other.totalTax), totalIncome(other.totalIncome), taxRate(other.taxRate) {
}

Taxpayer& Taxpayer::operator=(const Taxpayer& other) {
    if (this == &other) return *this;

    inn = other.inn;
    year = other.year;
    taxableIncome = other.taxableIncome;
    nontaxableIncome = other.nontaxableIncome;
    totalTax = other.totalTax;
    totalIncome = other.totalIncome;

    return *this;
}

void Taxpayer::validateINN(const std::string& inn) const {
    if (inn.empty()) {
        throw std::invalid_argument("��� �� ����� ���� ������.");
    }
    if (inn.length() != MAX_SIZE) {
        throw std::invalid_argument("��� ������ ��������� ����� 12 ��������.");
    }
    for (char c : inn) {
        if (!isdigit(c)) {
            throw std::invalid_argument("��� ������ ��������� ������ �����.");
        }
    }
}

void Taxpayer::validateYear(int year) const {
    if (year < 1900 || year > 2100) {
        throw std::invalid_argument("��� ������ ���� � ��������� 1900�2100.");
    }
}

void Taxpayer::validateIncome(double income) const {
    if (income < 0) {
        throw std::invalid_argument("����� �� ����� ���� �������������.");
    }
}

void Taxpayer::addIncome(double amount, bool isTaxable) {
    validateIncome(amount);
    if (isTaxable) {
        taxableIncome += amount;
        totalTax = taxableIncome * taxRate;
    }
    else {
        nontaxableIncome += amount;
    }
    totalIncome = taxableIncome + nontaxableIncome;
}

void Taxpayer::addIncome(double netIncomeAfterTax) {
    validateIncome(netIncomeAfterTax);
    double grossIncome = netIncomeAfterTax / (1 - taxRate);
    taxableIncome += grossIncome;
    totalTax = taxableIncome * taxRate;
    totalIncome = taxableIncome + nontaxableIncome;
}

void Taxpayer::printInfo() const {
    std::cout << "���: " << inn << "\n"
        << "���: " << year << "\n"
        << "���������������� �����: " << taxableIncome << "\n"
        << "������������������ �����: " << nontaxableIncome << "\n"
        << "�������� �����: " << totalTax << "\n"
        << "����� �����: " << totalIncome << "\n"
        << "������ ������: " << taxRate * 100 << "%\n";
}

// ���������� ������ ������ ������, ������� �� �������� ��������
void Taxpayer::printTax() const {
    std::cout << "�����, ������� �� �������� ��������: " << totalTax << std::endl;
}

const std::string& Taxpayer::getINN() const { return inn; }
int Taxpayer::getYear() const { return year; }
double Taxpayer::getTaxableIncome() const { return taxableIncome; }
double Taxpayer::getNontaxableIncome() const { return nontaxableIncome; }
double Taxpayer::getTotalTax() const { return totalTax; }
double Taxpayer::getTotalIncome() const { return totalIncome; }
double Taxpayer::getTaxRate() const { return taxRate; }

std::istream& operator>>(std::istream& in, Taxpayer& taxpayer) {
    double netIncomeAfterTax;
    std::cout << "������� ����� ����� ������ ������: ";
    in >> netIncomeAfterTax;
    taxpayer.addIncome(netIncomeAfterTax);
    return in;
}



