
CC = gcc
RM = rm -f

#CFLAGS = -c -I/usr/include/mysql -ggdb -pipe -fdebug-prefix-map=/usr/src/ports/mysql/mysql-5.5.28-1/build=/usr/src/debug/mysql-5.5.28-1 -fdebug-prefix-map=/usr/src/ports/mysql/mysql-5.5.28-1/src/mysql-5.5.28=/usr/src/debug/mysql-5.5.28-1 -g
CFLAGS = -c 
#LIBS = -L/usr/lib -lmysqlclient -lz -lssl -lcrypto
LIBS = -L/usr/lib -lz

WARNINGS = -Wall

OBJS=nova_compatible.o utility.o security.o network.o exception.o route.o
TARGET=nova

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
		$(RM) $(OBJS) $(TARGET) core strace* ltrace* *.stackdump *~

.c.o:
		$(CC) $(CFLAGS) $(WARNINGS) $*.c
