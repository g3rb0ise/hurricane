# Project global settings
EXE     :=hurricane
CC      :=g++
CFLAGS  := -Wall -Werror -Wuninitialized -Wunused
LDFLAGS := 
LIBS    := 

# Project directory structure
BIN_DIR := bin
OBJ_DIR := build
SRC_DIR := src

# Construct OBJ_DIR output and dependency filenames
SRCS := $(shell find $(SRC_DIR) -name *.cpp)
HPPS := $(shell find $(SRC_DIR) -name *.hpp)
OBJS := $(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(addsuffix .o,$(basename $(SRCS))))

.PHONY: info clean mrproper all

# Main task
all: $(BIN_DIR)/$(EXE)

# Build target
$(BIN_DIR)/$(EXE): $(OBJS) $(HPPS)
	@echo "[*] Project compilation ..."
	@mkdir -p $(dir $@)
	@$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $@
	@echo "Done"

# Compile all cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c -o $@ $<
	
# clean project
clean:
	@echo "[*] Clean project"
	@rm -rf $(OBJ_DIR)

# remove executable
mrproper: clean
	@echo "[*] Delete all generated files"
	@rm -rf $(BIN_DIR)

# Get informations about MAKEFILE configuration
info:
	@echo "[*] Executable name: ${EXE}"
	@echo "[*] Application dir: ${BIN_DIR}"
	@echo "[*] Object dir:      ${OBJ_DIR}"
	@echo "[*] Sources dir:     ${SRC_DIR}"
	@echo "[*] Sources:         ${SRCS}"
	@echo "[*] Headers:         ${HPPS}"
	@echo "[*] Objects:         ${OBJS}"
	@echo "[*] CFLAGS:          ${CFLAGS}"
	@echo "[*] LDFLAGS:         ${LDFLAGS}"
	@echo "[*] LIBS:            ${LIBS}"