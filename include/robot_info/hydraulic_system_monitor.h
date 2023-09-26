#pragma once
#include <string>
#include <vector>

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

  std::vector<std::pair<std::string, std::string>> getHydraulicMonitorMagnitudes();
};