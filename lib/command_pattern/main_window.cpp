#include "command_pattern/header_for_moc/main_window.hpp"
#include "command_pattern/drawcommand.hpp"

#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>
#include <QString>

namespace Is
{
    MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent)
    {
        // UI
        ui_ = new Ui::MainWindow();
        ui_->setupUi(this);

        // Scene/View
        scene_ = new QGraphicsScene(this);
        scene_->setSceneRect(ui_->graphicsView->rect());
        ui_->graphicsView->setScene(scene_);
        // 仮想WindowであるSceneをViewportであるViewにどのような相対関係でマッピングするか決める
        ui_->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop); 

        // Signal/Slot
        connect(ui_->pushButton_Clear, SIGNAL(clicked()), this, SLOT(clearScene()));
        connect(ui_->pushButton_Repaint, SIGNAL(clicked()), this, SLOT(repaintScene()));
    }

    MainWindow::~MainWindow()
    {
        delete ui_;
        delete scene_;
    }

    // proteced
    void MainWindow::mouseMoveEvent(QMouseEvent* event)
    {

    }

    // protected
    void MainWindow::mousePressEvent(QMouseEvent* event)
    {
        QGraphicsView* view = ui_->graphicsView; // 再定義

        QPointF mouse_pos_win = event->windowPos(); // Windowのクライアント領域上でのマウスの位置
        QPoint relative_view_pos = view->pos(); // Windowのクライアント領域上でのViewの左上原点
        QPoint mouse_pos_view = mouse_pos_win.toPoint() - relative_view_pos;
        QPointF mouse_pos_scene = view->mapToScene(mouse_pos_view);

        qDebug() << QString(" -> center(%1,%2) in Scene.").arg(mouse_pos_scene.x()).arg(mouse_pos_scene.y());

        shared_ptr<Command> cmd = make_shared<DrawCommand>(scene_, mouse_pos_scene);
        history_.append(cmd); // 履歴を残す
        cmd->execute();
    }


    // slot
    void MainWindow::clearScene()
    {
        auto items = scene_->items();
        for (auto iter = items.begin(); iter < items.end(); ++iter)
        {
            scene_->removeItem(*iter);
        }
    }

    
    // slot
    void MainWindow::repaintScene()
    {
        // 履歴をたどって描画
        history_.execute();
    }
}