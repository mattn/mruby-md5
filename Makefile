MRUBY_ROOT = ..

INCLUDES = -I$(MRUBY_ROOT)/include -I$(MRUBY_ROOT)/src -I.
CFLAGS = $(INCLUDES) -O3 -g -Wall -Werror-implicit-function-declaration

CC = gcc
LL = gcc
AR = ar

all : libmrb_md5.a
	@echo done

md5.o : md5.c md5.h
	gcc -c -I. md5.c

mrb_md5.o : mrb_md5.c mrb_md5.h
	gcc -c $(CFLAGS) mrb_md5.c

libmrb_md5.a : mrb_md5.o md5.o
	$(AR) r libmrb_md5.a mrb_md5.o md5.o

clean :
	rm -f *.o libmrb_md5.a
