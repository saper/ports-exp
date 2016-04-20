( ( cd `make -V STAGEDIR`/`make -V LOCALBASE` && find bin lib -type f -o -type l ) | sort | grep -v ^lib/node_modules/node-sass/vendor;
cat <<EOF
@dir lib/node_modules/node-sass/src/libsass
@dir lib/node_modules/node-sass/test/fixtures/spec
EOF
) > pkg-plist
