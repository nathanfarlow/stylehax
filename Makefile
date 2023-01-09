include $(DEVKITARM)/ds_rules

index.html: build_html.py template.html payload.bin
	python3 build_html.py template.html payload.bin index.html
	@rm payload.bin

payload.bin: *.c
	$(CC) -nostartfiles -nostdlib -DARM9 -I$(LIBNDS)/include *.c -o payload.elf -Os -fpie -Wall
	$(OBJCOPY) -O binary payload.elf payload.bin
	@rm payload.elf

# payload.bin: payload.s
# 	arm-none-eabi-as payload.s -o payload.o
# 	arm-none-eabi-objcopy -O binary payload.o payload.bin
# 	@rm -f payload.o

clean:
	@rm -f index.html