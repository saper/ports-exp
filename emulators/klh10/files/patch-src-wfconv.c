--- src/wfconv.c.orig	2020-04-09 20:29:19.306513000 +0200
+++ src/wfconv.c	2020-04-09 20:29:39.015184000 +0200
@@ -84,7 +84,7 @@
     w10_t w;
 
     if (argc != 2 || strlen(typestr = argv[1]) != 3) {
-	fprintf(stderr, usage);
+	fprintf(stderr, "%s", usage);
 	exit(1);
     }
     if (typestr[0] != '-'
