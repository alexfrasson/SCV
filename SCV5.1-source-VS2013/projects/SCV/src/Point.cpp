#include "stdafx.h"
#include "Point.h"
#include "Kernel.h"

#include "util.h"

namespace scv {

Point::Point(void) : x(0), y(0) {
}

Point::Point(int x, int y) : x(x), y(y) {
}

Point::Point(const std::string &str) {
   std::istringstream iss(str);
   std::string word;

   getline( iss, word, ',' );
   x = fromString<int>(trim(word));   
   getline( iss, word, ',' );
   y = fromString<int>(trim(word));
}

std::ostream& operator<<(std::ostream& lhs, const Point& rhs) {
   return (lhs << rhs.x << "," << rhs.y);
}

const Point Point::inverse(void) const {
   return Point(x, Kernel::getInstance()->getHeight() - y);
}

//@epreuss
void Point::toFiveMultiple()
{	
	int remainder;
	// For x.
	remainder = x % 5;
	if (remainder == 1 || remainder == 2)
		x -= remainder;
	else if (remainder == 3 || remainder == 4)
		x += 5 - remainder;
	// For y.
	remainder = y % 5;
	if (remainder == 1 || remainder == 2)
		y -= remainder;
	else if (remainder == 3 || remainder == 4)
		y += 5 - remainder;
}

} // namespace scv


