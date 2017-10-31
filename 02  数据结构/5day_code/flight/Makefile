CC = gcc
SUBDIRS = flight main obj

OBJS = flight.o main.o
BIN = flight
OBJS_DIR = obj
BIN_DIR = myflight

export CC OBJS BIN OBJS_DIR BIN_DIR

all:CHECK_DIR $(SUBDIRS)

CHECK_DIR:
	mkdir -p $(BIN_DIR)

$(SUBDIRS):ECHO
	make -C $@
ECHO:
	@echo $(SUBDIRS)
	@echo begin compile
clean:
	@$(RM) $(OBJS_DIR)/*.o
	@rm -rf $(BIN_DIR)
