#writer is made from writer.c
#check if the variable CROSS_COMPILE is not defined
#then the compiler is the native compiler -> default value of CC variable
#if the variable is defined and specified as aarch64-none-linux-gnu-, then CC = 
ifdef CROSS_COMPILE
	ifeq ( $(CROSS_COMPILE), aarch64-none-linux-gnu-)
		CC = $(CROSS_COMPILE)
	endif
endif
writer: writer.c

clean:
	rm -f writer