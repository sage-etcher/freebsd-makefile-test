
include config.mk


build:
	$(MAKE) -f $(BUILD_MK) $@

bear:
	$(MAKE) -f $(BUILD_MK) clean
	$(BEAR) -- $(MAKE) -f $(BUILD_MK) build

clean:
	$(MAKE) -f $(BUILD_MK) $@

install:
	@echo "not implimented $@"

uninstall:
	@echo "not implimented $@"


# vim: noet
# end of file
