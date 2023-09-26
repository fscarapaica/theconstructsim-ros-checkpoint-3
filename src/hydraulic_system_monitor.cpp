#include "robot_info/hydraulic_system_monitor.h"
#include <array>
#include <string>

HydraulicSystemMonitor::HydraulicSystemMonitor(
    std::string hydraulic_oil_temperature,
    std::string hydraulic_oil_tank_fill_level,
    std::string hydraulic_oil_pressure) {
  this->hydraulic_oil_temperature = hydraulic_oil_temperature;
  this->hydraulic_oil_tank_fill_level = hydraulic_oil_tank_fill_level;
  this->hydraulic_oil_pressure = hydraulic_oil_pressure;
}

std::vector<std::pair<std::string, std::string>> HydraulicSystemMonitor::getHydraulicMonitorMagnitudes() {
  return {{"hydraulic_oil_temperature", hydraulic_oil_temperature},
          {"hydraulic_oil_tank_fill_level", hydraulic_oil_tank_fill_level},
          {"hydraulic_oil_pressure", hydraulic_oil_pressure}};
}