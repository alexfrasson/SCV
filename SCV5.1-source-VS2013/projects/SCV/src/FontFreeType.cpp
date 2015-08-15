#include "FontFreeType.h"

namespace scv {

FontFreeType::FontFreeType(void) {
	setFontName("UbuntuMono.ttf"); // Standard font name.	
}

void FontFreeType::display(std::string string, int X, int Y, FreeTypeColor color)
{
	display(string, X, Y, color, 14);
}

void FontFreeType::display(std::string string, int X, int Y, FreeTypeColor color, int fontSize)
{
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	glRasterPos2d(X + 1, Y + 11); // Positioning correction.
	font->FaceSize(fontSize);
	font->Render(string.c_str());	
	glPopMatrix();
}

void FontFreeType::setFontName(std::string fontName)
{
	this->fontName = fontName;	
	createFont();
}

float FontFreeType::getAvgCharWidth(std::string string)
{
	return (font->Advance(string.c_str(), string.length(), FTPoint())) / string.length();
}

float FontFreeType::getHeight()
{
	return font->Ascender();
}

float FontFreeType::getStringLength(std::string string)
{	
	return font->Advance(string.c_str(), string.length(), FTPoint());
}

void FontFreeType::createFont()
{
	font = new FTGLPixmapFont(fontName.c_str());
	// Check error.
	if (font->Error())
		printf("Font error: '%s' was not detected.\n", fontName.c_str());
}

} // namespace scv