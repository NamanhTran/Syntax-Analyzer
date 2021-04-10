#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::unordered_map<std::string, std::string>> parseTable = {
    {"E",
        {
            {"id", "T,E'"},
            {"+", ""},
            {"-", ""},
            {"*", ""},
            {"/", ""},
            {"(", "T,E'"},
            {")", ""},
            {"$", ""}

        }
    },

    {"E'",
        {
            {"id", ""},
            {"+", "+,T,E'"},
            {"-", "-,T,E'"},
            {"*", ""},
            {"/", ""},
            {"(", ""},
            {")", "epsil"},
            {"$", "epsil"}
        }

    },

    {"T",
        {
            {"id", "F,T'"},
            {"+", ""},
            {"-", ""},
            {"*", ""},
            {"/", ""},
            {"(", "F,T'"},
            {")", ""},
            {"$", ""}
        }
    },
    {"T'",
        {
            {"id", ""},
            {"+", "epsil"},
            {"-", "epsil"},
            {"*", "*,F,T'"},
            {"/", "/,F,T'"},
            {"(", ""},
            {")", "epsil"},
            {"$", "epsil"}
        }
    },
    {"F",
        {
            {"id", "id"},
            {"+", ""},
            {"-", ""},
            {"*", ""},
            {"/", ""},
            {"(", "(,E,)"},
            {")", ""},
            {"$", ""}
        }
    }
};
std::unordered_map<std::string, std::string> abbreviatedTable = {
    {"E", "Expression"},
    {"E'", "Expression Prime"},
    {"T", "Term"},
    {"T'", "Term Prime"},
    {"F", "Factor"},
};




