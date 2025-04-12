# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Directorios
SRC_DIR = .
PERSONAJES_DIR = Personajes
GUERREROS_DIR = $(PERSONAJES_DIR)/Guerreros/Sources
MAGOS_DIR = $(PERSONAJES_DIR)/Magos/Sources
ARMAS_DIR = Armas
ARMAS_MAGICAS_DIR = $(ARMAS_DIR)/Magicas/Sources

# Target del ejecutable
TARGET = juego

# Archivos fuente
SRCS = main.cpp \
       $(GUERREROS_DIR)/Barbaro.cpp \
       $(GUERREROS_DIR)/Caballero.cpp \
       $(GUERREROS_DIR)/Gladiador.cpp \
       $(GUERREROS_DIR)/Guerreros.cpp \
       $(GUERREROS_DIR)/Mercenario.cpp \
       $(GUERREROS_DIR)/Paladin.cpp \
       $(MAGOS_DIR)/Magos.cpp \
       $(ARMAS_DIR)/Combate/Sources/ArmaCombate.cpp \
       $(ARMAS_DIR)/Combate/Sources/espada.cpp \
       $(ARMAS_DIR)/Combate/Sources/garrote.cpp \
       $(ARMAS_DIR)/Combate/Sources/hacha_doble.cpp \
       $(ARMAS_DIR)/Combate/Sources/hacha_simple.cpp \
       $(ARMAS_DIR)/Combate/Sources/lanza.cpp \
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
