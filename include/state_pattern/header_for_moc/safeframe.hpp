#ifndef STATE_SAFE_FRAME_HPP
#define STATE_SAFE_FRAME_HPP

#include "ui_SafeFrame.h"

#include "../../common.hpp"
#include "../context.hpp"
#include "../state.hpp"

#include <memory>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
    namespace Ui { class SafeFrame; }
QT_END_NAMESPACE

namespace IS
{
    using std::shared_ptr;
    using std::make_shared;

    class DP_API SafeFrame : public QMainWindow, public Context 
    {
        Q_OBJECT

        shared_ptr<Ui::SafeFrame> ui_;
        State* state_;

    public:
        SafeFrame(QWidget* parent = nullptr);
        ~SafeFrame();

        virtual void setClock(int hour) override final;
        virtual void changeState(State* state) override final;
        virtual void callSecurityCenter(const string& msg) override final;
        virtual void recordLog(const string& msg) override final;
    public slots:
        void actionPerformed();
    };
}
#endif