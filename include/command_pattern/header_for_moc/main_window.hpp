#ifndef COMMAND_MAIN_WINDOW_HPP
#define COMMAND_MAIN_WINDOW_HPP

#include "ui_MainWindow.h"

#include "../../common.hpp"
#include "macrocommand.hpp"

#include <memory>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QGraphicsScene;

namespace Is
{
    using std::shared_ptr;
    using std::make_shared;

    class DP_API MainWindow : public QMainWindow
    {
        Q_OBJECT

        Ui::MainWindow* ui_;
        QGraphicsScene* scene_;

        MacroCommand history_;

    public:
        MainWindow(QWidget* parent = nullptr);
        ~MainWindow();

    protected:
        virtual void mouseMoveEvent(QMouseEvent *event) override;
        virtual void mousePressEvent(QMouseEvent *event) override;

    public slots:
        void clearScene();
        void repaintScene();
    };
}
#endif