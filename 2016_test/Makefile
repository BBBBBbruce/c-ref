

# -------- Compiler --------
CC = g++
CPPFLAGS = -std=c++11 -W -Wall


all: ./bin/main.o ./bin/labass2016.o
	$(CC) $(CPPFLAGS) ./bin/main.o ./bin/labass2016.o -o ./bin/main_prog
# -------- Compiling --------
./bin/labass2016.o: ./src/labass2016.cpp ./inc/labass2016.hpp
	$(CC) $(CPPFLAGS) -c ./src/labass2016.cpp  -o ./bin/labass2016.o

./bin/main.o: ./src/main.cpp
	$(CC) $(CPPFLAGS) -c ./src/main.cpp  -o ./bin/main.o

# -------- Linking --------




#note: if using an external library, placed in folder lib/, then use the variable LIBFLAGS
#$(CC) $(LIBFLAGS) $(OBJECTS) -o bin/$(TARGET)


# -------- Running --------
run:
	./bin/main_prog

# -------- Cleaning --------
clean:
	rm bin/*.o
