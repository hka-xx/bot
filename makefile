paths = -LC:/lib/boost/lib -IC:/lib/boost 
libs =  /usr/lib/libboost_regex.so 
chatter : main.o chatter.o
	g++ -o chatter main.o chatter.o $(paths) $(libs)
main.o : main.cpp chatter.h
	g++ -c main.cpp
chatter.o : chatter.cpp chatter.h
	g++ -c chatter.cpp $(paths)
clean : 
	rm *.o chatter
