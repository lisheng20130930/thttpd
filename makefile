# Listen.Li create this file 2012.03.30

TARGET=thttpd
CC=gcc
CFLAGS = -c

VPATH=./:./evnet:./utils:./classes
INCLUDES = -I"./" -I"./classes" -I"./evnet" -I"./utils"
OBJ=acceptor.o\
  aesocket.o\
  channel.o\
  dataqueue.o\
  event.o\
  httparser.o\
  httpc.o\
  httpd.o\
  libnet.o\
  muparser.o\
  upload.o\
  buffer.o\
  libos.o\
  log.o\
  bootstrap.o\
  thttpd.o\
  config.o\
  utils.o
  

$(TARGET):$(OBJ)
	$(CC) $(OBJ) -o $(TARGET) -lm

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf *.o
