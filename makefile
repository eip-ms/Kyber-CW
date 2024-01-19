
# Target file name (without extension).
# This is the base name of the compiled .hex file.

#include $(TARGET)/Makefile.inc
SRC += main.c
#HEADER = /home/ms/Desktop/phd/implementations/kyber-c/kem.h 
# -----------------------------------------------------------------------------

ifeq ($(CRYPTO_OPTIONS),)
CRYPTO_OPTIONS = NONE
endif

CDEFS=-DTARGET=$(TARGET)

${info Building for platform ${PLATFORM} with CRYPTO_TARGET=$(CRYPTO_TARGET)}

FIRMWAREPATH = /home/ms/chipwhisperer/hardware/victims/firmware
include $(FIRMWAREPATH)/Makefile.inc


