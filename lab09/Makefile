CC = clang

C_OPTS = $(MAC_OPTS) -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion $(LAB_OPTS) -Isrc
LDLIBS = -lcheck -lm -pthread -lrt -lsubunit

clean:
	rm -rf dist

prep:
	mkdir dist

compile: main.bin test.bin

main.bin: src/main.c src/lib.c
	$(CC) $(C_OPTS) src/main.c src/lib.c -o ./dist/$@

test.bin: test/test.c src/lib.c
	$(CC) $(C_OPTS) test/test.c src/lib.c -o ./dist/$@ $(LDLIBS)

run: main.bin
	./dist/main.bin

test: test.bin
	./dist/test.bin

all: clean prep compile run

check:
	clang-format --verbose -n --Werror src/*
	clang-tidy src/*.c  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump
