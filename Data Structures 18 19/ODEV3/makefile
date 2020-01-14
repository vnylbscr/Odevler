hepsi: derle calistir
derle:
	g++ -I ./include -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include -o ./lib/DosyaOkuma.o -c ./src/DosyaOkuma.cpp
	g++ -I ./include -o ./lib/main.o -c ./src/Test.cpp
	g++ -I ./include -o ./src/Dugum.cpp ./src/BST.cpp ./src/DosyaOkuma.cpp ./src/Test.cpp -o ./bin/main
calistir:
	./bin/main