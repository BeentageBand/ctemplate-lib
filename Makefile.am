 ACLOCAL_AMFLAGS = -I m4 --install
# Libraries
nobase_include_HEADERS =  \
ctemplate-lib/hashmap/chashmap.c              \
ctemplate-lib/hashmap/chashmap.h              \
ctemplate-lib/hashmap/chashmap-internal.h     \
ctemplate-lib/hashmap/chashmap-int-template.h \
ctemplate-lib/hashmap/chashmap-template.h     \
ctemplate-lib/hashset/chashset.c              \
ctemplate-lib/hashset/chashset.h              \
ctemplate-lib/hashset/chashset-internal.h     \
ctemplate-lib/hashset/chashset-int-template.h \
ctemplate-lib/hashset/chashset-template.h     \
ctemplate-lib/hashset/bucket.c                \
ctemplate-lib/hashset/bucket.h                \
ctemplate-lib/map/cmap.c                      \
ctemplate-lib/map/cmap.h                      \
ctemplate-lib/map/cmap-internal.h             \
ctemplate-lib/map/cmap-int-template.h         \
ctemplate-lib/map/cmap-template.h             \
ctemplate-lib/map/pair.c                      \
ctemplate-lib/map/pair.h                      \
ctemplate-lib/queue/cqueue.c                  \
ctemplate-lib/queue/cqueue.h                  \
ctemplate-lib/queue/cqueue-internal.h         \
ctemplate-lib/queue/cqueue-int-template.h     \
ctemplate-lib/queue/cqueue-template.h         \
ctemplate-lib/set/cset.c                      \
ctemplate-lib/set/cset.h                      \
ctemplate-lib/set/cset-internal.h             \
ctemplate-lib/set/cset-int-template.h         \
ctemplate-lib/set/cset-template.h             \
ctemplate-lib/set/treenode.c                  \
ctemplate-lib/set/treenode.h                  \
ctemplate-lib/vector/cvector.c                \
ctemplate-lib/vector/cvector.h                \
ctemplate-lib/vector/cvector-internal.h       \
ctemplate-lib/vector/cvector-int-template.h   \
ctemplate-lib/vector/cvector-template.h   

# Unit Tests
check_PROGRAMS = unittest
unittest_SOURCES = \
tst/gtest-template.c \
tst/hashset-test.cc  \
tst/hashmap-test.cc  \
tst/map-test.cc      \
tst/set-test.cc      \
tst/queue-test.cc    \
tst/vector-test.cc   

unittest_CPPFLAGS = $(libgmock_main_CFLAGS)
unittest_LDADD = $(lib_LTLIBRARIES) $(libgmock_main_LIBS) $(libdir)/libcobject-1.0.a
unittest_LDFLAGS = -no-install

EXTRA_DIST = m4/NOTES
dist_doc = README.md LICENSE
