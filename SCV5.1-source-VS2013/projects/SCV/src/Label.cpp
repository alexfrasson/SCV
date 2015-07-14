#include "stdafx.h"
#include "Label.h"
#include "Kernel.h"

namespace scv {

Label::Label(const scv::Point &p1, const scv::Point &p2, const std::string& str) : Component(p1, p2) {
   _isHResizable = _isVResizable = false;
   _str = str;
   _type = LABEL;

   setMaximumSize(getPreferredSize());

   createTexture();
}

Label::Label(const scv::Point &p, const std::string& str) : Component(p, Point(p.x + FontFreeType::getInstance()->getStringLength(str), p.y + 13)) {
   _isHResizable = _isVResizable = false;
   _str = str;
   _type = LABEL;

   setMaximumSize(getPreferredSize());

   createTexture();
}

Label::Label(const scv::Point &p, unsigned int width, const std::string& str) : Component(p, Point(p.x + width, p.y + 13)) {
   _isHResizable = _isVResizable = false;
   _str = str;
   _type = LABEL;

   setMaximumSize(getPreferredSize());

   createTexture();
}

void Label::setString(const std::string& str) {
   static Kernel *kernel = Kernel::getInstance();
	static FontFreeType *freeType = FontFreeType::getInstance();
   if (_str != str) {
      _str = str;
      onStringChange();
   }
	setWidth(freeType->getStringLength(_str));
}

void Label::display(void) {	
	static FontFreeType *freeType = FontFreeType::getInstance();
	freeType->display(_str, getAbsolutePosition().x, getAbsolutePosition().y, scv::FreeTypeColor(1, 1, 1));
}

} // namespace scv
