# Répertoires
SRC_DIR = src
AGENT_DIR = $(SRC_DIR)/Agent
RULE_DIR = $(SRC_DIR)/Rule
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Nom de l'exécutable
TARGET = $(BIN_DIR)/main

# Fichiers source
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(AGENT_DIR)/*.cpp) $(wildcard $(RULE_DIR)/*.cpp)

# Fichiers objets dans le dossier build (en remplaçant src/ par build/)
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(subst $(SRC_DIR)/,,$(SRCS)))

# Compilateur et options
CXX = g++
CXXFLAGS = -g -I$(INCLUDE_DIR)
LIBS = -lSDL2_gfx -lSDL2main -lSDL2

# Cibles
all: $(TARGET)

# Lier les objets pour créer l'exécutable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Compiler chaque .cpp en .o dans build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
