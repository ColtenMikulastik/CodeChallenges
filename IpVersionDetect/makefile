
# make > compiles and runs binary
# make clean > resets the binary files.

run: main.exe
	./main.exe

main.exe: main.cpp
	g++ ./main.cpp -o ./main.exe

gdb: 
	g++ -g ./main.cpp -o ./test
	gdb ./test

clean:
	rm -rf ./main.exe
	rm -rf ./test


c: main.cpp
	g++ ./main.cpp -o ./main.exe
	./main.exe
	rm -rf ./main.exe
