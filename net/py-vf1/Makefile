# Created by: Marcin Cieślak <saper@saper.info>
# $FreeBSD$

PORTNAME=	vf1
DISTVERSION=	0.0.10
CATEGORIES=	net
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	VF-1-${DISTVERSION}

MAINTAINER=	saper@saper.info
COMMENT=	Command line gopher client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${FLAVOR}

USES=		python:3.2+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
