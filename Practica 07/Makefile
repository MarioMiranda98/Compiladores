Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o vect y.tab.c symbol.c init.c math.c vector_cal.c code.c -lm
	@echo Compiled

$(Gram): hoc.y
	@yacc -d hoc.y

clean:
	@rm -f  *.tab.* *.yy.* calc
	@echo Clean
