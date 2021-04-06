
typedef char * va_list;
typedef long unsigned int size_t;

#include "kconfig.h"
#include "global_data.h"
register volatile gd_t *gd asm ("r9");

struct jt_funcs {
#define EXPORT_FUNC(impl, res, func, ...) res(*func)(__VA_ARGS__);
#include "_exports.h"
#undef EXPORT_FUNC
};

