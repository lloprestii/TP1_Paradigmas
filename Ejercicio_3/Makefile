CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I..
DEBUG_FLAGS = -g
RELEASE_FLAGS = -O2

# Directorios base
EJERCICIO1_DIR = ../Ejercicio_1
EJERCICIO2_DIR = ../Ejercicio_2

# Archivos fuente
SRCS = main.cpp \
       $(EJERCICIO2_DIR)/Factory.cpp \
       $(EJERCICIO1_DIR)/Personajes/Guerreros/Sources/Guerreros.cpp \
       $(EJERCICIO1_DIR)/Personajes/Guerreros/Sources/Barbaro.cpp \
       $(EJERCICIO1_DIR)/Personajes/Guerreros/Sources/Caballero.cpp \
       $(EJERCICIO1_DIR)/Personajes/Guerreros/Sources/Gladiador.cpp \
       $(EJERCICIO1_DIR)/Personajes/Guerreros/Sources/Mercenario.cpp \
       $(EJERCICIO1_DIR)/Personajes/Guerreros/Sources/Paladin.cpp \
       $(EJERCICIO1_DIR)/Personajes/Magos/Sources/Magos.cpp \
       $(EJERCICIO1_DIR)/Personajes/Magos/Sources/Hechicero.cpp \
       $(EJERCICIO1_DIR)/Personajes/Magos/Sources/Conjurador.cpp \
       $(EJERCICIO1_DIR)/Personajes/Magos/Sources/Nigromante.cpp \
       $(EJERCICIO1_DIR)/Personajes/Magos/Sources/Brujo.cpp \
       $(EJERCICIO1_DIR)/Armas/Combate/Sources/ArmaCombate.cpp \
       $(EJERCICIO1_DIR)/Armas/Combate/Sources/hacha_simple.cpp \
       $(EJERCICIO1_DIR)/Armas/Combate/Sources/hacha_doble.cpp \
       $(EJERCICIO1_DIR)/Armas/Combate/Sources/espada.cpp \
       $(EJERCICIO1_DIR)/Armas/Combate/Sources/lanza.cpp \
       $(EJERCICIO1_DIR)/Armas/Combate/Sources/garrote.cpp \
       $(EJERCICIO1_DIR)/Armas/Magicas/Sources/ArmaMagica.cpp \
       $(EJERCICIO1_DIR)/Armas/Magicas/Sources/LibroHechizos.cpp \
       $(EJERCICIO1_DIR)/Armas/Magicas/Sources/Amuleto.cpp \
       $(EJERCICIO1_DIR)/Armas/Magicas/Sources/Pocion.cpp \
       $(EJERCICIO1_DIR)/Armas/Magicas/Sources/Baston.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = personajes

# Target por defecto
all: $(TARGET)

# Compilación en modo debug
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Compilación en modo release
release: CXXFLAGS += $(RELEASE_FLAGS)
release: $(TARGET)

# Target principal
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all debug release clean 