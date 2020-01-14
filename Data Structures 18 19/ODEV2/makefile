hepsi: derle calistir
derle:
	g++ -I ./include -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include -o ./lib/CiftYonluBagilListe.o -c ./src/CiftYonluBagilListe.cpp
	g++ -I ./include -o ./lib/DosyaOkuma.o -c ./src/DosyaOkuma.cpp
	g++ -I ./include -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include -o ./src/Dugum.cpp ./src/CiftYonluBagilListe.cpp ./src/DosyaOkuma.cpp ./src/main.cpp -o ./bin/main
calistir:
	./bin/main
	