CC=gcc
CFLAGS= -Wextra -Wall -pedantic -g

INC= ../Include
SRC= main.c
OBJ= $(SRC:.c=.o)
EXEC=main.exe

all: $(EXEC)
$(EXEC): $(OBJ) $(INC)/calendrier.h
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -I $(INC) -L $(LIB) $(LDFLAGS)
%.o: %.c %.h
	@$(CC) -o $@ -c $< $(CFLAGS)
debug:
	gdb $(EXEC) 
run:
	./$(EXEC)
clean:
	rm $(EXEC) *.o