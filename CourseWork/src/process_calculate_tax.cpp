#include "process_calculate_tax.h"
double processCalculateTax(const Property& prop) {
    return prop.area * prop.ratio * (prop.type == Residential ? RATE_RES : RATE_NON_RES);
}