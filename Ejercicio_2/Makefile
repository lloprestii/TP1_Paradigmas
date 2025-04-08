CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./Armas/Headers -I./Armas/Combate/Headers -I./Armas/Magicas/Headers

SRC_DIR = .
ARMA_SRC_DIR = Armas
COMBATE_SRC_DIR = Armas/Combate/Sources
MAGICAS_SRC_DIR = Armas/Magicas/Sources

SRCS = $(SRC_DIR)/main.cpp \
       $(COMBATE_SRC_DIR)/ArmaCombate.cpp \
       $(COMBATE_SRC_DIR)/Espada.cpp \
       $(MAGICAS_SRC_DIR)/ArmaMagica.cpp \
       $(MAGICAS_SRC_DIR)/BastonMagico.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) 