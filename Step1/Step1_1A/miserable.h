#pragma once

void displayTemperature(const std::vector<double>& temperatures);

void displayTemperatureMinMax(const std::vector<double>& temperatures);

void displayAvgTemperature(const std::vector<double>& temperatures) ;

bool readTemperaturesFromFile(const std::string &filename, std::vector<double>& temperatures);
