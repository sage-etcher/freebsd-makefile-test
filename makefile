
include config.mk


# build + track
build: depend
	$(MAKE) -f $(BUILD_MK) $@

depend: $(DEPEND_MK)

$(DEPEND_MK): $(SRCS)
	$(CC) -MM -MF $(DEPEND_MK) $(SRCS) $(CFLAGS)


# clean
clean:
	$(RM) $(DEPEND_MK)
	$(MAKE) -f $(BUILD_MK) $@

fullclean: clean
	$(RM) $(BEAR_OUTPUT)


# install
install:
	@echo "not implimented $@"

uninstall:
	@echo "not implimented $@"


# bear
BUILD_MAKEFILE_LIST = $(MAIN_MAKEFILE) $(BUILD_MK) $(CONFIG_MK)

bear: $(BEAR_OUTPUT)

$(BEAR_OUTPUT): $(SRCS) $(BUILD_MAKEFILE_LIST)
	$(MAKE) -f $(BUILD_MK) clean
	$(BEAR) -- $(MAKE) -f $(MAIN_MAKEFILE) build


# logging
debug-variables:
	@echo "Variables:"
	@echo "  CC           $(CC)"
	@echo "  LD           $(LD)"
	@echo "  RM           $(RM)"
	@echo "  BEAR         $(BEAR)"
	@echo "  BEAR_OUTPUT  $(BEAR_OUTPUT)"
	@echo "  SRCS         $(SRCS)"
	@echo "  OBJS         $(OBJS)"
	@echo "  SDL2_CFLAGS  $(SDL2_CFLAGS)"
	@echo "  SDL2_LFLAGS  $(SDL2_LFLAGS)"
	@echo "  CFLAGS       $(CFLAGS)"
	@echo "  LFLAGS       $(LFLAGS)"
	@echo ""

debug-build:
	$(MAKE) -f $(BUILD_MK) debug-build

debug: debug-variables debug-build


# vim: noet
# end of file
