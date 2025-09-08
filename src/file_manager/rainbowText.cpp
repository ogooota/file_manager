#include "rainbowText.hpp"

std::vector<std::string> colors = {
   "\033[31m", "\033[91m", "\033[33m", "\033[93m",
   "\033[32m", "\033[92m", "\033[36m", "\033[96m",
   "\033[34m", "\033[94m", "\033[35m", "\033[95m",
   "\033[37m", "\033[97m", "\033[90m", "\033[38;5;208m"
};

std::string rainbowText(std::string& text) {
    std::stringstream ss;
    for (int i = 0;i < text.size();i++) {
        ss << colors[i % colors.size()] << text[i];
    }
    ss << colors[12];
    text.replace(0, text.size(), ss.str());
    return text;
}

std::string rainbowText(std::string* text, const int start, const int end) {
    std::string text_content = *text;
    std::string sub_text;
    std::stringstream ss;
    size_t size = end - start;
    sub_text = text_content.substr(start, size);
    for (int i = 0;i < size;i++) {
        ss << colors[i % colors.size()] << sub_text[i];
    }
    ss << colors[12];
    sub_text = ss.str();
    text_content.replace(start, size, sub_text);
    return text_content;
}

std::string rainbowText(std::string* text, const std::string& sub) {
    std::string text_content = *text;
    size_t start = text_content.find(sub);
    size_t end = start + sub.size();
    size_t size = end - start;
    std::string sub_text = text_content.substr(start, size);
    std::stringstream ss;
    for (int i = 0;i < size;i++) {
        ss << colors[i % colors.size()] << sub_text[i];
    }
    ss << colors[12];
    sub_text = ss.str();
    text_content.replace(start, size, sub_text);
    return text_content;
}
