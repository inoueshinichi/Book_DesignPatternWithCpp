#ifndef DESIGN_PATTERN_COMMON_HPP
#define DESIGN_PATTERN_COMMON_HPP

#if defined(_MSC_VER)

#   if defined(design_pattern_EXPORTS) || defined(design_pattern_dbg_EXPORTS)
#       define DP_API __declspec(dllexport)
#   else
#       define DP_API __declspac(dllimport)
#   endif

#else
#   define DP_API 
#endif

#endif 