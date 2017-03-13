/* LEXER FOR SHELL */


%{

  #include <string.h> 
  #include "y.tab.h" 

%}

%%

\n                                                                            {return NEWLINE;}

[ \t]                                                                         {}

">"                                                                           {return GREAT;}

"<"                                                                           {return LESS;}

">>"                                                                          {return GREATGREAT;}

"&"                                                                           {return AMPERSAND;}

">&"                                                                          {return GREATAMPERSAND;}

"))"                                                                          {return AMPERBANG;}

"&>"	                                                                        {return AMPOUTANG;}

"&>|"                                                                         {return OUTANGAMPBANG;}

">>&"	                                                                        {return DOUTANGAMP;	}

">>&|"	                                                                      {return DOUTANGAMPBANG; }

"|"                                                                           {return PIPE;}

"|&"	                                                                        {return PIPEAMP;}

.                                                                             {return NOTOKEN; }
%%
