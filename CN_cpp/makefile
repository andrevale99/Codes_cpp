GCC = g++
FLAGS = 

MAIN = main.cpp
INCL = CN.hpp CN.cpp

OUT = program.out

all: $(OUT)

$(OUT): $(MAIN) $(INCL)
	$(GCC) $(FLAGS) $(MAIN) $(INCL) -o $(OUT)

clear:
	@rm $(OUT)
	@rm *~
	@rm *.gch
