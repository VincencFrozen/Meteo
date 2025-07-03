#pragma once

#include <stdint.h>
#include "anemometer.hpp"

namespace WindLogic {

constexpr uint32_t DEFAULT_HISTERSIS_S = 30;
constexpr uint32_t DEFAULT_WIND_SPEED_KMH = 30;
constexpr uint32_t DEFAULT_WIND_LEVEL_THRESHOLD_KMH = 10;

enum class WindSeverity 
{
    OK,
    CRITICAL
};


class WindLogic
{
public:
    WindLogic(const Anemometer::IAnemometer & anemometer, Anemometer::windSpeedKmh_t windLevelTrershold_kmh = DEFAULT_WIND_LEVEL_THRESHOLD_KMH
        , uint32_t histersis_s = DEFAULT_HISTERSIS_S)
    : anemometer(anemometer), windLevelTrershold_kmh(windLevelTrershold_kmh), histersis_s(histersis_s) {};

    void process(void);

private:
    const Anemometer::IAnemometer & anemometer;
    Anemometer::windSpeedKmh_t windLevelTrershold_kmh;
    uint32_t histersis_s;

    virtual void triggerWindState(WindSeverity windSeverity) = 0;
};

class WindLogicUart : public WindLogic
{
public:
    using WindLogic::WindLogic;

private:
    void triggerWindState(WindSeverity windSeverity) override;
};


} // namespace WindLogic