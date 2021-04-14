#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Parse_Table {
    public:
        Parse_Table();
        std::vector<std::string> get_value(std::string symbol_key, std::string terminal_key);
    
    private:
        std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> parseTable;
};

Parse_Table::Parse_Table() {
    this->parseTable = {
            {"E",
                {
                    {"id", {"T", "E'"}},
                    {"+", {}},
                    {"-", {}},
                    {"*", {}},
                    {"/", {}},
                    {"(", {"T", "E'"}},
                    {")", {}},
                    {"$", {}}
                }
            },

            {"E'",
                {
                    {"id", {}},
                    {"+", {"+", "T" ,"E'"}},
                    {"-", {"-", "T", "E'"}},
                    {"*", {}},
                    {"/", {}},
                    {"(", {}},
                    {")", {"epsil"}},
                    {"$", {"epsil"}}
                }
            },

            {"T",
                {
                    {"id", {"F", "T'"}},
                    {"+", {}},
                    {"-", {}},
                    {"*", {}},
                    {"/", {}},
                    {"(", {"F", "T'"}},
                    {")", {}},
                    {"$", {}}
                }
            },
            {"T'",
                {
                    {"id", {}},
                    {"+", {"epsil"}},
                    {"-", {"epsil"}},
                    {"*", {"*", "F", "T'"}},
                    {"/", {"/", "F", "T'"}},
                    {"(", {}},
                    {")", {"epsil"}},
                    {"$", {"epsil"}}
                }
            },
            {"F",
                {
                    {"id", {"id"}},
                    {"+", {}},
                    {"-", {}},
                    {"*", {}},
                    {"/", {}},
                    {"(", {"(", "E", ")"}},
                    {")", {}},
                    {"$", {}}
                }
            }
    };
}

std::vector<std::string> Parse_Table::get_value(std::string symbol_key, std::string terminal_key) {
    if (this->parseTable.find(symbol_key) == this->parseTable.end() || this->parseTable[symbol_key].find(terminal_key) == this->parseTable[symbol_key].end()) {
        return {};
    }

    return this->parseTable[symbol_key][terminal_key];
}

class Abbreviated_Table {
    private: 
        std::unordered_map<std::string, std::string> abbreviatedTable;

    public:
        Abbreviated_Table();
        std::string get_expanded(std::string symbol);
};

Abbreviated_Table::Abbreviated_Table() {
    this->abbreviatedTable = {
        {"E", "Expression"},
        {"E'", "Expression Prime"},
        {"T", "Term"},
        {"T'", "Term Prime"},
        {"F", "Factor"},
        {"epsil", "Epsilon"}
    };
}

std::string Abbreviated_Table::get_expanded(std::string symbol) {
    std::cout << "Expanding: " << symbol << std::endl;
    if (this->abbreviatedTable.find(symbol) == this->abbreviatedTable.end()) {
        return symbol;
    }

    return this->abbreviatedTable[symbol];
}