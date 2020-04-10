--- src/kn10pag.c.orig	2020-04-09 20:15:49.291122000 +0200
+++ src/kn10pag.c	2020-04-09 20:17:24.014180000 +0200
@@ -23,6 +23,7 @@
  */
 
 #include <stdio.h>
+#include <string.h> /* For memset() */
 
 #include "klh10.h"
 #include "osdsup.h"
