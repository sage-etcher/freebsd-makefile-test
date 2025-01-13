
include config.mk


build: test.out

depend: $(DEPEND_MK)
	$(MAKE) -f $(DEPEND_MK)

$(DEPEND_MK): $(SRCS)
	$(CC) -MM -MF $(DEPEND_MK) $(SRCS) $(CFLAGS)

clean:
	$(RM) $(DEPEND_MK)
	$(RM) *.o
	$(RM) *.out

debug:
	@echo "build debug:"

# linkage
test.out: depend $(OBJS)
	$(LD) -o $@ $(OBJS) $(LFLAGS)

# compile
%.o: %.c
	@echo "building me"
	$(CC) $(CFLAGS) -c -o $@ $<


# vim: noet
# end of file
