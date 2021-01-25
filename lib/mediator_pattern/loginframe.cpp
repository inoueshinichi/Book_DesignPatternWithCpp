#include "mediator_pattern/loginframe.hpp"

namespace Is
{
    LoginFrame::LoginFrame(QWidget* parent)
        : QDialog(parent)
    {
        // UI設定
        ui_ = make_unique<Ui::LoginFrame>();
        ui_->setupUi(this);

        // Colleagueの設定
        createColleagues();

        // colleagueChangedの初期設定
        colleagueChanged();
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

    }
}
