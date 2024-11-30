# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -I./Include  # Correct include path
OUTPUT = Security

# Source and object files
SRC = src/main.c
OBJ = src/main.o

# Default target
all: $(OUTPUT)

# Build the output file
$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Pattern rule for object files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
ifeq ($(OS),Windows_NT)
    RM = del /q /f
    SEP = \\
else
    RM = rm -f
    SEP = /
endif

clean:
	@if exist $(subst /,$(SEP),$(OBJ)) $(RM) $(subst /,$(SEP),$(OBJ))
	@if exist $(subst /,$(SEP),$(OUTPUT)) $(RM) $(subst /,$(SEP),$(OUTPUT))

# Rebuild target
rebuild: clean all
