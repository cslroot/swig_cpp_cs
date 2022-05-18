
#ifndef BAR_EXPORT_H
#define BAR_EXPORT_H

#ifdef BAR_STATIC_DEFINE
#define BAR_EXPORT
#define BAR_NO_EXPORT
#else
#ifndef BAR_EXPORT
#ifdef bar_EXPORTS
/* We are building this library */
#define BAR_EXPORT __declspec(dllexport)
#else
/* We are using this library */
#define BAR_EXPORT __declspec(dllimport)
#endif
#endif

#ifndef BAR_NO_EXPORT
#define BAR_NO_EXPORT
#endif
#endif

#ifndef BAR_DEPRECATED
#define BAR_DEPRECATED __declspec(deprecated)
#endif

#ifndef BAR_DEPRECATED_EXPORT
#define BAR_DEPRECATED_EXPORT BAR_EXPORT BAR_DEPRECATED
#endif

#ifndef BAR_DEPRECATED_NO_EXPORT
#define BAR_DEPRECATED_NO_EXPORT BAR_NO_EXPORT BAR_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#ifndef BAR_NO_DEPRECATED
#define BAR_NO_DEPRECATED
#endif
#endif

#endif /* BAR_EXPORT_H */
