#include "shell.h"

std::vector<std::string> parsing (std::string input_line){
  for (int i = 0; i < input_line.size(); i++) {
    if(input_line.at(i) == '|'){
      input_line.insert(i, " ");
      input_line.insert(i + 2, " ");
      i++;
    }
    if(input_line.at(i) == '<'
    && input_line.at(i + 1) != '<'){
        input_line.insert(i, " ");
        input_line.insert(i + 2, " ");
        i++;
    }
    if(input_line.at(i) == '>'
    && input_line.at(i + 1) != '>'){
        input_line.insert(i, " ");
        input_line.insert(i + 2, " ");
        i++;
    }
    if(input_line.at(i) == '>'
    && input_line.at(i + 1) == '>'){
        input_line.insert(i, " ");
        input_line.insert(i + 3, " ");
        i+=2;
    }
    if(input_line.at(i) == '<'
    && input_line.at(i + 1) == '<'){
        input_line.insert(i, " ");
        input_line.insert(i + 3, " ");
        i+=2;
    }
  }
  std::stringstream ss (input_line) ;
  std::vector<std::string> return_value ;
  for ( std::string word; ss>>word;) {
    return_value.push_back(word);
  }
  for (int i = 0; i < return_value.size(); i++) {
    std::cout << return_value[i] << std::endl;
  }
  return return_value;
}

void get_comand(void) {
  std::string input_line;
  std::vector<std::string> parsing_comands;
  std::cout << "[o my gosh shell] $ ";
  getline (std::cin, input_line) ;
  parsing_comands = parsing(input_line);
}
