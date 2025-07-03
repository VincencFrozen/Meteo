#include <stdint.h>
#include <iostream>

#include "anemometer.hpp"
#include "windlogic.hpp"

namespace WindLogic {

void WindLogic::process(void)
{
    // Todo: Add Histersis
    triggerWindState((anemometer.getWindSpeed() > windLevelTrershold_kmh) ? WindSeverity::CRITICAL : WindSeverity::OK);
}

void WindLogicUart::triggerWindState(WindSeverity windSeverity)
{
    if(windSeverity == WindSeverity::OK)
    {
        std::cout << "OK" << std::endl;
    } else
    {
        std::cout << "CRITICAL" << std::endl;
    }
}

} // namespace WindLogic