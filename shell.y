/* PARSER FOR SHELL
 Arguments and executions will be added
*/
%%
goal:
	commands
	;

commands:
	command
	| commands command
	;

command: simple_command
        ;

simple_command:
	pipe_list iomodifier_list background_opt NEWLINE {
	  //Command Execution
	}
        | NEWLINE
	| error NEWLINE
         	 ;

pipe_list:
    pipe_list PIPE command_and_args
    | command_and_args
    ;

command_and_args:
	command_word arg_list {

	}
	;

arg_list:
	arg_list argument
	| /* can be empty */
	;

argument:
	WORD {

	}
	;

command_word:
	WORD {

	}
	;

iomodifier_list:
       iomodifier_list iomodifier_opt
       | /* can be empty */
       ;

iomodifier_opt:
	GREAT WORD {

	}
	|
	GREATGREAT WORD {

	}
	|
	GREATAMP WORD {

	}
	|
	GREATGREATAMP WORD {

	}
	|
	LESS WORD {

	}
	;

background_opt:
	AMPERSAND {

	}
	| /* can be empty */
	;
%%
