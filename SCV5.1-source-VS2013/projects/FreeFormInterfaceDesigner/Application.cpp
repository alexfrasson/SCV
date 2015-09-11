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

   scv::TextBox *textBox0 = new scv::TextBox(scv::Point(245,220), scv::Point(430,371), "TextBox 0");
   addComponent(textBox0);

   scv::Spinner *spinner0 = new scv::Spinner(scv::Point(620,275), 35, 0.f, 100.f, 50.f, 1.f);
   addComponent(spinner0);

   scv::Label *label0 = new scv::Label(scv::Point(561,277), scv::Point(610, 290), "yeeeeah");
   addComponent(label0);

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
