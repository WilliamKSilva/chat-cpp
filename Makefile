
binary: server.o client.o
	clang++ build/server.o build/socket.o build/messages.o -o build/server
	clang++ build/client.o build/socket.o build/messages.o -o build/client
	rm -rf build/*.o

client.o: socket.o messages.o 
	clang++ -c client/main.cpp -o build/client.o

server.o: socket.o messages.o
	clang++ -c server/main.cpp -o build/server.o

socket.o: socket.cpp socket.h messages.o
	clang++ -c socket.cpp -o build/socket.o

messages.o: messages.cpp messages.h 
	clang++ -c messages.cpp -o build/messages.o

clear:
	rm -rf build/*.o