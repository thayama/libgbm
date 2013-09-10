lib_LTLIBRARIES = libgbm.la

moduledir = $(libdir)/gbm
module_LTLIBRARIES = libgbm_kms.la

libgbm_la_SOURCES =	\
	gbm.c		\
	backend.c	\
	common.c

libgbm_la_LIBADD =	\
	@LIBUDEV_LIBS@

libgbm_la_CFLAGS =	\
	@LIBUDEV_CFLAGS@	\
	-D_OS_UNIX=1	\
	-DMODULEDIR='"$(libdir)/gbm"'

libgbm_la_LDFLAGS = -version-info 1:0:0

libgbm_kms_la_SOURCES =	\
	backend_kms.c

libgbm_kms_la_LIBADD =	\
	@LIBKMS_LIBS@	\
	@LIBDRM_LIBS@	\
	@WAYLAND_KMS_LIBS@

libgbm_kms_la_CFLAGS =	\
	@LIBKMS_CFLAGS@	\
	@LIBDRM_CFLAGS@	\
	@WAYLAND_KMS_CFLAGS@

libgbm_kms_la_LDFLAGS = -version-info 1:0:0

extdir = $(includedir)/gbm
ext_HEADERS =		\
	gbm.h		\
	gbmint.h	\
	common_drm.h	\
	common.h	\
	gbm_kmsint.h


pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gbm.pc
