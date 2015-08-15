/* Exemplo que mostra o uso dos botoes.
 * Cada botao modifica a string do Textfield
 * de uma maneira
 */
#include <SCV/Kernel.h>
#include <SCV/ColorScheme.h>
#include <SCV/Label.h>
#include <SCV/Button.h>
#include <SCV/TextField.h>
#include <string>

namespace {

class MyCenterButton : public scv::Button {
public:
   MyCenterButton(scv::Point p1, std::string t, scv::TextField* tt) : scv::Button(scv::Point(p1.x,p1.y),scv::Point(p1.x + 80,p1.y + 20), t) {
      //Pega e armazena o ponteiro do Textfield usado
      tf = tt;
   }

   //Implementacao da callback do botao
   void onMouseClick(const scv::MouseEvent &evt) {
      //Seta o conteudo do textfield para Center
      tf->setString("Center");
   }
private:
   scv::TextField *tf;
};

class MyRightButton : public scv::Button {
public:
   MyRightButton(scv::Point p1, std::string t, scv::TextField* tt) : scv::Button(scv::Point(p1.x,p1.y),scv::Point(p1.x + 80,p1.y + 20), t) {
      //Pega e armazena o ponteiro do Textfield usado
      tf = tt;
   }

   //Implementacao da callback do botao
   void onMouseClick(const scv::MouseEvent &evt) {
      //Seta o conteudo do textfield para Right
      tf->setString("Right");
   }
private:
   scv::TextField *tf;
};

class MyLeftButton : public scv::Button {
public:
   MyLeftButton(scv::Point p1, std::string t, scv::TextField* tt) : scv::Button(scv::Point(p1.x,p1.y),scv::Point(p1.x + 80,p1.y + 20), t) {
      //Pega e armazena o ponteiro do Textfield usado
      tf = tt;
   }

   //Implementacao da callback do botao
   void onMouseClick(const scv::MouseEvent &evt) {
      //Seta o conteudo do textfield para Left
      tf->setString("Left");
   }
private:
   scv::TextField *tf;
};

}

void example2_main() {
	scv::Kernel* kernel = scv::Kernel::getInstance();

   scv::ColorScheme* scheme = scv::ColorScheme::getInstance();
   scheme->loadScheme(scv::ColorScheme::WARCRAFT);

   kernel->setWindowSize(400, 200);

   scv::TextField *tf = new scv::TextField(scv::Point(80,70),240,"Center");
   scv::Kernel::getInstance()->addComponent(tf);

	MyLeftButton *bLeft = new MyLeftButton(scv::Point(80,90), "Left", tf);
   MyCenterButton *bCenter = new MyCenterButton(scv::Point(160,90),"Center", tf);
   MyRightButton *bRight = new MyRightButton(scv::Point(240,90),"Right", tf);
   scv::Kernel::getInstance()->addComponent(bLeft);
   scv::Kernel::getInstance()->addComponent(bCenter);
   scv::Kernel::getInstance()->addComponent(bRight);

	kernel->setFramesPerSecond(60);
	kernel->run();
}
