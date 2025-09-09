#include <filesystem>
#include <cstring>
#include <iostream>
#include "rainbowText.h"
#include "fileManager.h"


// commands:
// set dir [directory to be created] or [directory that already exists];
// exclude ["file_name.file_extension" to be excluded from going into the directory]; 
// include [directory] or [all](will include all files inside a directory) or [single_file.file_extension];
// enable [feature (rainbowText, for example)];
// disable [feature (rainbowText, for example)];
// execute (for executing the action this program does: organizing shit in folders)
// auto [file_extensions to get folders created, separated by comma]

void set_directory(const std::string& dir_name) {
    std::filesystem::path dir = std::filesystem::current_path().string() + "/" + dir_name; 
    if(!std::filesystem::exists(dir) || !std::filesystem::is_directory(dir)) {
        if(std::filesystem::create_directory(dir)) std::cout << "Directory created: " << dir_name << "\n"; 
        else {
            std::cout << "an error occurred while creating your folder." << "\n";
        }
    }
    else {
        std::cout << "Directory set: " << std::filesystem::current_path().string() + "/" + rainbowText(dir_name) << "\n";
    }
}
void auto_folder(std::vector<std::string>& file_types) {
    // complete function for creating folders with the file type names
    // and moving the files into them
    for(std::string s : file_types) {
        std::cout << s << "\n"; 
    }
}
void quit() {
    std::exit(0);
}
bool exclude() {
    return false;
}

bool include() {
    return false;
}

bool enable() {
    return false;
}

bool disable() {
    return false;
}

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
