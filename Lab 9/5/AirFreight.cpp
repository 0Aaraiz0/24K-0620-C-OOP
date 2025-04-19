#include "AirFreight.h"
#include <iostream>
using namespace std;

AirFreight::AirFreight(const string& trackingNumber, double weight)
    : Shipment(trackingNumber, weight) {}

double AirFreight::estimateDeliveryTime() const {
    return weight * 0.5 + 1.0; 
}

void AirFreight::showDetails() const {
    std::cout << "[Air Freight]\nTracking: " << trackingNumber
              << "\nWeight: " << weight << "kg"
              << "\nEstimated Delivery Time: " << estimateDeliveryTime() << " hrs\n\n";
}
