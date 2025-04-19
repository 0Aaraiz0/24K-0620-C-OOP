#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(const string& trackingNumber, double weight);
    virtual ~Shipment() {}

    virtual double estimateDeliveryTime() const = 0;
    virtual void showDetails() const = 0;
};

#endif 
