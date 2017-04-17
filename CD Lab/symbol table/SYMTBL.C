#include<stdio.h>
#include<conio.h>

void main() {
	char expr[50], symtbl[50], sym = 'B';
	int i, top = 0, pos = -1;

	clrscr();
	printf("Enter the Expression:\t");
	scanf("%s", expr);

	for(i = 0; expr[i] != '$'; i++) {
		if(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && expr[i] != '=') {
			symtbl[top++] = expr[i];
		}
	}

	clrscr();
	printf("\nSymbol\tAddr\tType\n");
	for(i = 0; i < top; i++) {
		printf("%c\t%p\tIdentifier\n", symtbl[i], &symtbl[i]);
	}

	printf("\nEnter a symbol to search:\t");
	sym = getch();
	for(i = 0; i < top; i++) {
		if(symtbl[i] == sym) {
			pos = i;
			break;
		}
	}
	if(pos == -1) {
		printf("\nCannot find symbol: %c", sym);
	}
	else {
		printf("\nSymbol\tAddr\tType\n");
		printf("%c\t%p\tIdentifier", symtbl[pos], &symtbl[pos]);
	}

	getch();
}