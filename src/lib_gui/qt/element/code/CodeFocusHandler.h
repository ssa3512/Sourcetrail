#ifndef CODE_FOCUS_HANDLER_H
#define CODE_FOCUS_HANDLER_H

#include "types.h"

class QPushButton;
class QtCodeArea;
class QtCodeFile;

class CodeFocusHandler
{
public:
	enum class Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	struct Focus
	{
		QtCodeFile* file = nullptr;
		QtCodeArea* area = nullptr;
		QPushButton* scopeLine = nullptr;
		size_t lineNumber = 0;
		Id locationId = 0;
	};

	const Focus& getFocus() const;

	void setFocusedLocationId(QtCodeArea* area, size_t lineNumber, Id locationId);
	void setFocusedScopeLine(QtCodeArea* area, QPushButton* scopeLine);
	void setFocusedFile(QtCodeFile* file);

protected:
	Focus m_focus;
};

#endif // CODE_FOCUS_HANDLER_H
