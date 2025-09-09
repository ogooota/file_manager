#include <iostream>
#include <filesystem>
#include "fileManager.h"
#include "rainbowText.h"

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
        std::cout << rainbowText("File: ") << e << "\n";
    }
    while(true) {        
        std::cout << "\n->$"; 
        std::string command; std::getline(std::cin, command); 
        if(command == "quit") {
            quit();
        }
        std::vector<std::string> command_vec = split(' ', command);
        if(command_vec[0] == "set" && command_vec[1] == "dir") {
            const std::string dir_name = command_vec[2];
            set_directory(dir_name);
        }
        else if(command_vec[0] == "auto") {
            command_vec.erase(command_vec.begin());
            command_vec = split(',', command_vec[0]);
            auto_folder(command_vec);
        }
    }
    return 0;
}
