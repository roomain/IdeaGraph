#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IDEAGRAPH_LIB)
#  define IDEAGRAPH_EXPORT Q_DECL_EXPORT
# else
#  define IDEAGRAPH_EXPORT Q_DECL_IMPORT
# endif
#else
# define IDEAGRAPH_EXPORT
#endif
