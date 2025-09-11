#include <filesystem>
#include <cstring>
#include <iostream>
#include <fstream>
#include "rainbowText.h"
#include "fileManager.h"

std::filesystem::path globals::workspace;

// commands:
// set dir [directory to be created] or [directory that already exists];
// exclude ["file_name.file_extension" to be excluded from going into the directory]; 
// include [directory] or [all](will include all files inside a directory) or [single_file.file_extension];
// enable [feature (rainbowText, for example)];
// disable [feature (rainbowText, for example)];
// execute (for executing the action this program does: organizing shit in folders)
// auto [file_extensions to get folders created, separated by comma]

bool set_directory(const std::string& dir_name) {
    std::filesystem::path dir = std::filesystem::current_path().string() + "\\" + dir_name;
    if(!std::filesystem::exists(dir) || !std::filesystem::is_directory(dir)) {
        try {
            if (std::filesystem::create_directory(dir)) {
                std::cout << "Directory created: " << dir_name << "\n";
            }
        }
        catch (std::filesystem::filesystem_error& e) {
            std::cout << "You typed an invalid directory name [\\, /, *, ?, \", <, >, |]\n" << "Please type in a valid name.\n";
            return false;
        }
    }
    globals::workspace = dir;
    return true;
}


// auto folder part
void auto_folder(std::vector<std::string>& file_types) {
    std::vector<std::filesystem::path> folders_to_create = list_folders(file_types);
    std::vector<std::ofstream> files_to_move;

    if(!create_folders(folders_to_create)) {
        std::cout << "an error has occurred while creating the folders.\n";
    }
    
}
std::vector<std::filesystem::path> list_folders(std::vector<std::string>& file_types) {
    std::vector<std::filesystem::path> folders_to_create;
    std::string workspace_str = globals::workspace.string();
    for(std::string s : file_types) {
        std::filesystem::path path_to_check = workspace_str + "\\" + s;
        std::cout << "Checking: " << path_to_check.string() << "\n"; 
        try {
            if(!dir_exists(path_to_check)) {
                std::cout << "Directory \"" << path_to_check.string() << "\" not found.\n";
                folders_to_create.push_back(path_to_check);
            }
            else {
                std::cout << "Directory \"" << path_to_check.string() << "\" already exists.\n";
            }
        }
        catch(std::filesystem::filesystem_error& e) {
            std::cout << "error: " << e.what() << "\n";
        }
    }
    return folders_to_create;
}

bool execute() {
    return false;
}

bool move_files() {
    return false;
}
bool find_files() {
    return false;
}

bool create_folders(std::vector<std::filesystem::path>& folders_to_create) {
    try {
        for(std::filesystem::path& e : folders_to_create) {
            if(std::filesystem::create_directory(e)) {
                std::cout << "Directory created: " << rainbowText(e.string()) << "\n";
            }
        }    
    }
    catch(std::filesystem::filesystem_error& e) {
        std::cout << "error: " << e.what() << "\n";
        return false;
    }
    return true;
}
bool dir_exists(std::filesystem::path& dir) {
    if (!std::filesystem::exists(dir) || !std::filesystem::is_directory(dir)) {
        return false;
    }
    return true;
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
        // deve ter que fazer outra coisa, se jogar exce��o n�o pode retornar a lista
        return files;
    }
}
