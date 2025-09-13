#include <iostream>
#include <filesystem>
#include <thread>
#include <chrono>
#include "fileManager.h"
#include "graphicals.h"

int main() {
    std::filesystem::path current_path = std::filesystem::current_path();
    std::vector<std::filesystem::path> files = get_current_path_files(current_path);
    
    // add progress bar
    for (int i = 0; i <= files.size();i++) {
        std::string current_progress = progressBar(files.size(), i);
        std::cout << rainbowText(current_progress) << "\r";
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    std::cout << "\n";

    std::vector<std::string> file_names;
    for (int i = 0;i < files.size();i++) {
        std::string file_str = files[i].string();
        std::vector<std::string> file_parts = split('/', file_str);
        for (std::string& e : file_parts) {
            if (e.find('.') != std::string::npos) file_names.push_back(e); 
        }
    }
    for (std::string& e : file_names) {
        std::cout << "File: " << e << "\n";
    }
    while(true) {    
        std::cout << "\n->$"; 
        std::string command; std::getline(std::cin, command); 
        
        // for direct command checks;
        if(command == "quit") {
            quit();
        }
        else if (command == "workspace") {
            std::cout << rainbowText(globals::workspace.string()) << "\n";
        }

        // for flagged commands;
        std::vector<std::string> command_vec = split(' ', command);
        if(command_vec[0] == "set" && command_vec[1] == "dir") {
            const std::string dir_name = command_vec[2];
            if (set_directory(dir_name)) {
                std::cout << "Directory set: " << std::filesystem::current_path().string() + "\\" + rainbowText(dir_name) << "\n";
            }
        }
        else if (command_vec[0] == "execute") {
            erase_first_and_split(&command_vec);
			execute(command_vec);
        }
        else if(command_vec[0] == "auto") {
			erase_first_and_split(&command_vec);
            auto_folder(command_vec);
        }
    }
    return 0;
}

