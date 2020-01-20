################################################################################
## qLibc
##
## Copyright (c) 2010-2015 Seungyoung Kim.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions are met:
##
## 1. Redistributions of source code must retain the above copyright notice,
##    this list of conditions and the following disclaimer.
## 2. Redistributions in binary form must reproduce the above copyright notice,
##    this list of conditions and the following disclaimer in the documentation
##    and/or other materials provided with the distribution.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
## AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
## IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
## ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
## LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
## CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
## SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
## INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
## CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
## ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
## POSSIBILITY OF SUCH DAMAGE.
################################################################################

prefix		= /usr/local
exec_prefix	= ${prefix}

## qlibc definitions
QLIBC_INCDIR		= ../include/qlibc
QLIBC_LIBDIR		= ../lib

## Compiler options
CC		= gcc
CFLAGS		= -g -O2 -Wall -Wstrict-prototypes -fPIC -g -O2
CPPFLAGS	=  -D_GNU_SOURCE -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -I/usr/include -I/usr/local/include -I${QLIBC_INCDIR}
RM		= /usr/bin/rm
DEPLIBS		= -lpthread

TARGETS1	= list listtbl hashtbl hasharr grow grow_obj queue stack \
			  config apacheconf
TARGETS2	= list listtbl hashtbl hasharr grow grow_obj queue stack
TARGETS		= ${TARGETS1}
LIBQLIBC	= ${QLIBC_LIBDIR}/libqlibc.a ${DEPLIBS}
LIBQLIBCEXT	= ${QLIBC_LIBDIR}/libqlibcext.a

## Main
all:	${TARGETS}

list: list.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ list.o ${LIBQLIBC}

listtbl: listtbl.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ listtbl.o ${LIBQLIBC}

hashtbl: hashtbl.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ hashtbl.o ${LIBQLIBC}

hasharr:	hasharr.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ hasharr.o ${LIBQLIBC}

grow: grow.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ grow.o ${LIBQLIBC}

grow_obj: grow_obj.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ grow_obj.o ${LIBQLIBC}

queue: queue.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ queue.o ${LIBQLIBC}

stack: stack.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ stack.o ${LIBQLIBC}

config: config.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ config.o ${LIBQLIBCEXT} ${LIBQLIBC}

apacheconf: apacheconf.o
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ apacheconf.o ${LIBQLIBCEXT} ${LIBQLIBC}

## Clear Module
clean:
	${RM} -f *.o ${TARGETS}

## Compile Module
.c.o:
	${CC} ${CFLAGS} ${CPPFLAGS} -c -o $@ $<

