#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "treemodel.h"
#include "animationscene.h"
#include "timeline.h"
#include "animationpropertyeditor.h"
#include "itempropertyeditor.h"
#include "scenepropertyeditor.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setTitle();
    
protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    void createMenus();
    void createActions();
    void createStatusBar();
    void createGui();
    void writeSettings();
    void readSettings();
    void writeFile(QString fileName);
    void reset();

    QSplitter *splitter;
    QToolBar *toolbar;
    QTreeView *tree;
    TreeModel *model;
    AnimationScene *scene;
    QGraphicsView *view;
    QFileInfo loadedFile;
    Timeline *timeline;
    AnimationPropertyEditor *m_animationPropertyEditor;
    ItemPropertyEditor *m_itemPropertyEditor;
    ScenePropertyEditor *m_scenePropertyEditor;
    QDockWidget *propertiesdock;
    QDockWidget *tooldock;


    QAction *openAct;
    QAction *newAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exportAct;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *selectAct;
    QAction *rectangleAct;
    QAction *ellipseAct;
    QAction *textAct;
    QAction *svgAct;
    QAction *bitmapAct;
    QAction *showPropertyPanelAct;
    QAction *showToolPanelAct;
    QAction *copyAct;
    QAction *pasteAct;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QMenu *viewMenu;

public slots:
    void exportAnimation();
    void about();
    void save();
    void saveAs();
    void open();
    void newfile();
    void setSelectMode();
    void setRectangleMode();
    void setEllipseMode();
    void setTextMode();
    void setBitmapMode();
    void setSvgMode();
    void elementtreeSelectionChanged(const QItemSelection&,const QItemSelection&);
    void sceneItemAdded(QGraphicsItem *);
    void showPropertyPanel();
    void showToolPanel();
    void changePropertyEditor(QPropertyAnimation *);
    void sceneSelectionChanged();
    void timelineSelectionChanged(ResizeableItem*);
    void copy();
    void paste();
};

#endif // MAINWINDOW_H
