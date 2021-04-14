#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>

#include "./parseTable.hpp"
#include "./token.hpp"
#include "./utils/input_file.hpp"
#include "./utils/deleteComments.hpp"

std::string vector_to_string(std::vector<std::string> vector);
std::vector<std::string> lines_into_vector(std::string);

class Syntax_Parser
{
private:
    // Create a set where it contains non-terminal symbols
    std::set<std::string> non_terminal_set;

    Parse_Table parse_table = Parse_Table();
    Abbreviated_Table abbreviated_table = Abbreviated_Table();

    std::vector<std::pair<std::string, std::vector<std::string> > > production_rules_pairs;

public:
    Syntax_Parser();
    void parse(std::string input_string);
    std::vector<std::pair<std::string, std::vector<std::string> > > get_production_rules();
};

Syntax_Parser::Syntax_Parser()
{
    this->non_terminal_set = {"E", "E'", "T", "T'", "F", "epsil"};
}

void Syntax_Parser::parse(std::string input_string)
{
    // Initalize syntax_parser stack, input string
    std::stack<std::string> syntax_parser_stack;
    std::stack<std::string> token_stack;

    // Identify which table to use

    std::vector<std::string> string_tokens = tokenize(input_string);

    // Push $ to syntax_parser stack and append $ to end of string (?)
    syntax_parser_stack.push("$");

    // Add starting symbol to the syntax_parser stack (?)
    syntax_parser_stack.push("E");

    // Add $ to the token_stack
    token_stack.push("$");
    for (int i = string_tokens.size() - 1; i >= 0; i--)
    {
        token_stack.push(string_tokens[i]);
    }

    // Temporary variable to hold the current token's production rule
    std::pair<std::string, std::vector<std::string> > temp_production_rules = {token_stack.top(), {}};

    // Loop until stack is empty
    while (!syntax_parser_stack.empty())
    {
        std::string symbol = syntax_parser_stack.top();
        std::string token = token_stack.top();

        if (this->non_terminal_set.find(symbol) == this->non_terminal_set.end())
        {
            if (symbol == token)
            {
                syntax_parser_stack.pop();
                token_stack.pop();

                if (!syntax_parser_stack.empty())
                {
                    symbol = syntax_parser_stack.top();
                    token = token_stack.top();
                    // End of production rules for token
                    this->production_rules_pairs.push_back(temp_production_rules);

                    // Initalize the temporary variable for the next token
                    temp_production_rules = {token, {}};
                }
            }

            else
            {
                // Generate Syntax Error by adding an error to the production rule vector
                temp_production_rules.second.push_back("error: " + symbol + " expected.");
                this->production_rules_pairs.push_back(temp_production_rules);
                break;
            }
        }

        else
        {
            if (!this->parse_table.get_value(symbol, token).empty())
            {
                syntax_parser_stack.pop();
                std::vector<std::string> new_symbols = this->parse_table.get_value(symbol, token);

                for (int i = new_symbols.size() - 1; i >= 0; i--)
                {
                    if (new_symbols[i] != "epsil")
                    {
                        syntax_parser_stack.push(new_symbols[i]);
                    }
                }

                // Push production rule used for the token
                temp_production_rules.second.push_back("<" + this->abbreviated_table.get_expanded(symbol) + ">" + " -> " + vector_to_string(new_symbols));

                symbol = syntax_parser_stack.top();
            }

            else
            {
                // Generate Syntax Error by adding an error to the production rule vector
                temp_production_rules.second.push_back("error: " + symbol + " expected.");
                this->production_rules_pairs.push_back(temp_production_rules);
                break;
            }
        }
    }
}

std::vector<std::pair<std::string, std::vector<std::string> > > Syntax_Parser::get_production_rules()
{
    return this->production_rules_pairs;
}

std::string vector_to_string(std::vector<std::string> vector)
{
    std::string vector_string;
    Abbreviated_Table abbreviated_table = Abbreviated_Table();

    for (int i = 0; i < vector.size(); i++)
    {
        vector_string.append("<" + abbreviated_table.get_expanded(vector[i]) + ">");
    }

    return vector_string;
}

std::vector<std::string> lines_into_vector(std::string input_string)
{
    std::vector<std::string> string_vector;
    std::string temp_string;

    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] != '\n')
        {
            temp_string.append(std::string(1, input_string[i]));
        }

        else
        {
            if (temp_string.length() > 0)
            {
                string_vector.push_back(temp_string);
                temp_string.clear();
            }
        }
    }

    return string_vector;
}