#ifndef QT_GRAPH_FOCUS_HANDLER_H
#define QT_GRAPH_FOCUS_HANDLER_H

class QtGraphEdge;
class QtGraphNode;

class QtGraphFocusHandler
{
public:
	enum class Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	virtual void focusNext(Direction direction, bool navigateEdges) = 0;

	virtual void focusNode(QtGraphNode* node) = 0;
	virtual void defocusNode(QtGraphNode* node) = 0;

	virtual void focusEdge(QtGraphEdge* edge) = 0;
	virtual void defocusEdge(QtGraphEdge* edge) = 0;

	virtual void activateFocus() = 0;
	virtual void expandFocus() = 0;
};

#endif // QT_GRAPH_FOCUS_HANDLER_H
