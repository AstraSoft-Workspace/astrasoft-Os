ISO_NAME = astrasoft.iso

# Paths
BOOTLOADER = ../bootloader/boot.asm
KERNEL = ../kernel/main.c ../drivers/screen.c ../drivers/keyboard.c

# Toolchain
CC = i386-elf-gcc
LD = i386-elf-ld
AS = nasm

CFLAGS = -m32 -ffreestanding -nostdlib -nostdinc -fno-builtin -fno-stack-protector

all: $(ISO_NAME)

boot.o:
	$(AS) -f elf32 $(BOOTLOADER) -o boot.o

kernel.o:
	$(CC) $(CFLAGS) -c ../kernel/main.c -o kernel.o
	$(CC) $(CFLAGS) -c ../drivers/screen.c -o screen.o
	$(CC) $(CFLAGS) -c ../drivers/keyboard.c -o keyboard.o

kernel.bin: boot.o kernel.o
	$(LD) -m elf_i386 -Ttext 0x1000 -o kernel.elf boot.o kernel.o screen.o keyboard.o
	$(LD) -m elf_i386 -Ttext 0x1000 -o kernel.bin --oformat binary boot.o kernel.o screen.o keyboard.o

iso: kernel.bin
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	echo 'set timeout=0\nset default=0\nmenuentry "AstraSoft OS" {\n multiboot /boot/kernel.bin\n boot\n}' > isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO_NAME) isodir

run: all
	qemu-system-i386 -cdrom $(ISO_NAME)

clean:
	rm -rf *.o *.bin *.elf isodir $(ISO_NAME)
