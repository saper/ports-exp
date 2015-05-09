# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/libsass/Makefile 360716 2014-07-05 02:58:20Z nivit $

PORTNAME=	libsass
PORTVERSION=	3.2.3
CATEGORIES=	textproc
DISTNAME=	$(PORTVERSION:S,.b,-beta.,)

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

AUTOMAKE_ARGS=	--add-missing

GH_ACCOUNT=	saper
GH_COMMIT=	55fa15b
GH_TAGNAME=	FreeBSD

INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

USES=		autoreconf compiler:c++11-lib libtool pathfix gmake:lite
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-patch:
		@echo "echo \"${PORTVERSION}+FreeBSD.${GH_COMMIT}\"" > ${WRKSRC}/version.sh

post-build:
	(cd ${WRKSRC}/.libs && ${AR} rf ${PORTNAME}.a *.o)

.include <bsd.port.mk>
