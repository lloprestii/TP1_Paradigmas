# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I.
LDFLAGS = 

# Nombre del ejecutable
TARGET = juego_guerreros

# Directorios
SRC_DIR = .
PERSONAJES_DIR = Personajes
GUERREROS_DIR = $(PERSONAJES_DIR)/Guerreros/Sources
MAGOS_DIR = $(PERSONAJES_DIR)/Magos/Sources
ARMAS_DIR = Armas/Combate/Sources
ARMAS_MAGICAS_DIR = Armas/Magicas/Sources

# Archivos fuente
SRCS = $(SRC_DIR)/main.cpp \
       $(GUERREROS_DIR)/Barbaro.cpp \
       $(GUERREROS_DIR)/Caballero.cpp \
       $(GUERREROS_DIR)/Gladiador.cpp \
       $(GUERREROS_DIR)/Guerreros.cpp \
       $(GUERREROS_DIR)/Mercenario.cpp \
       $(GUERREROS_DIR)/Paladin.cpp \
       $(MAGOS_DIR)/Magos.cpp \
       $(ARMAS_DIR)/ArmaCombate.cpp \
       $(ARMAS_DIR)/espada.cpp \
       $(ARMAS_DIR)/garrote.cpp \
       $(ARMAS_DIR)/hacha_doble.cpp \
       $(ARMAS_DIR)/hacha_simple.cpp \
       $(ARMAS_DIR)/lanza.cpp \
       $(ARMAS_MAGICAS_DIR)/ArmaMagica.cpp \
       $(ARMAS_MAGICAS_DIR)/Amuleto.cpp \
       $(ARMAS_MAGICAS_DIR)/LibroHechizos.cpp \
       $(ARMAS_MAGICAS_DIR)/Pocion.cpp \
       $(ARMAS_MAGICAS_DIR)/Baston.cpp

# Objetos
OBJS = $(SRCS:.cpp=.o)

# Regla principal
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET)

# Regla para compilar cada archivo fuente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Para asegurar que clean siempre se ejecute
.PHONY: clean
