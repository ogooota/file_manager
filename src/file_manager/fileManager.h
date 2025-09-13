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
void quit();

void auto_folder(std::vector<std::string>& file_types);
std::vector<std::filesystem::path> list_folders(std::vector<std::string>& file_types);
bool create_folders(std::vector<std::filesystem::path>& folders_to_create);
bool dir_exists(std::filesystem::path& dir);

bool execute(std::vector<std::string>& file_types);

bool move_files();
bool find_files();

bool exclude();
bool include();
bool enable();
bool disable();


// lazy people code;
void erase_first_and_split(std::vector<std::string>* arr);