#ifndef QT_GRAPH_FOCUS_HANDLER_H
#define QT_GRAPH_FOCUS_HANDLER_H

#include <list>
#include <vector>

#include "types.h"

class QtGraphEdge;
class QtGraphNode;
class QPointF;

class QtGraphFocusClient
{
public:
	virtual void focusView() = 0;

	virtual const std::list<QtGraphNode*>& getGraphNodes() const = 0;
	virtual const std::list<QtGraphEdge*>& getGraphEdges() const = 0;

	virtual QtGraphNode* getActiveNode() const = 0;

	virtual void showNode(QtGraphNode* node) = 0;

	virtual QtGraphNode* findNodeRecursive(const std::list<QtGraphNode*>& nodes, Id tokenId) = 0;
};

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

	QtGraphFocusHandler(QtGraphFocusClient* client);

	void clear();

	void focus();
	void defocus();

	Id getLastFocusId() const;

	void focusInitialNode();

	void focusNext(Direction direction, bool navigateEdges);

	void focusNode(QtGraphNode* node);
	void defocusNode(QtGraphNode* node);
	void refocusNode(QtGraphNode* node);

	void focusEdge(QtGraphEdge* edge);
	void defocusEdge(QtGraphEdge* edge);

	void defocusGraph();

	void activateFocus();
	void expandFocus();

private:
	QtGraphNode* findNextNode(QtGraphNode* node, Direction direction);
	QtGraphNode* findNextNode(QtGraphEdge* edge, Direction direction);
	QtGraphEdge* findNextEdge(QPointF pos, Direction direction, QtGraphEdge* previousEdge = nullptr);

	QtGraphNode* findChildNodeRecursive(const std::list<QtGraphNode*>& nodes, bool first);

	QtGraphNode* findSibling(const QtGraphNode* node, Direction direction);
	std::vector<std::vector<QtGraphNode*>> getSiblingsHierarchyRecursive(const QtGraphNode* node);
	void addSiblingsRecursive(const std::list<QtGraphNode*>& nodes, std::vector<QtGraphNode*>& siblings);

	QtGraphFocusClient* const m_client;

	QtGraphNode* m_focusNode = nullptr;
	QtGraphEdge* m_focusEdge = nullptr;
	Id m_lastFocusId = 0;
};

#endif // QT_GRAPH_FOCUS_HANDLER_H
