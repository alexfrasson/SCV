#include "stdafx.h"
#include "StaticLabel.h"

namespace scv {

namespace StaticLabel {

void display(int x, int y, const std::string &label, FreeTypeColor color) {
	static FontFreeType *freeType = FontFreeType::getInstance();
	freeType->display(label, x, y, color);
}

void display(int x, int y, const std::string &label, const Color4f &color) {
   display(Point(x, y), label, color);
}

void display(const Point &translate, const std::string &label, const Color4f &color) {
	static FontFreeType *freeType = FontFreeType::getInstance();	
	freeType->display(label, translate.x, translate.y, scv::FreeTypeColor(1, 1, 1));
}

void display(int x, int y, const std::string &label, int selectStart, int selectEnd, const Color4f &textColor, const Color4f &selectedTextColor, const Color4f &selectionColor) {
   display(Point(x, y), label, selectStart, selectEnd, textColor, selectedTextColor, selectionColor);
}

void display(const Point &translate, const std::string &label, int selectStart, int selectEnd, const Color4f &textColor, const Color4f &selectedTextColor, const Color4f &selectionColor) {
   static FontTahoma *font = FontTahoma::getInstance();
   static ComponentTexture *cTexture = font->getTexture();
   static ColorScheme *scheme = ColorScheme::getInstance();
	static FontFreeType *freeType = FontFreeType::getInstance();
	freeType->display(label, translate.x, translate.y, scv::FreeTypeColor(1, 1, 1));

   if (selectStart > selectEnd)
      std::swap(selectStart, selectEnd);

   int strLength = 0;
   float avgCharWidth = freeType->getAvgCharWidth(label),
			freeTypeHeight = freeType->getHeight();
   cTexture->enable();
   for (int i = 0; i < label.size(); i++) {
      if (label[i] != '\n') {
         // select
         if (selectStart != selectEnd && i > selectStart && i <= selectEnd) {
            scheme->applyColor(selectionColor);				
				cTexture->display(strLength + translate.x, translate.y - 2, 1, avgCharWidth, freeTypeHeight + 3);
            scheme->applyColor(selectedTextColor);
         } else {
            scheme->applyColor(textColor);
         }
      }
		strLength += avgCharWidth;
   }
   cTexture->disable();
}

} // namespace StaticLabel

} //namespace scv