#pragma once
#include <vector>
#include <string> 
#include <filesystem>

std::vector<std::string> split(const char& del, const std::string& text);
std::vector<std::filesystem::path> get_current_path_files(std::filesystem::path& current_path);
void set_directory(const std::string& path);
void quit();
void auto_folder(std::vector<std::string>& file_types);
bool exclude();
bool include();
bool enable();
bool disable();

