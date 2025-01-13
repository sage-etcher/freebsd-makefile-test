
SRCS  = main.c helper.c
OBJS := $(SRCS:.c=.o)

SDL2_CFLAGS != pkg-config --cflags sdl2
SDL2_LFLAGS != pkg-config --libs sdl2

CFLAGS := -std=c89 -Wall -Wpedantic -Wextra $(SDL2_CFLAGS) $(CFLAGS)
LFLAGS := $(SDL2_LFLAGS) $(LFLAGS)

CC = cc
LD = cc

RM = rm -f
BEAR = bear --force-wrapper

DEPEND_MK = .depend.mk
BUILD_MK  = build.mk
CONFIG_MK = config.mk

debug:
	@echo "  CC           $(CC)"
	@echo "  LD           $(LD)"
	@echo "  RM           $(RM)"
	@echo "  BEAR         $(BEAR)"
	@echo "  SRCS         $(SRCS)"
	@echo "  OBJS         $(OBJS)"
	@echo "  SDL2_CFLAGS  $(SDL2_CFLAGS)"
	@echo "  SDL2_LFLAGS  $(SDL2_LFLAGS)"
	@echo "  CFLAGS       $(CFLAGS)"
	@echo "  LFLAGS       $(LFLAGS)"

# vim: noet
# end of file
