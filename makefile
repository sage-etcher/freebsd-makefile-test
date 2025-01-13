

build: depend
	$(MAKE) -f $(BUILD_MK) $@

bear:
	$(MAKE) -f $(BUILD_MK) clean
	$(BEAR) -- $(MAKE) -f $(BUILD_MK) build

depend: $(DEPEND_MK)

$(DEPEND_MK): $(SRCS)
	$(CC) -MM -MF $(DEPEND_MK) $(SRCS) $(CFLAGS)

fullclean: clean
	$(RM) $(BEAR_OUTPUT)

clean:
	$(RM) $(DEPEND_MK)
	$(MAKE) -f $(BUILD_MK) $@

install:
	@echo "not implimented $@"

uninstall:
	@echo "not implimented $@"

debug:
	$(MAKE) -f $(CONFIG_MK) debug-config
	$(MAKE) -f $(BUILD_MK) debug-build


include config.mk
# vim: noet
# end of file
