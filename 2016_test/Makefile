# -------- Variables --------
TARGET=bin/main_prog

OBJECTS=bin/labass2016.o bin/main.o

# -------- Compiler --------
CC=g++
CCFLAGS=-Wall

# -------- Compiling options --------
INCFLAGS=-I ./inc

# -------- Compiling --------
bin/%.o : src/%.cpp
	$(CC) $(CCFLAGS) $(INCFLAGS) -c $< -o $@

# -------- Linking --------
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# -------- Running --------
run:
	./$(TARGET)

# -------- Cleaning --------
clean:
	rm bin/*.o $(TARGET)
