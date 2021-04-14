#include <iostream>
#include <string>

#include "syntax_parser.hpp"

int main(int argc, char** argv) {
    // If the path file was not provided then print the usage instruction
    if (argc != 2) {
        std::cout << "Error no path to test case text file provided in command line." << std::endl;
        std::cout << "Usage: ./main [file_path_to_txt]" << std::endl;

        return 1;
    }

    // Get the file path of the txt in the command line argument
    std::string file_path = argv[1];

    // Start the syntax analysis of the txt content
    syntax_parser(file_path);

    return 0;
}