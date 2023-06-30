#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(EDITWIDGETS_LIB)
#  define EDITWIDGETS_EXPORT Q_DECL_EXPORT
# else
#  define EDITWIDGETS_EXPORT Q_DECL_IMPORT
# endif
#else
# define EDITWIDGETS_EXPORT
#endif
