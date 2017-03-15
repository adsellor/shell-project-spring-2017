#include "shell.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

/* struct Path {
  vector<string> paths;
  void show_path(){
    for (size_t i = 0; i < paths.size(); i++) {
      cout<<paths[i];
    }
  }
  void add_path(string path){
    bool shouldAdd = true;
    for (size_t i = 0; i < paths.size(); i++) {
      if(paths[i] == path){
        shouldAdd = false;
      }
    }
    if(shouldAdd){
      paths.push_back(path);
    }
    else{
      cout<<"The path already exists \n";
    }
  }
  void delete_path(string path){
    for (size_t i = 0; i < paths.size(); i++) {
      if(paths[i] == path){
        paths.erase(paths.begin() + i,paths.begin() + i + 1);
        break;
      }
    }
  }
};

vector<string> parsing (string input_line){
  for (size_t i = 0; i < input_line.size(); i++) {
    if(input_line.at(i) == '|'){
      add_spaces(input_line, i, i + 2);
    }
    if(input_line.at(i) == '<'
    && input_line.at(i + 1) != '<'){
      add_spaces(input_line, i, i + 2);
    }
    if(input_line.at(i) == '>'
    && input_line.at(i + 1) != '>'){
      add_spaces(input_line, i, i + 2);
    }
    if(input_line.at(i) == '>'
    && input_line.at(i + 1) == '>'){
      add_spaces(input_line, i, i + 3);
    }
    if(input_line.at(i) == '<'
    && input_line.at(i + 1) == '<'){
      add_spaces(input_line, i, i + 3);
    }
  }
  stringstream ss (input_line) ;
  vector<string> return_value ;
  for (string word; ss>>word;) {
    return_value.push_back(word);
  }
  for (size_t i = 0; i < return_value.size(); i++) {
    cout << give_me_color(1) << return_value[i] << give_me_color(0) << endl;
  }
  return return_value;
}

void add_spaces(string input_line, size_t& pos1, size_t pos2) {
    input_line.insert(pos1, " ");
    input_line.insert(pos2, " ");
    pos1 = pos2 - pos1 - 1;
}

void fork_exec(vector<string> vector_arg){
    //execvp accepts only an array of string pointers
    const char *program =(vector_arg[0]).c_str();
    const char **arg = new const char* [vector_arg.size()+2];  //extra space for program name and sentinel
    arg [0] = program;
    for (size_t i = 0;  i < vector_arg.size()+1;  ++i)
            arg [i+1] = (vector_arg[i]).c_str();

    arg [vector_arg.size()+1] = NULL;  // end of arguments sentinel is NULL

    int pid =fork();
    if(pid == -1){
        cout << "OH NO :( I am sick, can't do that";
    }
    else if(pid == 0){
        //child
        //exec is execute, 'p': give the name of the program and the operating system will look for the program in the path
        execvp(program, (char **)arg );
    }
    else{
        //parent
          waitpid(pid, NULL, 0);
    }
}

void get_comand(void) {

  string input_line;
  vector<string> parsed_commands;
  cout << "[oh my gosh shell] $ ";
  getline (cin, input_line) ;
  parsed_commands = parsing(input_line);

  fork_exec(parsed_commands);
}

string give_me_color(int color_index) {
  string output;

  // 1 - for red, 2 - for green, 3 - for blue, 4 - for cyan,
  // 5 - for magenta, 0 - for default
  switch (color_index) {
    case 1:
      output = "\033[1;31m";
      break;
    case 2:
      output = "\033[1;32m";
      break;
    case 3:
      output = "\033[1;34m";
      break;
    case 4:
      output = "\033[1;36m";
      break;
    case 5:
      output = "\033[1;35m";
      break;
    case 0:
    default:
      output = "\033[0m";
  }
  return output;
} */

SimpleCommand::SimpleCommand()  {
  _numberOfMaxArguments = 5;
  _numberOfArguments  = 0;
  _arguments(char **) malloc(_numberOfMaxArguments  * sizeof(char *));
}

void SimpleCommand:putArgument(char * argument) {
  if(_numberOfMaxArguments  ==  _numberOfArguments  + 1){
    _numberOfMaxArguments *= 2;
    _arguments  (char **) realloc(_arguments, _numberOfMaxArguments * sizeof(cahr *));
  }

//processes will be added
}
