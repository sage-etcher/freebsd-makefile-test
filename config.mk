

SRCS  = main.c helper.c
OBJS := $(SRCS:.c=.o)

SDL2_CFLAGS != pkg-config --cflags sdl2
SDL2_LFLAGS != pkg-config --libs sdl2

CFLAGS := -std=c11 -Wall -Wpedantic -Wextra $(SDL2_CFLAGS) $(CFLAGS)
LFLAGS := $(SDL2_LFLAGS) $(LFLAGS)

CC = cc
LD = cc

RM = rm -f
BEAR = bear --force-wrapper
BEAR_OUTPUT = compile_commands.json

MAIN_MAKEFILE = makefile
CONFIG_MK = config.mk
BUILD_MK  = build.mk
DEPEND_MK = .depend.mk

BUILD_MAKEFILE_LIST = $(MAIN_MAKEFILE) $(BUILD_MK) $(CONFIG_MK)

# vim: noet
# end of file
