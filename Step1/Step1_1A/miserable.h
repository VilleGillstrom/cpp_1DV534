#pragma once

void displayTemperature(const std::vector<double>& temperatures);

void displayTemperatureMinMax(const std::vector<double>& temperatures);

void displayAvgTemperature(const std::vector<double>& temperatures) ;

std::vector<double> readTemperaturesFromFile(const std::string &filename);
