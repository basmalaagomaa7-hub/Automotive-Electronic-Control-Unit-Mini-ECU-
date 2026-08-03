#ifndef BATTERY_MONITOR_INTERFACE_H
#define BATTERY_MONITOR_INTERFACE_H

#include <stdint.h>

#define BatteryMonitor_BatteryNormal    0U
#define BatteryMonitor_BatteryLow       1U

void BatteryMonitor_Init(void);
void BatteryMonitor_Run(uint16_t BatteryAdcValue);
uint8_t BatteryMonitor_GetState(void);

#endif
