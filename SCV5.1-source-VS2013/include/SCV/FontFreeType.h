/*!
\file       FontFreeType.h
\brief      Implementation of Free Type fonts.
\author     SCV Team
*/

#ifndef __SCV_FONT_FREE_TYPE_H__
#define __SCV_FONT_FREE_TYPE_H__

#ifndef DOXYGEN_SKIP_THIS
#include "Singleton.h"
#endif // DOXYGEN_SKIP_THIS

#include "stdafx.h"
#include <FTGL\ftgl.h>

namespace scv {

/*! FontFreeType Class
* \ingroup internal
*/

class FreeTypeColor;

class FontFreeType : public Singleton<FontFreeType> {
friend class Singleton<FontFreeType>;

public:
	void display(std::string string, int X, int Y, FreeTypeColor color);
	void display(std::string string, int X, int Y, int fontsize);
	void setFontName(std::string fontName);
	float getAvgCharWidth(std::string string);
	float getHeight();
	float getStringLength(std::string string);

private:	
	FTGLPixmapFont *font;
	std::string fontName;

	FontFreeType(void);

	void createFont();	
};

class FreeTypeColor
{
public:
	float r, g, b; // 0.0 to 1.0

	FreeTypeColor(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
};

} // namespace scv

#endif // __SCV_FONT_FREE_TYPE_H__