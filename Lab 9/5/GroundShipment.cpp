#include "GroundShipment.h"
#include <iostream>
using namespace std;

GroundShipment::GroundShipment(const string& trackingNumber, double weight)
    : Shipment(trackingNumber, weight) {}

double GroundShipment::estimateDeliveryTime() const {
    return weight * 1.2 + 3.0; 
}

void GroundShipment::showDetails() const {
    std::cout << "[Ground Shipment]\nTracking: " << trackingNumber
              << "\nWeight: " << weight << "kg"
              << "\nEstimated Delivery Time: " << estimateDeliveryTime() << " hrs\n\n";
}
