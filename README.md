# Meteo

## Peripherals & Power supply

- Anemometer
    - Output is a pin with frequency (2.4km/h = 1Hz)
    - Needs GPIO Interrupt

- Communication
    - UART
        - Logging

- Power supply
    - USB 5V

## Logic

- Does the wind exceeds M (45km/h) for the first time
    - YES - send a command into the UART "Wind: CRITICAL"
    - NO  - send a command into the UART "Wind: OK
- Set the histeresis for L (30 min). Curtains will stay closed even though the wind isn't critical anymore.
- Send the wind info every N (5 min)
- FW update over On-Board debugger

## HW

- DW1001 (https://www.qorvo.com/products/p/DWM1001-DEV)

## Testing

- Manual for now

## Logical HW Scheme

```plantuml
@startuml
[DWM1001DEV] as MCU
[Anemometer] as Wind
MCU -- Wind : GPIO Interrupt

@enduml
```

## Class diagrams

```plantuml
@startuml
interface Anemometer {
    +getWindSpeed()
    +setCriticalWindSpeed()
}
class AnemometerGpio {
    -uint32_t speedKmh
    #uint32_t kmhPerTick
    #WindLogic *windLogic
    +triggerFromGpio()
    +AnemometerGpio()
}
class AnemometerGPIOWH1080
class AnemometerMock {
    -uint32_t speedKmh
}
class AnemometerGPIOMock

Anemometer <|-- AnemometerGpio
Anemometer <|-- AnemometerMock
AnemometerGpio <|-- AnemometerGPIOWH1080
AnemometerGpio <|-- AnemometerGPIOMock

enum WindState {
    OK
    CRITICAL
}

abstract class WindLogic {
    #notifyWindChange(uint32_t windSpeed_kmh)
    +getWindState()
    +process()
    -uint32_t windLevelTresholdKmh
    -uint32_t histersis_s
    -void (* triggerWind)(WindState windState)
}

@enduml
```

## Others

Links:
- https://github.com/embeddedcontainers/examples-zephyr-helloworld

