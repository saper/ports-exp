--- scripts/install.js.orig	2015-03-31 13:31:43.000000000 +0000
+++ scripts/install.js	2015-03-31 13:31:46.000000000 +0000
@@ -4,7 +4,6 @@
 
 var fs = require('fs'),
     mkdir = require('mkdirp'),
-    npmconf = require('npmconf'),
     path = require('path'),
     request = require('request');
 
@@ -47,7 +46,7 @@
  */
 
 function applyProxy(options, cb) {
-  npmconf.load({}, function (er, conf) {
+  require('npmconf').load({}, function (er, conf) {
     var proxyUrl;
 
     if (!er) {
