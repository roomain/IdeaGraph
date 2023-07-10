#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(JSONEXPLORER_LIB)
#  define JSONEXPLORER_EXPORT Q_DECL_EXPORT
# else
#  define JSONEXPLORER_EXPORT Q_DECL_IMPORT
# endif
#else
# define JSONEXPLORER_EXPORT
#endif
