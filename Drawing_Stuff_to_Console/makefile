
# make > compiles and runs binary
# make clean > resets the binary files.

run: main.exe
	./main.exe

main.exe: main.cpp
	g++ ./main.cpp -o ./main.exe

clean:
	rm -rf ./main.exe


c: main.cpp
	g++ ./main.cpp -o ./main.exe
	./main.exe
	rm -rf ./main.exe
