#Makefile for Forester project
all: Patterns_project

Patterns_project: main.o AnimationManager.o Enemy.o Entity.o tests.o \
	TinyXML/tinystr.o TinyXML/tinyxml.o TinyXML/tinyxmlerror.o TinyXML/tinyxmlparser.o
	clang++ main.o AnimationManager.o Enemy.o Entity.o tests.o \
	TinyXML/tinystr.o TinyXML/tinyxml.o TinyXML/tinyxmlerror.o TinyXML/tinyxmlparser.o -o \
	Patterns_project -L lib/ -Wl,-rpath,SFML-2.4.2/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

main.o: main.cpp
	clang++ -c main.cpp -std=c++11

AnimationManager.o: AnimationManager.cpp
	clang++ -c AnimationManager.cpp -std=c++11

Enemy.o: Enemy.cpp
	clang++ -c Enemy.cpp -std=c++11

Entity.o: Entity.cpp
	clang++ -c Entity.cpp -std=c++11

tests.o: tests.cpp
	clang++ -c tests.cpp -std=c++11

tinystr.o: TinyXML/tinystr.cpp
	clang++ -c TinyXML/tinystr.cpp

tinyxml.o: TinyXML/tinyxml.cpp
	clang++ -c TinyXML/tinyxml.cpp

tinyxmlerror.o: TinyXML/tinyxmlerror.cpp
	clang++ -c TinyXML/tinyxmlerror.cpp

tinyxmlparser.o: TinyXML/tinyxmlparser.cpp
	clang++ -c TinyXML/tinyxmlparser.cpp


clean:
	rm -rf *.o