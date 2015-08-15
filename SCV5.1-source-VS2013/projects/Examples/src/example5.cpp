/* Button Group
 * 
 */

#include <SCV/Kernel.h>
#include <SCV/ColorScheme.h>
#include <SCV/ProgressBar.h>
#include <SCV/Slider.h>
#include <SCV/ButtonGroup.h>
#include <SCV/RadioButton.h>


namespace {

class MyRadioButton : public scv::RadioButton {
public:
   MyRadioButton(scv::Point p1 , std::string name) : scv::RadioButton(p1, false, name) {
      //Adicionar o componente ao kernel
      scv::Kernel::getInstance()->addComponent(this);
   }

private:

};

}

void example5_main() {
	scv::Kernel* kernel = scv::Kernel::getInstance();
	
	kernel->setWindowSize(300, 250);



	scv::Label *label = new scv::Label(scv::Point(20, 40), "Escolha sua cor:");
	scv::Kernel::getInstance()->addComponent(label);
   MyRadioButton * b1 = new MyRadioButton(scv::Point(20, 80),      "Vermelho");	
   MyRadioButton * b2 = new MyRadioButton(scv::Point(20, 80+30),   "Verde");
   MyRadioButton * b3 = new MyRadioButton(scv::Point(20, 80+30*2), "Azul");
   MyRadioButton * b4 = new MyRadioButton(scv::Point(20, 80+30*3), "Branco");

	/*
	Para criar um grupo de botões, é necessário criar uma 
	instância de 'ButtonGroup' e registrar cada botão
	à instância criada.
	*/
   scv::ButtonGroup * bgroup = new scv::ButtonGroup();
   b1->registerButtonGroup(bgroup);
   b2->registerButtonGroup(bgroup);
   b3->registerButtonGroup(bgroup);
   b4->registerButtonGroup(bgroup);

	kernel->setFramesPerSecond(60);
	kernel->run();
}