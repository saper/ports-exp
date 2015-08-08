# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/libsass/Makefile 360716 2014-07-05 02:58:20Z nivit $

PORTNAME=	libsass
PORTVERSION=	3.2.5
CATEGORIES=	textproc
DISTNAME=	$(PORTVERSION:S,.b,-beta.,)

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

AUTOMAKE_ARGS=	--add-missing

GH_ACCOUNT=	saper
GH_TAGNAME=	5360d60

INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

USES=		autoreconf compiler:c++11-lib libtool pathfix gmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKEFILE= GNUmakefile

post-patch:
		@echo "echo \"${PORTVERSION}+FreeBSD.${GH_TAGNAME}\"" > ${WRKSRC}/version.sh

post-build:
	(cd ${WRKSRC}/src/.libs && ${AR} rf ${PORTNAME}.a *.o)

.include <bsd.port.mk>
