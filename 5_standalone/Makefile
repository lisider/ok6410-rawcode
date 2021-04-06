CROSS_COMPILE=arm-linux-

TARGET=standalone

CFLAG=-c -Iu-boot
PRECFLAG=-E -Iu-boot
LDFLAG=-e _start -Ttext 0x51000000

SDCARD=/dev/sdb



CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=${CROSS_COMPILE}objdump
FLASH=../0base/flash.sh

all: $(TARGET).dis $(TARGET).bin


$(TARGET).dis: $(TARGET)
	$(OBJDUMP) -D $(TARGET) > $(TARGET).dis

$(TARGET).bin: $(TARGET)
	$(OBJCOPY) -O binary $< $@

# start.o 必须在最前面
$(TARGET): start.o $(TARGET).o
	$(LD) $(LDFLAG) $? -o $@

%.o:%.S
	$(CC) $(CFLAG) $< -o $@
	$(CC) $(PRECFLAG) $< -o ${@:.o=.i}

%.o:%.c
	$(CC) $(CFLAG) $< -o $@
	$(CC) $(PRECFLAG) $< -o ${@:.o=.i}

flash:$(TARGET).bin $(SDCARD)
	#$(FLASH) ./$(TARGET).bin $(SDCARD)
	@if [ $(shell du -b $(TARGET).bin|cut -f1) -le 8192 ];then \
	$(FLASH) $(TARGET).bin $(SDCARD); \
	else \
	echo bin file is lager than 8192,size is $(shell du -b $(TARGET).bin|cut -f1); \
	fi \

clean:
	rm *.o $(TARGET) $(TARGET).bin $(TARGET).dis *.i -f
