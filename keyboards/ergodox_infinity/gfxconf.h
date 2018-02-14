/**
 * This file has a different license to the rest of the uGFX system.
 * You can copy, modify and distribute this file as you see fit.
 * You do not need to publish your source modifications to this file.
 * The only thing you are not permitted to do is to relicense it
 * under a different license.
 */

/**
 * Copy this file into your project directory and rename it as gfxconf.h
 * Edit your copy to turn on the uGFX features you want to use.
 * The values below are the defaults.
 *
 * Only remove the comments from lines where you want to change the
 * default value. This allows definitions to be included from
 * driver makefiles when required and provides the best future
 * compatibility for your project.
 *
 * Please use spaces instead of tabs in this file.
 */

#ifndef _GFXCONF_H
#define _GFXCONF_H

#include "common_gfxconf.h"
#define GDISP_NEED_TEXT			TRUE
#define GDISP_NEED_UTF8			TRUE
#define GDISP_NEED_ANTIALIAS		TRUE   // if wanted
#define GDISP_NEED_TEXT_KERNING		TRUE   // if wanted
#define GDISP_INCLUDE_USER_FONTS	TRUE

#endif /* _GFXCONF_H */
