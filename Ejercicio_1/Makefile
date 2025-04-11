CXX = g++
CXXFLAGS = -std=c++11 -Wall -I.
TARGET = barbaro_test
SRCS = main.cpp \
       Personajes/Guerreros/Sources/Barbaro.cpp \
       Personajes/Guerreros/Sources/Guerreros.cpp \
       Armas/Combate/Sources/hacha_doble.cpp \
       Armas/Combate/Sources/ArmaCombate.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
