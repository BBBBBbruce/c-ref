

# -------- Compiler --------
CC = g++
CPPFLAGS = -std=c++11 -W -Wall


all: ./bin/main.o ./bin/labass2017.o
	$(CC) $(CPPFLAGS) ./bin/main.o ./bin/labass2017.o -o ./bin/main_prog
# -------- Compiling --------
./bin/labass2017.o: ./src/labass2017.cpp ./inc/labass2017.hpp
	$(CC) $(CPPFLAGS) -c ./src/labass2017.cpp  -o ./bin/labass2017.o

./bin/main.o: ./src/main.cpp
	$(CC) $(CPPFLAGS) -c ./src/main.cpp  -o ./bin/main.o


#note: if using an external library, placed in folder lib/, then use the variable LIBFLAGS
#$(CC) $(LIBFLAGS) $(OBJECTS) -o bin/$(TARGET)


# -------- Running --------
run:
	./bin/main_prog

# -------- Cleaning --------
clean:
	rm bin/*.o
