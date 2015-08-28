#include "Application.h"

Application::Application(void) : Kernel() {
   setWindowSize(1280, 720);
   lockWindowSize(false);
   setFramesPerSecond(60);

   setWindowTitle("SCV v5.0 - FreeForm Interface Designer");
}

Application::~Application(void) {
}

void Application::init(void) {
   _mainPanel = new scv::Panel(scv::Point(0, 0), scv::Point(1280, 720));

   addComponent(_mainPanel);

   Canvas0 *canvas0 = new Canvas0(scv::Point(341,280), scv::Point(541, 480));
   addComponent(canvas0);

}

void Application::onMouseClick(const scv::MouseEvent &evt) {
}
void Application::onMouseDrag(const scv::MouseEvent &evt) {
}
void Application::onMouseOver(const scv::MouseEvent &evt) {
}
void Application::onMouseUp(const scv::MouseEvent &evt) {
}
void Application::onMouseWheel(const scv::MouseEvent &evt) {
}
void Application::onKey(const scv::KeyEvent &evt) {
}
void Application::onChar(const unsigned int &character, const int &modifier) {
}
void Application::onSizeChange(void) {
   _mainPanel->setSize(getWidth(), getHeight());
}
void Application::onPositionChange(void) {
}
