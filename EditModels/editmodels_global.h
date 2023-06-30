#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(EDITMODELS_LIB)
#  define EDITMODELS_EXPORT Q_DECL_EXPORT
# else
#  define EDITMODELS_EXPORT Q_DECL_IMPORT
# endif
#else
# define EDITMODELS_EXPORT
#endif
