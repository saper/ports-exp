# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/libsass/Makefile 360716 2014-07-05 02:58:20Z nivit $

PORTNAME=	libsass
PORTVERSION=	3.3.2
CATEGORIES=	textproc
DISTNAME=	$(PORTVERSION:S,.b,-beta.,)

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

AUTOMAKE_ARGS=	--add-missing

GH_ACCOUNT=	sass
GH_TAGNAME=	3.3.2
GH_COMMIT=	f47645c

INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	GNUmakefile.am

MAKEFILE=	GNUmakefile

USES=		autoreconf compiler:c++11-lib gmake:lite libtool pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

STATIC_PIC=	${PORTNAME}_pic.a

post-patch:
		@echo "echo \"${PORTVERSION}+FreeBSD.${GH_COMMIT}\"" > ${WRKSRC}/version.sh

post-build:
	(cd ${WRKSRC}/src/.libs && ${AR} rf ${STATIC_PIC} *.o)

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/${STATIC_PIC} ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
