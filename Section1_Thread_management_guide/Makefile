prepare:
	mkdir bin
clean: 
	rm -rf bin
compile:
	g++ -std=c++20 $(file).cpp -o ./bin/$(file)
compile_wheader:
	g++ -std=c++20 $(file).cpp $(header).h -o ./bin/$(file)
compile_wclass:
	g++ -std=c++20 $(main).cpp $(file).cpp $(header).h -o ./bin/$(file)