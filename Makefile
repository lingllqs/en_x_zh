CC = gcc
PREFIX ?= $(HOME)/.local
BINDIR = $(PREFIX)/bin
SHAREDIR = $(PREFIX)/share/stardict

CFLAGS = -Iinclude -Wall -O2 -DDB_PATH=\"$(SHAREDIR)/stardict.db\"
LDFLAGS = -lsqlite3

SRC = src/main.c src/db.c src/query.c src/cli.c src/render.c

# ===== 输出目录 =====
BUILD_DIR = build
BIN_DIR = bin
TARGET = $(BIN_DIR)/dict

# ===== 自动生成 .o 文件路径 =====
OBJ = $(SRC:src/%.c=$(BUILD_DIR)/%.o)

# ===================== 默认目标 =====================
all: $(TARGET)

# ===================== 链接 =====================
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)

# ===================== 编译规则 =====================
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ===================== 运行 =====================
run: all
	./$(TARGET)

# ===================== 安装 =====================

install: all
	@echo "Installing binary..."
	mkdir -p $(BINDIR)
	cp $(TARGET) $(BINDIR)/dict

	@echo "Installing database..."
	mkdir -p $(SHAREDIR)

	@if [ -f "$(SHAREDIR)/stardict.db" ]; then \
		echo "⚠ Database already exists, skipping copy."; \
	else \
		cp data/stardict.db $(SHAREDIR)/stardict.db; \
		echo "✔ Database installed."; \
	fi

	@echo "Done."

# ===================== 卸载 =====================
uninstall:
	rm -f $(BINDIR)/dict
	rm -rf $(SHAREDIR)

# ===================== 清理 =====================
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
