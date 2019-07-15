
# vim: ft=make noexpandtab

OBJECTS := msign.o

BINDIR_LINUX = ../bin/linux
BINDIR_MSP430G2553 = ../bin/msp430g2553

MD=mkdir -v -p

CFLAGS := -Wall -Werror

$(BINDIR_LINUX)/libmsign.a: OBJDIR := ../obj/linux

$(BINDIR_MSP430G2553)/libmsign.a: OBJDIR := ../obj/msp430g2553
$(BINDIR_MSP430G2553)/libmsign.a: AR := msp430-ar
$(BINDIR_MSP430G2553)/libmsign.a: CC := msp430-gcc
$(BINDIR_MSP430G2553)/libmsign.a: CFLAGS += \
	-mmcu=msp430g2553 \
	-g \
	-pg \
	-Os \
	-fno-builtin \
	-ffreestanding \
	-nostdlib

test_msign: LDFLAGS += $(shell pkg-config --libs check) -L../bin/linux -lmsign
test_msign: CFLAGS += -DCHECK -g -Wall -Werror
test_msign: OBJDIR := ../obj/linux

all: $(BINDIR_LINUX)/libmsign.a $(BINDIR_MSP430G2553)/libmsign.a

test_msign: $(BINDIR_LINUX)/libmsign.a ../obj/linux/check.o
	$(CC) -o $@ $(OBJDIR)/check.o $(LDFLAGS)

$(BINDIR_LINUX)/libmsign.a: $(addprefix ../obj/linux/,$(OBJECTS))
	$(MD) $(BINDIR_LINUX)
	$(AR) rcs $@ $^

$(BINDIR_MSP430G2553)/libmsign.a: $(addprefix ../obj/msp430g2553/,$(OBJECTS))
	$(MD) $(BINDIR_MSP430G2553)
	$(AR) rcs $@ $^

../obj/linux/%.o: $(notdir %.c)
	$(MD) $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

../obj/msp430g2553/%.o: $(notdir %.c)
	$(MD) $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -rf ../obj; \
	rm -f test_msign; \
	rm -rf ../bin

