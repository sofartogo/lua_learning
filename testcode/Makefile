all: capifd

capifd: capi_firstdemo.o
	gcc -o $@ $^ -llua -lm -ldl 

capi_firstdemo.o: capi_firstdemo.c
	gcc -c $^ -DOS_LINUX

.PHONY: clean

clean: 
	rm capi_firstdemo.o capi_firstdemo


