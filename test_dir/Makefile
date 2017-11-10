CC		= gcc

SRC		= ../list.c
EXEC	= test

OBJ		= tester.o
SECRET	= tester.c
HEADERS	= tester.h

.PHONY: all
all: $(EXEC)
$(EXEC): $(SRC) $(OBJ)
	@gcc $(SRC) $(OBJ) -o $@

obj: $(SECRET)
	@gcc -c $^ -o $(OBJ)

.PHONY: clean
clean:
	@rm -f $(EXEC) $(OBJ)
