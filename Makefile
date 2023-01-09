index.html: build_html.py template.html payload.bin
	python3 build_html.py template.html payload.bin index.html

payload.bin: payload.o
	arm-none-eabi-objcopy payload.o /dev/null --dump-section .text=payload.bin

payload.o: payload.s
	arm-none-eabi-as payload.s -o payload.o

clean:
	rm -f payload.o payload.bin index.html