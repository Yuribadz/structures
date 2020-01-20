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

## Utilities
AR		= /usr/bin/ar
ARFLAGS		= -rc
CHMOD		= /usr/bin/chmod
INSTALL		= /usr/bin/install -c
INSTALL_DATA	= ${INSTALL} -m 644
LN_S		= ln -s
MKDIR_P		= /usr/bin/mkdir -p
RMDIR		= rmdir
RANLIB		= ranlib
RM		= /usr/bin/rm

## Install directories
INST_INCDIR	= ${prefix}/include
INST_LIBDIR	= ${exec_prefix}/lib

## Custom definitions
BUILD_TARGETS	= qlibc qlibcext
INSTALL_TARGETS	= install-qlibc install-qlibcext

## qlibc definitions
QLIBC_INCDIR		= ../include/qlibc
QLIBC_LIBDIR		= ../lib
QLIBC_LIBNAME		= libqlibc.a
QLIBC_SLIBNAME		= libqlibc.so
QLIBC_SLIBVERSION	= 2
QLIBC_SLIBREALNAME	= ${QLIBC_SLIBNAME}.${QLIBC_SLIBVERSION}

## qlibcext definitions
QLIBCEXT_LIBNAME	= libqlibcext.a
QLIBCEXT_SLIBNAME	= libqlibcext.so
QLIBCEXT_SLIBVERSION	= 2
QLIBCEXT_SLIBREALNAME	= ${QLIBCEXT_SLIBNAME}.${QLIBCEXT_SLIBVERSION}

## Objects List
QLIBC_OBJS	= \
		containers/qtreetbl.o		\
		containers/qhashtbl.o		\
		containers/qhasharr.o		\
		containers/qlisttbl.o		\
		containers/qlist.o		\
		containers/qvector.o		\
		containers/qqueue.o		\
		containers/qstack.o		\
		containers/qgrow.o		\
						\
		utilities/qcount.o		\
		utilities/qencode.o		\
		utilities/qfile.o		\
		utilities/qhash.o		\
		utilities/qio.o			\
		utilities/qsocket.o		\
		utilities/qstring.o		\
		utilities/qsystem.o		\
		utilities/qtime.o		\
						\
		ipc/qsem.o			\
		ipc/qshm.o			\
						\
		internal/qinternal.o		\
		internal/md5/md5c.o

QLIBCEXT_OBJS	= \
		extensions/qconfig.o		\
		extensions/qaconf.o		\
		extensions/qlog.o		\
		extensions/qhttpclient.o	\
		extensions/qdatabase.o		\
		extensions/qtokenbucket.o

## Which compiler & options for release
CC		= gcc
CFLAGS		= -g -O2 -Wall -Wstrict-prototypes -fPIC -g -O2
CPPFLAGS	=  -D_GNU_SOURCE -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -I/usr/include -I/usr/local/include -I${QLIBC_INCDIR} -I./internal

## Make Library
all: ${BUILD_TARGETS}

qlibc: ${QLIBC_OBJS}
	${AR} ${ARFLAGS} ${QLIBC_LIBDIR}/${QLIBC_LIBNAME} ${QLIBC_OBJS}
	${RANLIB} ${QLIBC_LIBDIR}/${QLIBC_LIBNAME}
	${CC} -shared -Wl,-soname,${QLIBC_SLIBREALNAME} -o ${QLIBC_LIBDIR}/${QLIBC_SLIBREALNAME} ${QLIBC_OBJS}
	( cd ${QLIBC_LIBDIR}; ${LN_S} -f ${QLIBC_SLIBREALNAME} ${QLIBC_SLIBNAME} )

qlibcext: ${QLIBCEXT_OBJS}
	${AR} ${ARFLAGS} ${QLIBC_LIBDIR}/${QLIBCEXT_LIBNAME} ${QLIBCEXT_OBJS}
	${RANLIB} ${QLIBC_LIBDIR}/${QLIBCEXT_LIBNAME}
	${CC} -shared -Wl,-soname,${QLIBCEXT_SLIBREALNAME} -o ${QLIBC_LIBDIR}/${QLIBCEXT_SLIBREALNAME} ${QLIBCEXT_OBJS}
	( cd ${QLIBC_LIBDIR}; ${LN_S} -f ${QLIBCEXT_SLIBREALNAME} ${QLIBCEXT_SLIBNAME} )

install: ${INSTALL_TARGETS}

install-qlibc: qlibc
	${MKDIR_P} $(DESTDIR)/${INST_INCDIR}/qlibc
	${INSTALL_DATA} ${QLIBC_INCDIR}/qlibc.h $(DESTDIR)/${INST_INCDIR}/qlibc/qlibc.h
	${MKDIR_P} $(DESTDIR)/${INST_INCDIR}/qlibc/containers/
	${INSTALL_DATA} ${QLIBC_INCDIR}/containers/qtreetbl.h $(DESTDIR)/${INST_INCDIR}/qlibc/containers/qtreetbl.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/containers/qhashtbl.h $(DESTDIR)/${INST_INCDIR}/qlibc/containers/qhashtbl.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/containers/qhasharr.h $(DESTDIR)/${INST_INCDIR}/qlibc/containers/qhasharr.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/containers/qlisttbl.h $(DESTDIR)/${INST_INCDIR}/qlibc/containers/qlisttbl.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/containers/qlist.h $(DESTDIR)/${INST_INCDIR}/qlibc/containers/qlist.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/containers/qvector.h $(DESTDIR)/${INST_INCDIR}/qlibc/containers/qvector.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/containers/qqueue.h $(DESTDIR)/${INST_INCDIR}/qlibc/containers/qqueue.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/containers/qstack.h $(DESTDIR)/${INST_INCDIR}/qlibc/containers/qstack.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/containers/qgrow.h $(DESTDIR)/${INST_INCDIR}/qlibc/containers/qgrow.h
	${MKDIR_P} $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/
	${INSTALL_DATA} ${QLIBC_INCDIR}/utilities/qcount.h $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/qcount.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/utilities/qencode.h $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/qencode.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/utilities/qfile.h $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/qfile.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/utilities/qhash.h $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/qhash.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/utilities/qio.h $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/qio.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/utilities/qsocket.h $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/qsocket.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/utilities/qstring.h $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/qstring.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/utilities/qsystem.h $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/qsystem.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/utilities/qtime.h $(DESTDIR)/${INST_INCDIR}/qlibc/utilities/qtime.h
	${MKDIR_P} $(DESTDIR)/${INST_INCDIR}/qlibc/ipc/
	${INSTALL_DATA} ${QLIBC_INCDIR}/ipc/qsem.h $(DESTDIR)/${INST_INCDIR}/qlibc/ipc/qsem.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/ipc/qshm.h $(DESTDIR)/${INST_INCDIR}/qlibc/ipc/qshm.h
	${MKDIR_P} $(DESTDIR)/${INST_LIBDIR}
	${INSTALL_DATA} ${QLIBC_LIBDIR}/${QLIBC_LIBNAME} $(DESTDIR)/${INST_LIBDIR}/${QLIBC_LIBNAME}
	${INSTALL_DATA} ${QLIBC_LIBDIR}/${QLIBC_SLIBREALNAME} $(DESTDIR)/${INST_LIBDIR}/${QLIBC_SLIBREALNAME}
	( cd $(DESTDIR)/${INST_LIBDIR}; ${LN_S} -f ${QLIBC_SLIBREALNAME} ${QLIBC_SLIBNAME} )

uninstall-qlibc:
	${RM} -f $(DESTDIR)/${INST_INCDIR}/qlibc/qlibc.h
	${RM} -rf $(DESTDIR)/${INST_INCDIR}/qlibc/containers
	${RM} -rf $(DESTDIR)/${INST_INCDIR}/qlibc/utilities
	${RM} -rf $(DESTDIR)/${INST_INCDIR}/qlibc/ipc
	${RM} -f $(DESTDIR)/${INST_LIBDIR}/${QLIBC_LIBNAME}
	${RM} -f $(DESTDIR)/${INST_LIBDIR}/${QLIBC_SLIBREALNAME}
	${RM} -f $(DESTDIR)/${INST_LIBDIR}/${QLIBC_SLIBNAME}

install-qlibcext: qlibcext
	${MKDIR_P} $(DESTDIR)/${INST_INCDIR}/qlibc
	${INSTALL_DATA} ${QLIBC_INCDIR}/qlibcext.h $(DESTDIR)/${INST_INCDIR}/qlibc/qlibcext.h
	${MKDIR_P} $(DESTDIR)/${INST_INCDIR}/qlibc/extensions/
	${INSTALL_DATA} ${QLIBC_INCDIR}/extensions/qconfig.h $(DESTDIR)/${INST_INCDIR}/qlibc/extensions/qconfig.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/extensions/qaconf.h $(DESTDIR)/${INST_INCDIR}/qlibc/extensions/qaconf.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/extensions/qlog.h $(DESTDIR)/${INST_INCDIR}/qlibc/extensions/qlog.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/extensions/qhttpclient.h $(DESTDIR)/${INST_INCDIR}/qlibc/extensions/qhttpclient.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/extensions/qdatabase.h $(DESTDIR)/${INST_INCDIR}/qlibc/extensions/qdatabase.h
	${INSTALL_DATA} ${QLIBC_INCDIR}/extensions/qtokenbucket.h $(DESTDIR)/${INST_INCDIR}/qlibc/extensions/qtokenbucket.h
	${MKDIR_P} $(DESTDIR)/${INST_LIBDIR}
	${INSTALL_DATA} ${QLIBC_LIBDIR}/${QLIBCEXT_LIBNAME} $(DESTDIR)/${INST_LIBDIR}/${QLIBCEXT_LIBNAME}
	${INSTALL_DATA} ${QLIBC_LIBDIR}/${QLIBCEXT_SLIBREALNAME} $(DESTDIR)/${INST_LIBDIR}/${QLIBCEXT_SLIBREALNAME}
	( cd $(DESTDIR)/${INST_LIBDIR}; ${LN_S} -f ${QLIBCEXT_SLIBREALNAME} ${QLIBCEXT_SLIBNAME} )

uninstall-qlibcext:
	${RM} -f $(DESTDIR)/${INST_INCDIR}/qlibc/qlibcext.h
	${RM} -rf $(DESTDIR)/${INST_INCDIR}/qlibc/extensions
	${RM} -f $(DESTDIR)/${INST_LIBDIR}/${QLIBCEXT_LIBNAME}
	${RM} -f $(DESTDIR)/${INST_LIBDIR}/${QLIBCEXT_SLIBREALNAME}
	${RM} -f $(DESTDIR)/${INST_LIBDIR}/${QLIBCEXT_SLIBNAME}

deinstall: uninstall
uninstall: uninstall-qlibc uninstall-qlibcext
	${RMDIR} $(DESTDIR)/${INST_INCDIR}/qlibc

clean:
	${RM} -f ${QLIBC_OBJS}
	( cd ${QLIBC_LIBDIR}; ${RM} -f ${QLIBC_LIBNAME} ${QLIBC_SLIBREALNAME} ${QLIBC_SLIBNAME} )
	${RM} -f ${QLIBCEXT_OBJS}
	( cd ${QLIBC_LIBDIR}; ${RM} -f ${QLIBCEXT_LIBNAME} ${QLIBCEXT_SLIBREALNAME} ${QLIBCEXT_SLIBNAME} )

doc:
	doxygen doxygen.conf

cleandoc:
	${RM} -rf ../doc/html

test:
	(cd ../tests; make clean test)

## Compile
.c.o:
	${CC} ${CFLAGS} ${CPPFLAGS} -c -o $@ $<

