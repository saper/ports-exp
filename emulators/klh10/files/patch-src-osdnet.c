--- src/osdnet.c.orig	2020-04-09 20:25:09.602895000 +0200
+++ src/osdnet.c	2020-04-09 20:26:25.864356000 +0200
@@ -387,9 +387,9 @@
     int nents = 0;
     int nvary = 0;
 
-    fprintf(f, "Interface table: %ld bytes (%d entries if std addr len %d)\n",
+    fprintf(f, "Interface table: %ld bytes (%ld entries if std addr len %zd)\n",
 	    (long)ifc->ifc_len, ifc->ifc_len/sizeof(struct ifreq),
-	    (int)sizeof(struct sockaddr));
+	    sizeof(struct sockaddr));
 
     ifr = ifc->ifc_req;
     ifrend = (struct ifreq *)((char *)(ifc->ifc_req) + ifc->ifc_len);
