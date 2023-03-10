# detect operating system
UNAME := $(shell uname)
MKFL_DIR := makefiles

# set Makefile based on operating system
ifeq ($(UNAME), Darwin)
    include $(MKFL_DIR)/Makefile_MACOSX
else
    include $(MKFL_DIR)/Makefile_LINUX
endif
