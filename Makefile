#

default:
	mkdir -p bin
	gcc -I. -o bin/parser \
		src/main.c \
		src/parser_tests.c \
		src/parser.c \
		src/TestFramework.c
	bin/parser
