#include "Shipment.h"
using namespace std;

Shipment::Shipment(const string& trackingNumber, double weight)
    : trackingNumber(trackingNumber), weight(weight) {}
