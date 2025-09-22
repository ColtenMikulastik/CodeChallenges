

run:add_two_numbers.exe
	./add_two_numbers.exe

add_two_numbers.exe: add_two_numbers.cpp
	g++ ./add_two_numbers.cpp -o ./add_two_numbers.exe

gdb:
	g++ -g ./add_two_numbers.cpp -o ./test.exe
	gdb ./test.exe

clean:
	rm -rf ./*.exe

c: run
	rm -rf ./*.exe
