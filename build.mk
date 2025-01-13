
include config.mk


build: test.out

depend: $(DEPEND_MK)
	$(MAKE) -f $(DEPEND_MK)

$(DEPEND_MK): $(SRCS)
	$(CC) -MM -MF $(DEPEND_MK) $(SRCS) $(CFLAGS)

clean:
	rm -f $(DEPEND_MK)
	rm -f *.o
	rm -f *.out

debug:
	@echo "depend = '$(DEPEND_MK)'"

# linkage
test.out: depend $(OBJS)
	$(LD) -o $@ $(OBJS) $(LFLAGS)

# compile
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


# vim: noet
