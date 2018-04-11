clean:$
	\rm -rf cluster$

all:	client.o Head.o Node.o Func.o$
	g++ -o  cluster client.o Head.o Node.o Func.o -pthread

client.o: client.cpp$
	g++ -c -std=c++11 client.cpp -pthread

Head.o:	Head.cpp$
	g++ -c -std=c++11 Head.cpp -pthread

Node.o: Node.cpp$
	g++ -c -std=c++11 Node.cpp -pthread

Func.o: Func.cpp$
	g++ -c -std=c++11 Func.cpp -pthread
