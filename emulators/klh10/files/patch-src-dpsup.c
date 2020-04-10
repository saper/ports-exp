--- src/dpsup.c.orig	2020-04-09 20:22:56.769283000 +0200
+++ src/dpsup.c	2020-04-09 20:23:19.435813000 +0200
@@ -34,6 +34,7 @@
 #if KLH10_DEV_DP		/* Moby conditional for entire file */
 
 #include <stdio.h>
+#include <stdlib.h>		/* For exit() */
 #include <string.h>		/* For strerror() if present */
 
 #include "dpsup.h"
