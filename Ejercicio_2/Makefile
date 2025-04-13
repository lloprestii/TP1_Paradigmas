# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -I../Ejercicio_1 -I../Ejercicio_1/Personajes/Guerreros/Headers -I../Ejercicio_1/Personajes/Magos/Headers -I../Ejercicio_1/Armas/Combate/Headers -I../Ejercicio_1/Armas/Magicas/Headers

# Directorios
EJERCICIO1_DIR = ../Ejercicio_1
PERSONAJES_DIR = $(EJERCICIO1_DIR)/Personajes
GUERREROS_DIR = $(PERSONAJES_DIR)/Guerreros/Sources
MAGOS_DIR = $(PERSONAJES_DIR)/Magos/Sources
ARMAS_DIR = $(EJERCICIO1_DIR)/Armas
ARMAS_COMBATE_DIR = $(ARMAS_DIR)/Combate/Sources
ARMAS_MAGICAS_DIR = $(ARMAS_DIR)/Magicas/Sources

# Target del ejecutable
TARGET = juego

# Archivos fuente del ejercicio 2
SRCS = main.cpp \
       Factory.cpp

# Archivos fuente del ejercicio 1 necesarios
SRCS += $(GUERREROS_DIR)/Barbaro.cpp \
        $(GUERREROS_DIR)/Caballero.cpp \
        $(GUERREROS_DIR)/Gladiador.cpp \
        $(GUERREROS_DIR)/Guerreros.cpp \
        $(GUERREROS_DIR)/Mercenario.cpp \
        $(GUERREROS_DIR)/Paladin.cpp \
        $(MAGOS_DIR)/Magos.cpp \
        $(MAGOS_DIR)/Brujo.cpp \
        $(MAGOS_DIR)/Conjurador.cpp \
        $(MAGOS_DIR)/Hechicero.cpp \
        $(MAGOS_DIR)/Nigromante.cpp \
        $(ARMAS_COMBATE_DIR)/ArmaCombate.cpp \
        $(ARMAS_COMBATE_DIR)/espada.cpp \
        $(ARMAS_COMBATE_DIR)/garrote.cpp \
        $(ARMAS_COMBATE_DIR)/hacha_doble.cpp \
        $(ARMAS_COMBATE_DIR)/hacha_simple.cpp \
        $(ARMAS_COMBATE_DIR)/lanza.cpp \
        $(ARMAS_MAGICAS_DIR)/ArmaMagica.cpp \
        $(ARMAS_MAGICAS_DIR)/Amuleto.cpp \
        $(ARMAS_MAGICAS_DIR)/LibroHechizos.cpp \
        $(ARMAS_MAGICAS_DIR)/Pocion.cpp \
        $(ARMAS_MAGICAS_DIR)/Baston.cpp

# Objetos
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Regla para el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Regla para compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Para asegurar que clean siempre se ejecute
.PHONY: clean all 