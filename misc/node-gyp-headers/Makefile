# Created by: Marcin Cieslak <saper@SAPER.INFO>
# $FreeBSD$

PORTNAME=	node-gyp-headers
PORTVERSION=	0007
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	misc
MASTER_SITES=	ftp://m.saper.info/local/

MAINTAINER=	saper@SAPER.INFO
COMMENT=	Development headers for node extensions

LICENSE=	MIT

USES=		zip

NO_BUILD=	yes

WRKSRC=		${WRKDIR}

.include <bsd.port.pre.mk>

do-install:
	(cd ${WRKDIR} && ${COPYTREE_SHARE} node-gyp ${STAGEDIR}${PREFIX}/share/)

.include <bsd.port.post.mk>
