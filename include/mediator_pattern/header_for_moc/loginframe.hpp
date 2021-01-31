#ifndef MEDIATOR_LOGINFRAME_HPP
#define MEDIATOR_LOGINFRAME_HPP

#include "ui_LoginFrame.h"

#include "../../common.hpp"
#include "../mediator.hpp"

#include <memory>
#include <string>

#include <QDialog>

QT_BEGIN_NAMESPACE
    namespace Ui { class LoginFrame; }
QT_END_NAMESPACE

namespace Is
{
    using std::string;
    using std::shared_ptr;
    using std::make_shared;
    using std::unique_ptr;
    using std::make_unique;

    class DP_API LoginFrame : public QDialog, public Mediator
    {
        Q_OBJECT

        shared_ptr<Ui::LoginFrame> ui_;

        void userpassChanged();

    public:
        LoginFrame(QWidget* parent = nullptr);
        ~LoginFrame();

        virtual void createColleagues() override final;

        virtual void colleagueChanged() override final;

    public slots:
        void actionPerformed();
    };
}
#endif