HEADERS = -I Ejercicio_1/Personajes/ \
          -I Ejercicio_1/Personajes/Magos/Headers/ \
          -I Ejercicio_1/Personajes/Guerreros/Headers/ \
          -I Ejercicio_1/Armas/ \
          -I Ejercicio_1/Armas/Combate/Headers/ \
          -I Ejercicio_1/Armas/Magicas/Headers/ \
          -I Ejercicio_2/ \
          -I Ejercicio_3/

SRC_COMMON = Ejercicio_1/Personajes/Magos/Sources/*.cpp \
             Ejercicio_1/Personajes/Guerreros/Sources/*.cpp \
             Ejercicio_1/Armas/Combate/Sources/*.cpp \
             Ejercicio_1/Armas/Magicas/Sources/*.cpp

SRC_EJ2 = Ejercicio_2/Factory.cpp


ej1:
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio_1/main1.cpp $(SRC_COMMON) -o ejercicio1
	./ejercicio1

ej2:
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio_2/main2.cpp $(SRC_COMMON) $(SRC_EJ2) -o ejercicio2
	./ejercicio2

ej3:
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio_3/main3.cpp $(SRC_COMMON) $(SRC_EJ2) -o ejercicio3
	./ejercicio3

clean:
	rm -f ejercicio1 ejercicio2 ejercicio3
	rm -rf *.dSYM/
