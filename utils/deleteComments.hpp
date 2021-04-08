#include<iostream>
#include<fstream>

std::string deleteComments(std::string c)
{
  int n = c.length();
  bool comment = false;
  std::string newString;

  //Traverse the string
  for(int i = 0; i < n; ++i)
  {
      // This happens if we are at the end of a comment
      if (comment == true && (c[i] == '\n' || c[i] == '!'))
      {
        comment = false;
      }
      //This is where skipping the contents in the comments happens
      else if (comment == true)
      {
        continue;
      }
      //If it starts with a comment, then comment turns true
      else if (c[i] == '!')
      {
        comment = true;
      }
      //Else we add each letter to the new string
      else
      {
        newString += c[i];
      }
  }
  return newString;
}
