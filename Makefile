TARGET_EXEC ?= TTP
CC 			 = gcc

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
OBJ_DIR ?= .obj

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -Wall -std=c99

$(TARGET_EXEC): $(OBJS)
	@$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@echo "CC "$<" compilado..."

.PHONY: clean

clean:
	@$(RM) -r $(BUILD_DIR)
	@$(RM) -r $(TARGET_EXEC)
	@echo "Diretorio \""$(BUILD_DIR)"\" removido!"
	@echo "Executavel \""$(TARGET_EXEC)"\" removido!"

-include $(DEPS)

MKDIR_P ?= mkdir -p