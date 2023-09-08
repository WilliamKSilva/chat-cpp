
client: client.o 
	clang++ build/client.o build/socket.o build/messages.o -o build/client

client.o: socket.o messages.o 
	clang++ -c client/main.cpp -o build/client.o

socket.o: socket.cpp socket.h messages.o
	clang++ -c socket.cpp -o build/socket.o

messages.o: messages.cpp messages.h 
	clang++ -c messages.cpp -o build/messages.o

clear:
	rm -rf build/*.o