#writer is made from writer.c
#check if the variable CROSS_COMPILE is not defined
#then the compiler is the native compiler -> default value of CC variable
#if the variable is defined and specified as aarch64-none-linux-gnu-, then CC = 
writer: writer.c
ifdef CROSS_COMPILE
ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	$(CROSS_COMPILE)gcc $< -o $@
else
	@echo "CROSS_COMPILE has beed defined but defined as: $(CROSS_COMPILE)"
	@echo "Nothing happens"
endif
else
	@echo "CROSS_COMPILE is not defined, use the native compiler"
	$(CC) $< -o $@
endif


clean:
	rm -f writer