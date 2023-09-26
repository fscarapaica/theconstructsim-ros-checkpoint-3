#pragma once
#include <map>
#include <string>

class HydraulicSystemMonitor {
private:
  std::string hydraulic_oil_temperature = "";
  std::string hydraulic_oil_tank_fill_level = "";
  std::string hydraulic_oil_pressure = "";

public:
  HydraulicSystemMonitor(){};
  HydraulicSystemMonitor(std::string hydraulic_oil_temperature,
                         std::string hydraulic_oil_tank_fill_level,
                         std::string hydraulic_oil_pressure);

  std::map<std::string, std::string> getHydraulicMonitorMagnitudes();
};