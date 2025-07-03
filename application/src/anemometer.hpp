#pragma once

#include <stdint.h>

// TODO: Any kind of factory?

namespace Anemometer {

typedef float windSpeedKmh_t;

constexpr windSpeedKmh_t WH1080_KMHPERTICK  = 2.4;
constexpr windSpeedKmh_t DEFAULT_KMHPERTICK = 1;

class IAnemometer 
{
public:
    virtual windSpeedKmh_t getWindSpeed(void) const = 0;
};


class AnemometerGpio : public IAnemometer 
{
public:
    void triggerFromGpio(void);
    windSpeedKmh_t getWindSpeed(void) const override;

private:
    windSpeedKmh_t windSpeed_kmh;

protected:
    windSpeedKmh_t kmhPerTick;
    AnemometerGpio(windSpeedKmh_t kmhPerTick = DEFAULT_KMHPERTICK) : windSpeed_kmh(0.0), kmhPerTick(kmhPerTick) {};
};


class AnemometerGpioWH1080 : public AnemometerGpio
{
public:
    AnemometerGpioWH1080() : AnemometerGpio(WH1080_KMHPERTICK) {};
};

} // namespace Anemometer