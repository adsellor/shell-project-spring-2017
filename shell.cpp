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

  if(exists(parsing_comands[0])) {
    std::cout << "command exists" << std::endl;
  } else {
    std::cout << "wrong command!!" << std::endl;
  }
}

bool exists(std::string filename) {

  std::vector<std::string> paths;
  paths.push_back("/usr/local/sbin");
  paths.push_back("/usr/local/bin");
  paths.push_back("/usr/sbin");
  paths.push_back("/usr/bin");
  paths.push_back("/bin");

  struct stat buffer; 
 
  for (auto path: paths) {
    std::string name = path + "/" + filename;
    if(stat (name.c_str(), &buffer) == 0) {
      return true;
    }
  }

  return false;
}  
