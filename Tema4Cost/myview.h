#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QMouseEvent>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QMessageBox>
#include <vector>
#include "graf.h"

class MyView : public QGraphicsView
{
	Q_OBJECT

public:
	MyView(QWidget* parent = nullptr);
	void run();

	void mouseReleaseEvent(QMouseEvent* event) override;
	Graf& getGraf();
public:
    void redraw();
    void drawGenericTree();
    void drawKruskalTree();
    void keyPressEvent(QKeyEvent* event) override;


private:
	void drawNode(int x, int y, int value);
    void drawLine(int startX, int startY, int endX, int endY);
	//void redraw();

	QGraphicsScene* scene;
	Graf m_graf;

	Node* m_selectedNode;
	bool m_isFirstNodeSelected; 

private:
	Node* m_draggedNode = nullptr;
	QPoint m_offset;
};

#endif // MYVIEW_H
