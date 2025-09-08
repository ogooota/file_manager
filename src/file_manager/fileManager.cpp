#include <filesystem>
#include <cstring>
#include <iostream>
#include "rainbowText.hpp"

// :DDDDDD
std::vector<std::string> split(const char& del, const std::string& text) {
    std::vector<std::string> splitted_text;
    size_t found = text.find(del);
    size_t start = 0;
    while (found != std::string::npos) {
        splitted_text.push_back(text.substr(start, found - start));
        start = found + 1;
        found = text.find(del, start);
    }
    splitted_text.push_back(text.substr(start));
    return splitted_text;
}

std::vector<std::filesystem::path> get_current_path_files(std::filesystem::path& current_path) {
    std::vector<std::filesystem::path> files;
    try {
        for (auto const& path : std::filesystem::directory_iterator(current_path)) {
            if (!std::filesystem::is_directory(path)) {
                files.push_back(path);
            }
        }
        return files;
    }
    catch (std::filesystem::filesystem_error const& e) {
        std::cout << "error: " << e.what() << "\n";
        // deve ter que fazer outra coisa, se jogar exceção não pode retornar a lista
        return files;
    }
}
int main() {
    std::filesystem::path current_path = std::filesystem::current_path();
    std::vector<std::filesystem::path> files = get_current_path_files(current_path);
    std::vector<std::string> file_names;
    for (int i = 0;i < files.size();i++) {
        std::string file_str = files[i].string();
        std::vector<std::string> file_parts = split('/', file_str);
        for (std::string& e : file_parts) {
            if (e.find('.') != std::string::npos) file_names.push_back(e); 
        }
    }
    for (std::string& e : file_names) {
        std::cout << rainbowText(e) << "\n";
    }
    return 0;
}