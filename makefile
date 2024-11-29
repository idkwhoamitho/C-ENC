CC = gcc
CFLAG = -Wall -Wextra -Werror -std=c11 -I./Include  # Correct the include path here
output = EncryptDecrypt

# Source and object files
SRC = src/main.c
OBJ = src/main.o

all: $(output)

$(output): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(output)

rebuild: clean all
