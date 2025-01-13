
SRCS  = main.c helper.c
OBJS := $(SRCS:.c=.o)

SDL2_CFLAGS != pkg-config --cflags sdl2
SDL2_LFLAGS != pkg-config --libs sdl2

CFLAGS := -std=c89 -Wall -Wpedantic -Wextra $(SDL2_CFLAGS) $(CFLAGS)
LFLAGS := $(SDL2_LFLAGS) $(LFLAGS)

CC = cc
LD = cc

DEPEND_MK = .depend.mk
BUILD_MK  = build.mk
CONFIG_MK = config.mk

# vim: noet
