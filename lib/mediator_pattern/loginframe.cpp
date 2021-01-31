#include "mediator_pattern/header_for_moc/loginframe.hpp"

#include <QMessageBox>

namespace Is
{
    LoginFrame::LoginFrame(QWidget* parent)
        : QDialog(parent)
    {
        // UI設定
        ui_ = make_shared<Ui::LoginFrame>();
        ui_->setupUi(this);

        // Setting
        // this->setAttribute(Qt::WA_DeleteOnClose);

        // Colleagueの設定
        createColleagues();

        // colleagueChangedの初期設定
        colleagueChanged();

        // Signal/Slot
        connect(ui_->pushButton_Ok, &QPushButton::clicked, this, &LoginFrame::actionPerformed);
    }

    LoginFrame::~LoginFrame() {}

    void LoginFrame::createColleagues()
    {
        // Colleagueたちの設定
        // Qtを使っているのでインスタンスの生成はしない

        // Mediatorのセット
        ui_->radioButton_Guest->setMediator(this);
        ui_->radioButton_Login->setMediator(this);
        ui_->lineEdit_Username->setMediator(this);
        ui_->lineEdit_Password->setMediator(this);
        ui_->pushButton_Ok->setMediator(this);
        ui_->pushButton_Cancel->setMediator(this);
    }

    void LoginFrame::colleagueChanged()
    {
        if (ui_->radioButton_Guest->isChecked())
        {
            ui_->lineEdit_Username->setColleagueEnabled(false);
            ui_->lineEdit_Password->setColleagueEnabled(false);
            ui_->pushButton_Ok->setColleagueEnabled(true);
        }
        else
        {
            ui_->lineEdit_Username->setColleagueEnabled(true);
            userpassChanged();
        }
    }

    // lineEdit_Username or lineEdit_Passwordの変更があった
    // 各Colleagueの有効/無効を判定する
    void LoginFrame::userpassChanged()
    {
        if (auto text = ui_->lineEdit_Username->text(); text.length() > 0)
        {
            ui_->lineEdit_Password->setColleagueEnabled(true);
            if (auto text = ui_->lineEdit_Password->text(); text.length() > 0)
            {
                ui_->pushButton_Ok->setColleagueEnabled(true);
            }
            else
            {
                ui_->pushButton_Ok->setColleagueEnabled(false);
            }
        }
        else
        {
            ui_->lineEdit_Password->setColleagueEnabled(false);
            ui_->pushButton_Ok->setColleagueEnabled(false);
        }
    }

    void LoginFrame::actionPerformed()
    {
        auto user_text = ui_->lineEdit_Username->text();
        auto pass_text = ui_->lineEdit_Password->text();
        if (user_text.length() > 0 && pass_text.length() > 0)
        {

            QMessageBox::information(this, "ID&Pass", QString("%1\n%2").arg(user_text).arg(pass_text));
        }
    }
}
