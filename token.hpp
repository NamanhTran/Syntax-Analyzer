#include <iostream>
#include <string>
#include <set>
#include <vector>
//need to get a processed string into this file later for the lexical analyzer

std::vector<std::string> tokenize(std::string token_string) {
    std::set<std::string> operator_set = {"+", "-", "/", "%", "*" ,"=", "(", ")"};
    
    std::vector<std::string> tokens;

    std::string temp_token;
    
    for (int i = 0; i < token_string.size(); i++) {

        if (token_string[i] == ' ') {
            continue;
        } 
        
        else if (operator_set.find(std::string(1, token_string[i])) != operator_set.end()) {
            if (!temp_token.empty()) {
                tokens.push_back("id");
                temp_token.clear();
            }
            
            tokens.push_back(std::string(1, token_string[i]));
        } 
        
        else {
            temp_token.append(std::string(1, token_string[i]));
        }
    }
    if (!temp_token.empty()) {
        tokens.push_back("id");
    }
    return tokens;
}
