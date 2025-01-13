
include config.mk


build:
	$(MAKE) -f $(BUILD_MK) $@

clean:
	$(MAKE) -f $(BUILD_MK) $@

install:
	@echo "not implimented $@"

uninstall:
	@echo "not implimented $@"


# end of file
