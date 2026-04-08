#include <iostream>
#include "dabai.h"
#include <sstream>
#include <fstream>
#include <sys/stat.h>

bool file_exists(const std::string& path) {
    struct stat st;
    return stat(path.c_str(), &st) == 0;
}

std::string read_file(const std::string& path) {
    std::ifstream ifs(path);
    if (!ifs) throw std::runtime_error("Cannot read file: " + path);
    std::ostringstream content;
    content << ifs.rdbuf();
    return content.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <question> [file]..." << std::endl;
        return 1;
    }

    std::ostringstream question_parts;
    std::ostringstream files_content;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (file_exists(arg)) {
            files_content << "\n\n[File: " << arg << "]\n" << read_file(arg);
        } else {
            if (i > 1 && !question_parts.str().empty()) question_parts << " ";
            question_parts << arg;
        }
    }

    std::ostringstream prompt;
    prompt << question_parts.str() << files_content.str();

    try {
        std::string response = ask_dabai(prompt.str());
        std::cout << response << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
