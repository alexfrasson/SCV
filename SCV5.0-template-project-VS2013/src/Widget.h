#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <SCV/SCV.h>

class Canvas0 : public scv::Canvas {
public:
   Canvas0(scv::Point p1, scv::Point p2);

   virtual void onMouseClick(const scv::MouseEvent &evt);
   virtual void onMouseDrag (const scv::MouseEvent &evt);
   virtual void onMouseOver (const scv::MouseEvent &evt);
   virtual void onMouseUp   (const scv::MouseEvent &evt);
   virtual void onMouseWheel(const scv::MouseEvent &evt);
   virtual void onKey       (const scv::KeyEvent &evt);
   virtual void onChar      (const unsigned int &character, const int &modifier);
   virtual void onSizeChange(void);
   virtual void onPositionChange(void);

   virtual void render(void);
   virtual void update(void);

};

#endif