#include "cash.h"

Cash::Cash() 
: _denomination(0)
{}

Cash::Cash(const double& denomination)
: _denomination(denomination)
{}

Cash::~Cash()
{}

bool Cash::operator==(const Cash &other) const
{ 
    return _denomination == other._denomination;
}

void Cash::setDenomination(const double& denomination) {
    _denomination = denomination;
}

double Cash::getDenomination() const {
    return _denomination;
}



