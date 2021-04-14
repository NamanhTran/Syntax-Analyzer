#include <iostream>

#include "./table_parser.hpp"
#include "./outputFile.hpp"

void syntax_parser(std::string file_path)
{
    std::string input_string = inputFile(file_path);
    std::string formatted_string = deleteComments(input_string);

    std::vector<std::string> string_vector = lines_into_vector(formatted_string);

    Syntax_Parser syntax_parser = Syntax_Parser();

    for (int i = 0; i < string_vector.size(); i++)
    {
        syntax_parser.parse(string_vector[i]);
    }

    auto production_rules_pairs = syntax_parser.get_production_rules();

    // // DEBUG: Print the production rule for each token
    // for (int i = 0; i < production_rules_pairs.size(); i++) {
    //     std::string token = production_rules_pairs[i].first;
    //     std::vector<std::string> production_rules = production_rules_pairs[i].second;

    //     std::cout << "token: " << token << std::endl << "Production Rules:" << std::endl;

    //     for (int j = 0; j < production_rules.size(); j++) {
    //         std::cout << production_rules[j] << std::endl;
    //     }

    //     std::cout << std::endl;
    // }

    outputTexTFile(production_rules_pairs);
}