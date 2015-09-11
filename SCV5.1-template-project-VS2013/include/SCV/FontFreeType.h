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

class FontColor;

class FontFreeType : public Singleton<FontFreeType> {
friend class Singleton<FontFreeType>;

public:
	// Display.
	void display(std::string string, int X, int Y, FontColor color);
	void display(std::string string, int X, int Y, FontColor color, int fontSize);

	// Setters.
	void setFontName(std::string fontName);

	// Getters.
	float getAvgCharWidth(std::string string);
	float getStringLength(std::string string);
	float getHeight();

private:	
	FTGLPixmapFont *font;
	std::string fontName;

	FontFreeType();
	void createFont();	
};

class FontColor
{
public:
	float r, g, b; // 0.0 to 1.0

	FontColor(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
};

} // namespace scv

#endif // __SCV_FONT_FREE_TYPE_H__