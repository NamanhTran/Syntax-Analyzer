#include <vector>
#include <fstream>

void outputTexTFile(std::vector <std::pair<std::string, std::vector<std::string>>> x)
{
    // Used to write to an output  file
    std::ofstream outputFile;
    outputFile.open("output.txt");

    // For loop to iterate through the vector
    for (int i = 0; i < x.size(); ++i)
    {

      std::string input = x[i].first;
      char first = input[0];
      // This checks to see if the lexeme is a keyword
      if (input == "int" || input == "float" || input == "bool" || input == "True" || input == "False" ||
          input == "if" || input == "else" || input == "then" || input == "endif" || input == "endelse" ||
          input == "while" || input == "whileend" || input == "do" || input == "enddo" || input == "for" ||
          input == "endfor" || input == "STDinput" || input == "STDoutputand" || input == "or" || input == "not")
      {
          outputFile << "Token: Keyword        Lexeme: ";
      }
      // This checks to see if the lexeme is an identifier
      else if (isalpha(first))
      {
          outputFile << "Token: Identifier     Lexeme: ";
      }
      // This checks to see if the lexeme is a real
      else if (isdigit(first))
      {
          outputFile << "Token: Real           Lexeme: ";
      }
      // This checks to see if the lexeme is a separator
      else if (first == ';' || first == '(' || first == ')' ||
          first == '{' || first == '}' || first == '.' ||
          first == '[' || first == ']' || first == ':' || first == ',')
      {
          outputFile << "Token: Separator      Lexeme: ";
      }
      // This checks to see if the lexeme is an operator
      else if (first == '*' || first == '+' || first == '-' ||
          first == '=' || first == '/' || first == '%' ||
          first == '>' || first == '<')
      {
          outputFile << "Token: Operator       Lexeme: ";
      }
      outputFile << x[i].first << std::endl;
      // Used to iterate through the vector of strings in the pair
      std::vector<std::string>::iterator it = x[i].second.begin();

      // Iterates through the second part of the pair of vectors, which
      // will is a vector of all the production rules for that lexeme
      for (int j = 0; j < x[i].second.size(); ++j)
      {
          outputFile << "  " << *it << std::endl;
          it++;
      }
    }

    outputFile.close();
}
