#ifndef TAXINTERFACE_H
#define TAXINTERFACE_H

class TaxInterface {
public:
    virtual void printTax() const = 0;  // ����� ����������� �������
    virtual ~TaxInterface() = default;
};

#endif // TAXINTERFACE_H




