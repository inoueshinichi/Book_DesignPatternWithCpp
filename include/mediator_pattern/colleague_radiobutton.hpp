#ifndef MEDIATOR_COLLEAGUE_RADIOBUTTON_HPP
#define MEDIATOR_COLLEAGUE_RADIOBUTTON_HPP

#include "../common.hpp"
#include "colleague.hpp"
#include "mediator.hpp"

#include <string>

#include <QRadioButton>
#include <QWidget>

namespace Is
{
    using std::string;

    class DP_API ColleagueRadioButton : public QRadioButton, public Colleague
    {
        Q_OBJECT

        Mediator* mediator_ {nullptr};

    public:
        ColleagueRadioButton(QWidget* parent = nullptr)
            : QRadioButton(parent)
        {
            // Signal/Slot
            connect(this, &QRadioButton::toggled, this, &ColleagueRadioButton::itemStateChanged);
        }

        virtual ~ColleagueRadioButton() {}

        virtual void setMediator(Mediator* mediator) override final
        {
            mediator_ = mediator;
        }

        virtual void setColleagueEnabled(bool enabled) override final
        {
            // MediatorからButtonの有効/無効を指示される
            setEnabled(enabled);
        }

    public slots:
        void itemStateChanged()
        {
            // 状態が変化したらMediatorに通知する
            mediator_->colleagueChanged();
        }
    };
}
#endif