all: ae

ae: main.cpp
	g++ -o ae main.cpp

install:
	rm -rf ./*.o
	mv ./ae /usr/bin
