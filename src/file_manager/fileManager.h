#pragma once
#include <vector>
#include <string> 
#include <filesystem>

namespace globals {
	extern std::filesystem::path workspace;
};

std::vector<std::string> split(const char& del, const std::string& text);
std::vector<std::filesystem::path> get_current_path_files(std::filesystem::path& current_path);

bool set_directory(const std::string& path);
bool dir_exists(std::filesystem::path& dir);
void quit();
void auto_folder(std::vector<std::string>& file_types);
bool exclude();
bool include();
bool enable();
bool disable();

