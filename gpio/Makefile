TARGETS=	RFon BPon PHWL-GPIO-00A0.dtbo
all:	$(TARGETS)

RFon:	RFon.o
	gcc -o RFon RFon.c -lgpiod

PHWL-GPIO-00A0.dtbo:	PHWL-GPIO.dts
	dtc -O dtb -o PHWL-GPIO-00A0.dtbo -b 0 -@ PHWL-GPIO.dts

install:	PHWL-GPIO-00A0.dtbo
	sudo cp PHWL-GPIO-00A0.dtbo /lib/firmware
	sudo cp uEnv.txt /boot

clean:	
	-rm -f *.o *.dtbo RFon BPon
