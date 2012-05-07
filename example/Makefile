MRUBY_ROOT = ../..
ifeq ($(OS),Windows_NT)
MRUBY_LIB := $(MRUBY_ROOT)/lib/libmruby.a
LDFLAGS = $(MRUBY_LIB) ../libmrb_md5.a
else
MRUBY_LIB := $(MRUBY_ROOT)/lib/libmruby.a
LDFLAGS = $(MRUBY_LIB) ../libmrb_md5.a
endif

INCLUDES = -I$(MRUBY_ROOT)/include -I$(MRUBY_ROOT)/src -I..
CFLAGS = $(INCLUDES) -O3 -g -Wall -Werror-implicit-function-declaration

CC = gcc
LL = gcc
AR = ar

all : main
	@echo done

main : main.c
	gcc $(CFLAGS) -o main main.c ../libmrb_md5.a $(LDFLAGS)

clean :
	rm -f *.o main
