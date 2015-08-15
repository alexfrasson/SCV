/*

SCV - Simple Components for Visual
Developed at Federal University of Santa Maria - UFSM
LaCA - Computer Applied Laboratory - Laboratório de Computação Aplicada
webpage: www.inf.ufsm.br/~pozzer/scv
email: pozzer@inf.ufsm.br
2007-2012

*/

#include "SCV/SCV.h"

class MyCanvas : public scv::Canvas {
public:
	MyCanvas(const scv::Point& p1, const scv::Point& p2) : scv::Canvas(p1, p2)	
	{
		fontUbuntu = true;
	}
	void onKey(const scv::KeyEvent &evt);
	void render();	
	
	bool fontUbuntu;
};

void MyCanvas::onKey(const scv::KeyEvent &evt)
{
	if (evt.state == scv::KeyEvent::State::RELEASE)
	{
		if (fontUbuntu)
			scv::FontFreeType::getInstance()->setFontName("Instruction.ttf");
		else
			scv::FontFreeType::getInstance()->setFontName("UbuntuMono.ttf");
		fontUbuntu = !fontUbuntu;
	}	
}

void MyCanvas::render()
{	
	clear(0.7, 0.7, 0.7);
	int X = 15, Y = 30;
	text(X, Y, "Aperte um botao para mudar a fonte.");
	text(X, Y * 1.6, "Fonte:");
	if (fontUbuntu)
		text(65, Y * 1.6, "UbuntuMono");
	else
		text(65, Y * 1.6, "Instruction");
	text(X, Y * 3, "- Texto normal, sem formatacao.");
	text(X, Y * 4, "- Texto vermelho com tamanho original.", scv::FreeTypeColor(1, 0, 0), 14);
	text(X, Y * 5, "- Texto azul com tamanho customizado.", scv::FreeTypeColor(0, 0, 1), 18);
	text(X, Y * 6, "- Texto amarelo com tamanho customizado.", scv::FreeTypeColor(1, 1, 0), 10);

	circle(scv::Point(250, Y * 6 + 10), 10, 10);	
}

void example10_main() {
   scv::Kernel *kernel = scv::Kernel::getInstance();
   kernel->setWindowSize(500, 325);

	MyCanvas *canvas = new MyCanvas(scv::Point(50, 50), scv::Point(450, 275));
	kernel->addComponent(canvas);

   kernel->setFramesPerSecond(60);
   kernel->run();
}
