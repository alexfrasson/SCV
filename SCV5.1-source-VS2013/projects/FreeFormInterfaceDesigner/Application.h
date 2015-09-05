#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <SCV/SCV.h>
#include "Widget.h"

class Application : public scv::Kernel {
public:
   ///////////////////////////////////////////////////////////
   Application(void);
   virtual ~Application(void);
   ///////////////////////////////////////////////////////////

   void init(void);

   //SCVCallbacks
   ///////////////////////////////////////////////////////////
   virtual void onMouseClick(const scv::MouseEvent &evt);
   virtual void onMouseDrag (const scv::MouseEvent &evt);
   virtual void onMouseOver (const scv::MouseEvent &evt);
   virtual void onMouseUp   (const scv::MouseEvent &evt);
   virtual void onMouseWheel(const scv::MouseEvent &evt);
   virtual void onKey       (const scv::KeyEvent &evt);
   virtual void onChar      (const unsigned int &character, const int &modifier);
   virtual void onSizeChange(void);
   virtual void onPositionChange(void);
   ///////////////////////////////////////////////////////////

protected:
   static const int s_defaultWindowWidth = 1280;
   static const int s_defaultWindowHeight = 720;
   scv::Panel *_mainPanel;
private:
};

#endif //__APPLICATION_H__