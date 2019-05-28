# Created by: Marcin Cieslak <saper@SAPER.INFO>
# $FreeBSD$

PORTNAME=	sqlbag
PORTVERSION=	0.1.1548994599
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	saper@SAPER.INFO
COMMENT=	This is just a collection of handy code for doing database things.

LICENSE=	UNLICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PY_PATHLIB} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.8:databases/py-sqlalchemy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
