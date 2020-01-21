APP     := structures

OBJDIR  := obj
SRC_DIR := src
INC_DIR := inc
QLIBC_INCLUDES := lib/qlibc/include/
QLIBC_LIBRARY_PATH := -Llib/qlibc/lib
QLIBC_LIBS := -lqlibc -lqlibcext
PTHREAD_LIBS = -lpthread
SRCS    := $(shell find $(SRC_DIR) -name '*.c')
SRCDIRS := $(shell find $(SRC_DIR) -name '*.c' -exec dirname {} \; | uniq)
OBJS    := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
DEPS    := $(patsubst %.c,$(OBJDIR)/%.d,$(SRCS))

DEBUG    := -g

INCLUDES := -I./$(INC_DIR) -I./$(QLIBC_INCLUDES)
CFLAGS   := $(DEBUG) -Wall -Wpedantic $(INCLUDES) -c
LDFLAGS  := -Wl,-rpath,lib/qlibc/lib $(QLIBC_LIBRARY_PATH)
LIBS     := $(QLIBC_LIBS) $(PTHREAD_LIBS)

DEPENDS  = -MT $@ -MD -MP -MF $(subst .o,.d,$@)

SHELL    = /bin/sh

.PHONY: all clean distclean


all: buildrepo $(APP)

$(APP): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEPENDS) $< -o $@

clean:
	$(RM) -r $(OBJDIR)

distclean: clean
	$(RM) $(APP)

buildrepo:
	@$(call make-repo)

define make-repo
   for dir in $(SRCDIRS); \
   do \
    mkdir -p $(OBJDIR)/$$dir; \
   done
endef

ifneq "$(MAKECMDGOALS)" "distclean"
ifneq "$(MAKECMDGOALS)" "clean"
-include $(DEPS)
endif
endif
