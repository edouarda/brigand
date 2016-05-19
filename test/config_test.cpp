
#include <brigand/config.hpp>

#ifdef BRIGAND_COMP_MSVC
static_assert(_MSC_VER > 0, "wrong compiler detection macro");
#endif

#ifdef BRIGAND_COMP_GCC
static_assert(__GNUC__ > 0, "wrong compiler detection macro");
#endif

#ifdef BRIGAND_COMP_CLANG
static_assert(__clang__ > 0, "wrong compiler detection macro");
#endif
