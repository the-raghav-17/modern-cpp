CPP      := g++
CPPFLAGS := -Wall -Wextra -std=c++17 -Wpedantic -MMD -g

SRC_DIR := .
BUILD_DIR := build

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)

objs: vector pool

test: $(OBJS)
	$(CPP) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $^ -o $@

# ===== Manual rules ===== #

vector: $(BUILD_DIR)/thread_vector.o
pool: $(BUILD_DIR)/threadpool.o

# =====         END         ===== #

-include $(DEPS)

clean:
	rm -fr build/
