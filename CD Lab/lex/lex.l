digits [0-9]
letters [a-zA-Z]
delimiters [\,\:\;]
arithmetic [\+\-\*\/\%]
relational [\==\!=\<\>\<=\>=]

%{
int line = 0;
%}

%%
#.* { printf("\n %s - Preprocessor Directive", yytext); }
"/*".*"*/" { printf("\n %s - Comment", yytext); }
\".*\" { printf("\n %s - String", yytext); }

int|float|double|void|long|if|else|while|do|for|goto|break|continue|switch|case|default|return { printf("\n %s - Keyword", yytext); }
{letters}({letters}|{digits})* { printf("\n %s - Identifier", yytext); }
{digits}+ { printf("\n %s - Number", yytext); }
{delimiters} { printf("\n %s - Delimiter", yytext); }

\{ { printf("\n %s - Open Block", yytext); }
\} { printf("\n %s - Close Block", yytext); }
\( { printf("\n %s - Open Parenthesis", yytext); }
\) { printf("\n %s - Close Parenthesis", yytext); }

\n {line++;}
%%

int main() {
  yyin = fopen("add.c", "r");
  yylex();
}

int yywrap() {
return 1;
}
