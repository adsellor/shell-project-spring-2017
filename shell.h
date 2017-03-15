#pragma once
#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib.h>

void get_comand(void);
std::vector <std::string> parasing (std::string inputLine);
void add_spaces(std::string input_line, size_t& pos1, size_t pos2);
struct Path;
std::string give_me_color(int);
struct SimpleCommand {
  int _numberOfMaxArguments;
  int _numberOfArguments;

  char  **  _arguments;

  SimpleCommand();
  void putArgument(char * argument );
};

struct Command  {
  int _numberOfMaxSimpleCommands;
  int _numberOfSimpleCommands;
  SimpleCommand **  simpleCommands;
  char *  _outFile;
  char  * _errFile;
  int _background;
  int _append;
  int _outCount;
  int _inCount;
  int _errCount;

  void prompt();
  void print();
  void execute();
  void clear();

  Command();
	void insertSimpleCommand( SimpleCommand * simpleCommand );

	static Command _currentCommand;
	static SimpleCommand *_currentSimpleCommand;
};

};
