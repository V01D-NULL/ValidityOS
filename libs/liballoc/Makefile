include ../../build-util/flags.mk

TARGET := liballoc.a

CFILES	 := $(shell find ./ -type f -name '*.c')
ASMFILES := $(shell find ./ -type f -name '*.s')
OBJ_C    := $(CFILES:.c=.o)
OBJ_ASM  := $(ASMFILES:.s=.o)
OBJ		 := $(OBJ_C) $(OBJ_ASM)

.PHONY: all clean

CFLAGS := $(CFLAGS) \
			-I ../../kernel/ \
			-I ../

all: $(TARGET)

$(TARGET): $(OBJ)
	@printf "[liballoc @ AR] Archiving object files\n";
	$(AR) rcs $@ $^

%.o: %.c
	@printf "[liballoc @ CC] [ $< ]\n";
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	@printf "[liballoc @ AS] [ $< ]\n";
	$(AS) $(ASMFLAGS) $< -o $@

clean:
	@rm -rf $(TARGET) $(OBJ)
