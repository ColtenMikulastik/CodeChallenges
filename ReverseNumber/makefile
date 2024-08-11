

reversenumber: reversenumber.exe
	./reversenumber.exe

reversenumber.exe: reversenumber.cpp
	g++ reversenumber.cpp -o reversenumber.exe

clean:
	rm -rf ./*.exe

c:
	g++ -g reversenumber.cpp -o debugging.exe
	gdb ./debugging.exe

