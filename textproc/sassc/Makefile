# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/sassc/Makefile 360717 2014-07-05 03:23:35Z nivit $

PORTNAME=	sassc
PORTVERSION=	3.3.6
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wrapper around libsass

LICENSE=	MIT

LIB_DEPENDS=	libsass.so.1:textproc/libsass

AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ENV+=	SASSC_VERSION="${PORTVERSION}"

CPPFLAGS+=	-I${LOCALBASE}/include

GH_ACCOUNT=	sass
GH_COMMIT=	e32c23d

LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/sassc

USE_GITHUB=	yes
USES=		autoreconf compiler:c++11-lib gmake:lite libtool
GNU_CONFIGURE=	yes

post-patch:
	@echo "echo \"${PORTVERSION}+FreeBSD.${GH_COMMIT}\"" > ${WRKSRC}/version.sh

.include <bsd.port.mk>
