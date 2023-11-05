TARGET = PSPHome
OBJS = main.o \
gfx.o \
player.o

CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -lstdc++ -std=c++14 -fno-exceptions -fno-rtti 
ASFLAGS = $(CFLAGS)

LIBS = -lmad -lpspaudiolib -lpspaudio -lpsppower -lpng -lz -lpspgu

# PSP stuff
BUILD_PRX = 1

#firmware version
PSP_FW_VERSION = 500
PSP_LARGE_MEMORY = 1

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = HomeApp
#PSP_EBOOT_ICON = ICON0.png

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak