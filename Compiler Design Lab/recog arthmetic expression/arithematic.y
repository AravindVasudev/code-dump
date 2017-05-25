%{
  #include<stdio.h>
  int valid = 0, temp;
%}

%token num
%left '+' '-' '*' '/'
%nonassoc UMINUS

%%
expr1 : expr { temp = $1; }
expr  : expr '+' expr { $$ = $1 + $3; }
      | expr '-' expr { $$ = $1 - $3; }
      | expr '*' expr { $$ = $1 * $3; }
      | expr '/' expr { if($3 == 0) { valid = 1; $$ = 0; } else { $$ = $1 / $3; } }
      | '('expr')' { $$ = $2; }
      | '-'expr { $$ = -1 * $2; }
      | num { $$ = yylval; }
      ;
%%

int yyerror() {
  printf("\nINVALID EXPRESSION\n");
  valid = 2;
  return 0;
}

int yywrap() { return 1; }

int main() {
  printf("Enter the Expression:\n");
  yyparse();

  if(valid == 1) printf("\nDIVIDE BY 0!\n");
  else if(valid == 0) printf("\nVALUE:\t%d\n", temp);
}
