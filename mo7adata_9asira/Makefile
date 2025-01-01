NAMEC = client
NAMES = server
SRCC = client.c
SRCS = server.c
OBJC = ${SRCC:%.c=%.o}
OBJS = ${SRCS:%.c=%.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) minitalk_utils.c -o $(NAMEC)

$(NAMES): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) minitalk_utils.c -o $(NAMES)

clean:
	$(RM) $(OBJC)
	$(RM) $(OBJS)
	$(RM) minitalk_utils.o

fclean: clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)

re: fclean all