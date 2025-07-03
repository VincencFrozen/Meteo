#include "anemometer.hpp"

// TODO: Any kind of factory?

namespace Anemometer {

windSpeedKmh_t AnemometerGpio::getWindSpeed(void) const
{
    return this->windSpeed_kmh;
}

void AnemometerGpio::triggerFromGpio(void)
{
    // Todo. Correct computation

    this->windSpeed_kmh += 1;
}

} // namespace Anemometer