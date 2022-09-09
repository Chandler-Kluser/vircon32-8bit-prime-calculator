# before building make sure /usr/local/DevTools/ is in your system PATH
CC	= compile
AS	= assemble
PCK	= packrom
PNG	= png2vircon
TIL	= tiled2vircon
WAV	= wav2vircon

# build directory
BUILD_DIR = build

# cflags
CFLAGS 	+= -Wall
CFLAGS 	+= -v

# include VirconDefinitions library (not necessary for now)
LIBS	+= /home/chandler/Documentos/ComputerSoftware/VirconDefinitions/build/

.PHONY: all clean

all: vircon32-8bit-prime-calculator.v32

main.asm:main.c build
	$(CC) $(CFLAGS) $< -o $(BUILD_DIR)/$@

vircon32-8bit-prime-calculator.vbin:main.asm build
	$(AS) $(BUILD_DIR)/$< -o $(BUILD_DIR)/$@

vircon32-8bit-prime-calculator.v32:vircon32-8bit-prime-calculator.xml vircon32-8bit-prime-calculator.vbin build
	$(PCK) $< -o $(BUILD_DIR)/$@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)