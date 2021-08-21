/*
 * @author Double
 * @since 2021/08/22
 */

#ifndef D_BASE_H
#define D_BASE_H

#include "DLog.h"

#ifdef __cplusplus
extern "C" {
#endif

DEXPORT void DBaseInit(DLogLevel logLevel, DLogMode logMode, const char *logPath);

#ifdef __cplusplus
}
#endif

#endif // D_BASE_H
