#ifndef TESTWIDGET_GLOBAL_H
#define TESTWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TESTWIDGET_LIBRARY)
#  define TESTWIDGETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TESTWIDGETSHARED_EXPORT Q_DECL_IMPORT
#endif


extern "C" __declspec(dllexport) double multiply(int a, int b);

extern "C" __declspec(dllexport) void showDialog();
extern "C" __declspec(dllexport) void closeDialog();



#endif // TESTWIDGET_GLOBAL_H
