#include "FontFreeType.h"

namespace scv {

FontFreeType::FontFreeType(void) {
	fontName = "UbuntuMono.ttf";
	//fontName = "Instruction.ttf";
	createFont();
}

void FontFreeType::display(std::string string, int X, int Y, FreeTypeColor color)
{
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	glRasterPos2d(X + 1, Y + 11); // Positioning correction.
	font->Render(string.c_str());
	glPopMatrix();	
}

void FontFreeType::display(std::string string, int X, int Y, int fontsize)
{
	glPushMatrix();
	glRasterPos2d(X + 1, Y + 11); // Positioning correction.
	font->FaceSize(fontsize);
	font->Render(string.c_str());
	font->FaceSize(14);
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
		printf("Font error: Not detected.\n");
	// Font size.
	font->FaceSize(14);
}

} // namespace scv