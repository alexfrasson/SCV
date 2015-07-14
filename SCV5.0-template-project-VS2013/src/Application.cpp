#include "Application.h"

Application::Application(void) : Kernel() {
   setWindowSize(973, 720);
   lockWindowSize(false);
   setFramesPerSecond(60);

   setWindowTitle("SCV v5.0 - FreeForm Interface Designer");
}

Application::~Application(void) {
}

void Application::init(void) {
   _mainPanel = new scv::Panel(scv::Point(0, 0), scv::Point(973, 720));

   addComponent(_mainPanel);

   scv::Canvas *canvas0 = new scv::Canvas(scv::Point(26,101), scv::Point(731, 687));
   addComponent(canvas0);

   scv::Button *button0 = new scv::Button(scv::Point(747,637), scv::Point(956, 690), "Button");
   addComponent(button0);

   scv::ScrollComponent *scrollComponent0 = new scv::ScrollComponent(scv::Point(746,100), scv::Point(956, 609));
   addComponent(scrollComponent0);
   scv::Panel *panel0 = new scv::Panel(scv::Point(-194, 0),  scv::Point(500, 500));
   scrollComponent0->setComponent(panel0);

   scv::Label *label0 = new scv::Label(scv::Point(29,44), scv::Point(105, 57), "Slider");
   addComponent(label0);

   scv::Slider *slider0 = new scv::Slider(scv::Point(77,42), 144, 0.f, 100.f, 50.f, 1.f);
   addComponent(slider0);

   scv::Spinner *spinner0 = new scv::Spinner(scv::Point(872,17), 82, 0.f, 100.f, 50.f, 1.f);
   addComponent(spinner0);

   scv::Spinner *spinner1 = new scv::Spinner(scv::Point(872,55), 82, 0.f, 100.f, 50.f, 1.f);
   addComponent(spinner1);

   scv::TextBox *textBox0 = new scv::TextBox(scv::Point(274,15), scv::Point(734,64), "TextBox 0");
   addComponent(textBox0);

   scv::Label *label1 = new scv::Label(scv::Point(813,20), scv::Point(887, 33), "Ha");
   addComponent(label1);

   scv::Label *label2 = new scv::Label(scv::Point(812,56), scv::Point(888, 69), "Haha");
   addComponent(label2);

}

void Application::onMouseClick(const scv::MouseEvent &evt) {
}
void Application::onMouseHold(const scv::MouseEvent &evt) {
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
