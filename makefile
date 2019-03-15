# Listen.Li create this file 2012.03.30

TARGET=thttpd
CC=gcc
CFLAGS = -c -std=c99

VPATH=./:./evnet:./http:./utils:./classes
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
  msg_pack.o\
  msgc.o\
  msgd.o\
  msgpraser.o\
  Base64.o\
  buffer.o\
  cJSON.o\
  Crc16.o\
  Des.o\
  Idmap.o\
  libos.o\
  log.o\
  Md5.o\
  Rc4.o\
  stack.o\
  timer.o\
  ttlv.o\
  Xor.o\
  bootstrap.o\
  config.o\
  thttpd.o\
  utils.o
  

$(TARGET):$(OBJ)
	$(CC) $(OBJ) -o $(TARGET) -lm

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf *.o
