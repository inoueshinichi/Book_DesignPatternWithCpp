#include "state_pattern/header_for_moc/safeframe.hpp"
#include "state_pattern/day_state.hpp"
#include "state_pattern/night_state.hpp"
#include "state_pattern/state.hpp"

#include <sstream>
#include <iostream>

#include <QMessageBox>
#include <QString>

namespace Is
{
    SafeFrame::SafeFrame(QWidget* parent)
        : QMainWindow(parent)
        , state_(StateSingletonManager::getInstance<DayState>())
    {
        // UI
        ui_ = make_shared<Ui::SafeFrame>();
        ui_->setupUi(this); 

        // Setting
        this->setAttribute(Qt::WA_DeleteOnClose);

        // Signal/Slot
        connect(ui_->pushButton_Use, &QPushButton::clicked, this, &SafeFrame::actionPerformed);
        connect(ui_->pushButton_Alarm, &QPushButton::clicked, this, &SafeFrame::actionPerformed);
        connect(ui_->pushButton_Phone, &QPushButton::clicked, this, &SafeFrame::actionPerformed);
    }

    SafeFrame::~SafeFrame()
    {
        StateSingletonManager::clear();
    }

    // Slot
    void SafeFrame::actionPerformed()
    {
        auto sender = sender();
        if (sender == ui_->pushButton_Use)
        {
            state_->doUse(this);
        }
        else if (sender == ui_->pushButton_Alarm)
        {
            state_->doAlarm(this);
        }
        else if (sender == ui_->pushButton_Phone)
        {
            state_->doPhone(this);
        }
        else
        {
            QMessageBox::warning(this, "Exception", "?");
        }
    }

    void SafeFrame::setClock(int hour)
    {
        std::stringstream ss;
        ss << "現在時刻は";
        if (hour < 10)
        {
            ss << "0" << hour << ":00";
        }
        else
        {
            ss << hour << ":00";
        }
        std::cout << ss.str() << std::endl;
        ui_->textEdit_Clock->append(ss.str().c_str());
        state_->doClock(this, hour);
    }

    void SafeFrame::changeState(State* state)
    {
        std::cout << (*state_)() << "から" << (*state)() << "へ状態が変化しました。" << std::endl;
        state_ = state;
    }

    void SafeFrame::callSecurityCenter(const string& msg)
    {
        ui_->textEdit_Clock->append(QString("call! %1\n").arg(msg.c_str()));
    }

    void SafeFrame::recordLog(const string& msg)
    {
        ui_->textEdit_Clock->append(QString("record ... %1\n").arg(msg.c_str()));
    }
}