# Created by: Marcin Cieslak <saper@SAPER.INFO>
# $FreeBSD$

PORTNAME=	node-sass
PORTVERSION=	3.4.0.b1
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	textproc www

MAINTAINER=	saper@SAPER.INFO
COMMENT=	C/C++ Sass compiler bindings for nodejs

LICENSE=	MIT

FETCH_DEPENDS=	npm>=0:${PORTSDIR}/www/npm
BUILD_DEPENDS=	npm>=0:${PORTSDIR}/www/npm \
		libsass>3.2.5:${PORTSDIR}/textproc/libsass
RUN_DEPENDS=	npm>=0:${PORTSDIR}/www/npm

USES=		compiler:c++11-lib python:2.7 gmake:lite

GH_ACCOUNT=	sass
GH_TAGNAME=	v3.4.0-beta1

USE_GITHUB=	yes

MAKE_ENV+=	CC.host=${CC} CXX.host=${CXX} LINK.host=${CXX} LINK.target=${CXX} V=1
MAKE_ENV+=	SKIP_SASS_BINARY_DOWNLOAD_FOR_CI=yes
MAKE_ENV+=	LIBSASS_EXT=yes CXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=	LIBSASS_LIBRARY=${LOCALBASE}/lib/libsass_pic.a
MAKE_ENV+=	LIBSASS_CFLAGS=-I${LOCALBASE}/include
MAKE_ENV+=	NPM_CONFIG_CACHE=${DISTDIR}/npm NPM_CONFIG_UNSAFE_PERM=1
MAKE_ENV+=	NPM_CONFIG_NODEDIR=${LOCALBASE}/include/node

NPM_CACHE=	${DISTDIR}/npm

.include <bsd.port.pre.mk>
.if ${COMPILER_TYPE} == clang
MAKE_ENV+=	GYP_DEFINES=clang=1
.endif

post-fetch:
	${MKDIR} ${DISTDIR}/${PORTNAME}
	${MKDIR} ${NPM_CACHE}
	${CP} ${FILESDIR}/package.json ${DISTDIR}/${PORTNAME}
	(cd ${DISTDIR}/${PORTNAME} && ${SETENV} NPM_CONFIG_CACHE=${NPM_CACHE} npm install --no-scripts)

post-extract:
	(cd ${DISTDIR}/${PORTNAME} && ${FIND} node_modules | ${PAX} -rw ${WRKSRC})

do-build:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} NPM_CONFIG_CACHE=${NPM_CACHE} npm install --nodedir=${LOCALBASE})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	(cd ${WRKSRC} && ${FIND} . -type f -o -type l | ${GREP} -v '^./build' | ${PAX} -rw ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME})
	(cd ${STAGEDIR}${PREFIX} && ${FIND} lib/node_modules/${PORTNAME}/vendor -type f >> ${TMPPLIST} )
	${LN} -s ${PREFIX}/lib/node_modules/node-sass/bin/node-sass ${STAGEDIR}${PREFIX}/bin/node-sass

.include <bsd.port.post.mk>
