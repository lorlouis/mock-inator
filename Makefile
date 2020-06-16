SOURCE	= main.c
HEADER	=
CC	 = gcc -std=c89 -ansi
FLAGS	 = -g -c -Wall
LFLAGS	 =
BUILD_DIR = build
MKDIR_P = mkdir -p

OUT	= mock
_OBJS = main.o
OBJS = $(patsubst %,$(BUILD_DIR)/%,$(_OBJS))


sdl: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

rel: $(OBJS)
	$(CC) -O3 $(OBJS) -o $(OUT) $(LFLAGS)

install:
	chmod +x mock
	cp mock /usr/bin/

remove:
	rm /usr/bin/mock

$(BUILD_DIR)/%.o: %.c
	$(MKDIR_P) $(BUILD_DIR)
	$(MKDIR_P) $(BUILD_DIR)/lib
	$(CC) $(FLAGS) $< -o $@


clean:
	rm -rf $(BUILD_DIR)
	rm -f $(OUT)
