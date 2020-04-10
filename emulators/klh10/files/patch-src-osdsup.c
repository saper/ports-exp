--- src/osdsup.c.orig	2020-04-09 20:14:58.707902000 +0200
+++ src/osdsup.c	2020-04-09 20:15:23.746873000 +0200
@@ -41,6 +41,7 @@
 #  include <sys/stat.h>
 #  include <sys/file.h>
 
+#  include <stdlib.h>           /* For exit() */
 #  include <signal.h>
 #  include <errno.h>
 #  include <time.h>		/* For struct tm, localtime() */
