--- src/udlconv.c.orig	2020-04-09 20:33:09.209286000 +0200
+++ src/udlconv.c	2020-04-09 20:33:41.332358000 +0200
@@ -160,6 +160,7 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h> /* For exit() */
 #include <ctype.h>
 #include <string.h>
 
@@ -238,6 +239,7 @@
 void outfile(struct filent *fe);
 
 
+int
 main(int argc, char *argv[])
 {
     register int i;
