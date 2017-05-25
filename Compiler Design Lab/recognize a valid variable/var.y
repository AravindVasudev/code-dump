%{
  #include<stdio.h>
  int valid = 1;
%}

%token digit letter

%%
start : letter s
s     : letter s
      | digit s
      | letter
      ;
%%

int yyerror() {
  printf("It's not an identifier");
  valid = 0;
  return 0;
}

int yywrap() { return 1; }

int main() {
  printf("Enter the identifier:\n");
  yyparse();

  if(valid)
    printf("It's an identifier");
}
