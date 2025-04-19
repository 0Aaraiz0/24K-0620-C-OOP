#ifndef AIRFREIGHT_H
#define AIRFREIGHT_H

#include "Shipment.h"

using namespace std;

class AirFreight : public Shipment {
public:
    AirFreight(const string& trackingNumber, double weight);

    double estimateDeliveryTime() const override;
    void showDetails() const override;
};

#endif 
