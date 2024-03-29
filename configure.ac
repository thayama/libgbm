#
#  Copyright 2005 Red Hat, Inc.
#
#  Permission to use, copy, modify, distribute, and sell this software and its
#  documentation for any purpose is hereby granted without fee, provided that
#  the above copyright notice appear in all copies and that both that
#  copyright notice and this permission notice appear in supporting
#  documentation, and that the name of Red Hat not be used in
#  advertising or publicity pertaining to distribution of the software without
#  specific, written prior permission.  Red Hat makes no
#  representations about the suitability of this software for any purpose.  It
#  is provided "as is" without express or implied warranty.
#
#  RED HAT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
#  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
#  EVENT SHALL RED HAT BE LIABLE FOR ANY SPECIAL, INDIRECT OR
#  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
#  DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
#  TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
#  PERFORMANCE OF THIS SOFTWARE.
#

# Initialize Autoconf
AC_PREREQ([2.60])
AC_INIT([libgbm], [21.1.1],
        [https://bugs.freedesktop.org/enter_bug.cgi?product=Mesa], [libgbm])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_HEADERS([config.h])

# Initialize Automake
AM_INIT_AUTOMAKE([foreign dist-bzip2])
#AM_MAINTAINER_MODE

# Initialize libtool
AC_PROG_LIBTOOL

# Check for dlopen
AC_SEARCH_LIBS([dlopen], [dl dld], [],
               [AC_MSG_FAILURE([Dynamic linking loader missing])])

# Obtain compiler/linker options for dependencies
PKG_CHECK_MODULES([LIBUDEV], [libudev])
PKG_CHECK_MODULES([LIBDRM], [libdrm])
PKG_CHECK_MODULES([LIBKMS], [libkms])
PKG_CHECK_MODULES([WAYLAND_KMS], [wayland-kms])

AC_CONFIG_FILES([Makefile gbm.pc])
AC_OUTPUT
