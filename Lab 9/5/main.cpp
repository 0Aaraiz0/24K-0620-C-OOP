#include <iostream>
#include "AirFreight.h"
#include "GroundShipment.h"

using namespace std;

int main() {
    Shipment* s1 = new AirFreight("AIR123", 10.5);
    Shipment* s2 = new GroundShipment("GRND456", 15.2);
    Shipment* s3 = new AirFreight("AIR789", 7.8);
    Shipment* s4 = new GroundShipment("GRND999", 20.0);

    s1->showDetails();
    s2->showDetails();
    s3->showDetails();
    s4->showDetails();

    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 0;
}
