#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

// cores
extern std::vector<std::string> colors;

std::string rainbowText(std::string text);
std::string rainbowText(std::string* text, const int start, const int end);
std::string rainbowText(std::string* text, const std::string& sub);

std::string progressBar(const size_t& length, int& current);
