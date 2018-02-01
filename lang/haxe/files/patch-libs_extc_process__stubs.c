--- libs/extc/process_stubs.c.orig	2017-05-05 06:20:02 UTC
+++ libs/extc/process_stubs.c
@@ -31,6 +31,7 @@
 #	include <windows.h>
 #else
 #	include <sys/types.h>
+#	include <signal.h>
 #	include <unistd.h>
 #	include <errno.h>
 #	include <string.h>
