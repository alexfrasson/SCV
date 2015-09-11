#include "widget.h"

Canvas0::Canvas0(scv::Point p1, scv::Point p2) : scv::Canvas(p1, p2) {
}
//Canvas0
void Canvas0::onMouseClick(const scv::MouseEvent &evt) {
	printf("%f", evt.getPosition().x);
}
void Canvas0::onMouseDrag(const scv::MouseEvent &evt) {
	printf("d");
}
void Canvas0::onMouseOver(const scv::MouseEvent &evt) {
	glColor3f(1, 0, 0);
	line(scv::Point(0, 0), scv::Point(evt.getPosition().x, evt.getPosition().y));
	printf("%f", evt.getPosition().x);
}
void Canvas0::onMouseUp(const scv::MouseEvent &evt) {
}
void Canvas0::onMouseWheel(const scv::MouseEvent &evt) {
}
void Canvas0::onKey(const scv::KeyEvent &evt) {
}
void Canvas0::onChar(const unsigned int &character, const int &modifier) {
}
void Canvas0::onSizeChange(void) {
}
void Canvas0::onPositionChange(void) {
}
void Canvas0::render(void) {
	clear(0.5, 0.5, 0);
}
void Canvas0::update(void) {
}
