 ACLOCAL_AMFLAGS = -I m4 --install
# Libraries
nobase_include_HEADERS =  \
ctemplate-lib/cqueue.c               \
ctemplate-lib/cqueue.h               \
ctemplate-lib/cqueue-internal.h      \
ctemplate-lib/cqueue-int-template.h  \
ctemplate-lib/cqueue-template.h      \
ctemplate-lib/cvector.c              \
ctemplate-lib/cvector.h              \
ctemplate-lib/cvector-internal.h     \
ctemplate-lib/cvector-int-template.h \
ctemplate-lib/cvector-template.h

# Unit Tests
check_PROGRAMS = unittest
unittest_SOURCES = \
tst/gtest-template.c \
tst/vector-test.cc   \
tst/queue-test.cc

unittest_CPPFLAGS = $(libgmock_main_CFLAGS)
unittest_LDADD = $(lib_LTLIBRARIES) $(libgmock_main_LIBS) $(libdir)/libcobject-1.0.a
unittest_LDFLAGS = -no-install

EXTRA_DIST = m4/NOTES
dist_doc = README.md LICENSE