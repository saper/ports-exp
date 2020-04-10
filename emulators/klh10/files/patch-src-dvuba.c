--- src/dvuba.c.orig	2020-04-09 20:21:19.498344000 +0200
+++ src/dvuba.c	2020-04-09 20:21:49.455996000 +0200
@@ -45,6 +45,7 @@
 #if KLH10_CPU_KS	/* Moby conditional for entire file */
 
 #include <stdio.h>	/* For stderr if buggy */
+#include <string.h>	/* For memset() */
 
 #include "kn10def.h"
 #include "kn10ops.h"
