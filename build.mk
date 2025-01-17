
include config.mk


build: test.out

clean:
	$(RM) *.o
	$(RM) *.out

debug-build:
	@echo "build.mk:"
	@echo "  [nothing here]"
	@echo ""

# linkage
test.out: $(OBJS) $(BUILD_MAKEFILE_LIST)
	$(LD) -o $@ $(OBJS) $(LFLAGS)

# compile
%.o: %.c
	@echo "building me"
	$(CC) $(CFLAGS) -c -o $@ $<


# include DEPEND_MK if it exists, but dont worry if it doesn't
DEPEND_EXIST != test $(DEPEND_MK) || echo "$?"
.if $(DEPEND_EXIST)
	include $(DEPEND_MK)
.endif

# vim: noet
# end of file
