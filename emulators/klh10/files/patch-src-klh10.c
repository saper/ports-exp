--- src/klh10.c.orig	2001-11-10 22:29:07.000000000 +0100
+++ src/klh10.c	2020-04-09 21:00:02.185958000 +0200
@@ -349,6 +349,7 @@
 KEYSEND
 
 static void error(char *, ...), syserr(int, char *, ...);
+static void fc_quit_confirmed();
 
 jmp_buf errenv;
 
@@ -495,13 +496,13 @@
     cmdinit(&command, cmdprompt, cmdbuf, sizeof(cmdbuf));
     for (;;) {				/* Loop here... */
 	if (!cmdlsetup(&command)) {	/* Read typein command line */
-	    printf("\n");		/* If failed, try again */
-	    continue;
+	    break;
 	}
 	if (fedevchkf)			/* If checking for dev attn, */
 	    fedevchkf = dev_dpchk_ctl(TRUE);	/* do so here */
 	(void) cmdexec(&command);	/* Parse and execute */
     }
+    fc_quit_confirmed();
 }
 
 void
@@ -513,6 +514,19 @@
 
 
 void
+fc_quit_confirmed(void)
+{
+    printf("Shutting down...");
+
+    dev_term();		/* Power off all devices that might need it */
+
+    mem_term();		/* Flush memory in case shared */
+
+    printf("Bye!\n");
+    os_exit(0);
+}
+
+void
 fc_quit(struct cmd_s *cm)
 {
     printf("Are you sure you want to quit? [Confirm]");
@@ -527,14 +541,7 @@
     default:		/* Anything else prevents quit */
 	return;
     }
-    printf("Shutting down...");
-
-    dev_term();		/* Power off all devices that might need it */
-
-    mem_term();		/* Flush memory in case shared */
-
-    printf("Bye!\n");
-    os_exit(0);
+    fc_quit_confirmed();
 }
 
 /* FE_SHUTDOWN - Attempt to bring down PDP-10 OS and quit emulator as
