#ifndef SCREENS_H
#define SCREENS_H

namespace Colortrack
{
	class Screens {
	public:
		virtual void Input() = 0;
		virtual void Draw() = 0;
	};
}

#endif