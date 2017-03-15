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

"|"                                                                           {return PIPE;}



.                                                                             {return NOTOKEN; }
%%
