#include "Taxpayer.h"
#include "PropertyTaxpayer.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");
    int recordCount;

    std::cout << "������� ���������� �������: ";
    std::cin >> recordCount;

    std::vector<Taxpayer*> taxpayers;

    for (int i = 0; i < recordCount; ++i) {
        std::string inn;
        int year;
        double taxableIncome, nontaxableIncome, propertyValue;

        std::cout << "\n������ #" << i + 1 << ":\n";

        std::cout << "������� ��� (12 ����): ";
        std::cin >> inn;

        std::cout << "������� ��� �������: ";
        std::cin >> year;

        std::cout << "������� ���������������� ����� (0, ���� �����������): ";
        std::cin >> taxableIncome;

        std::cout << "������� ������������������ ����� (0, ���� �����������): ";
        std::cin >> nontaxableIncome;

        std::cout << "������� ��������� ����� (0, ���� �����������): ";
        std::cin >> propertyValue;

        try {
            Taxpayer* taxpayer = nullptr;
            if (propertyValue > 0) {
                taxpayer = new PropertyTaxpayer(inn, year, propertyValue, taxableIncome, nontaxableIncome);
            }
            else {
                taxpayer = new Taxpayer(inn, year, taxableIncome, nontaxableIncome);
            }

            char addMore = 'y';
            while (addMore == 'y' || addMore == 'Y') {
                std::cin >> *taxpayer;
                std::cout << "�������� ��� �����? (y/n): ";
                std::cin >> addMore;
            }

            taxpayers.push_back(taxpayer);

        }
        catch (const std::exception& e) {
            std::cerr << "������: " << e.what() << "\n";
        }
    }

    double totalTaxSum = 0.0;
    for (const auto* taxpayer : taxpayers) {
        totalTaxSum += taxpayer->getTotalTax();
    }

    for (size_t i = 0; i < taxpayers.size(); ++i) {
        std::cout << "\n--- ���������� � ����������������� #" << i + 1 << " ---\n";
        taxpayers[i]->printInfo();
        taxpayers[i]->printTax();  // ������� �����, ������� �� �������� ��������
    }

    std::cout << "\n����� ����� �� ���� ������������������: " << totalTaxSum << "\n";

    for (auto* taxpayer : taxpayers) {
        delete taxpayer;
    }

    return 0;
}






