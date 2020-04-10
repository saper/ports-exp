--- src/wxtest.c.orig	2020-04-09 20:31:33.596139000 +0200
+++ src/wxtest.c	2020-04-09 20:32:46.641995000 +0200
@@ -36,6 +36,7 @@
 #include <stdio.h>
 #include <limits.h>
 #include <stdlib.h>
+#include <string.h> /* For memset(), memcmp() */
 
 #include "rcsid.h"
 #include "word10.h"
@@ -65,7 +66,11 @@
 int txtest(void);
 int tinttypes(void);
 int tmasks(void);
+int testfmt(void);
+int test32(void);
+int test36(void);
 
+int
 main(int argc, char **argv)
 {
     char *cp;
