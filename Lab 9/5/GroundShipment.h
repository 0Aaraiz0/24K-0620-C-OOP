#ifndef GROUNDSHIPMENT_H
#define GROUNDSHIPMENT_H
using namespace std;

#include "Shipment.h"

class GroundShipment : public Shipment {
public:
    GroundShipment(const string& trackingNumber, double weight);

    double estimateDeliveryTime() const override;
    void showDetails() const override;
};

#endif 
