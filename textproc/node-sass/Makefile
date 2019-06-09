# Created by: Marcin Cieslak <saper@SAPER.INFO>
# $FreeBSD$

PORTNAME=	node-sass
PORTVERSION=	4.12.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc www

MAINTAINER=	saper@SAPER.INFO
COMMENT=	C/C++ Sass compiler bindings for nodejs

LICENSE=	MIT

LIB_DEPENDS=	libsass.so.1:textproc/libsass35
FETCH_DEPENDS=	npm>=0:www/npm
BUILD_DEPENDS=	npm>=0:www/npm
RUN_DEPENDS=	npm>=0:www/npm

USES=		compiler:c++11-lib gmake python:2.7 shebangfix

GH_ACCOUNT=	sass

USE_GITHUB=	yes

MAKE_ENV+=	CC.host=${CC} CXX.host=${CXX} LINK.host=${CXX} LINK.target=${CXX} V=1
MAKE_ENV+=	SKIP_SASS_BINARY_DOWNLOAD_FOR_CI=yes
MAKE_ENV+=	LIBSASS_EXT=yes CXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=	LIBSASS_LIBRARY=${LOCALBASE}/lib/libsass_pic.a
MAKE_ENV+=	LIBSASS_CFLAGS=-I${LOCALBASE}/include
MAKE_ENV+=	NPM_CONFIG_CACHE=${DISTDIR}/npm NPM_CONFIG_UNSAFE_PERM=1
MAKE_ENV+=	NPM_CONFIG_NODEDIR=${LOCALBASE}/include/node

MANDIRS+=	${PREFIX}/lib/node_modules/node-sass/node_modules/sshpk/man/man1

SHEBANG_GLOB=	lib/node_modules/${PORTNAME}/node_modules/node-gyp/gyp -name '*.py'

DIST_NPM_CACHE=	${DISTDIR}/npm
BUILD_NPM_CACHE=	${WRKDIR}/npm

.include <bsd.port.pre.mk>
.if ${COMPILER_TYPE} == clang
MAKE_ENV+=	GYP_DEFINES=clang=1
.endif

fetch-specials:
	${MKDIR} ${DISTDIR}/${PORTNAME}
	${MKDIR} ${DIST_NPM_CACHE}
	if [ ! -f ${DISTDIR}/${PORTNAME}/package-lock.json ]; then ${CP} ${FILESDIR}/package-lock.json ${DISTDIR}/${PORTNAME}; \
		${CP} ${FILESDIR}/package.json ${DISTDIR}/${PORTNAME}; \
		(cd ${DISTDIR}/${PORTNAME} && ${SETENV} NPM_CONFIG_CACHE=${DIST_NPM_CACHE} npm install --ignore-scripts --production) \
	fi

post-extract:
	(cd ${DISTDIR}/${PORTNAME} && find node_modules | ${PAX} -rw ${WRKSRC})
	${MKDIR} ${BUILD_NPM_CACHE}
	(cd ${DIST_NPM_CACHE} && find . | ${PAX} -rw ${BUILD_NPM_CACHE})

do-build:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} NPM_CONFIG_CACHE=${BUILD_NPM_CACHE} npm install --nodedir=${LOCALBASE} --production)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	(cd ${WRKSRC} && ${FIND} . -type f -o -type l | \
		${GREP} -v '^./build' | \
		${GREP} -v 'libsass/script' | \
		${GREP} -v 'gyp/samples' | \
		${GREP} -v 'node-gyp/test/docker.sh' | \
		${PAX} -rw ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME})
	(cd ${STAGEDIR}${PREFIX} && ${FIND} lib/node_modules/${PORTNAME}/vendor -type f >> ${TMPPLIST} )
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/vendor/*/binding.node 
	${LN} -s ../lib/node_modules/node-sass/bin/node-sass ${STAGEDIR}${PREFIX}/bin/node-sass

test:
	(cd ${WRKSRC} && npm test)

.include <bsd.port.post.mk>
