#ifndef MEDIATOR_COLLEAGUE_BUTTON_HPP
#define MEDIATOR_COLLEAGUE_BUTTON_HPP

#include "../common.hpp"
#include "colleague.hpp"
#include "mediator.hpp"

#include <string>

#include <QString>
#include <QPushButton>
#include <QWidget>

namespace Is
{
    using std::string;

    class DP_API ColleagueButton : public QPushButton, public Colleague
    {
        Q_OBJECT

        Mediator* mediator_;

    public:
        ColleagueButton(QWidget* parent = nullptr)
            : QPushButton(parent)
        {}

        virtual ~ColleagueButton() {}

        virtual void setMediator(Mediator* mediator) override final
        {
            mediator_ = mediator;
        }

        virtual void setColleagueEnabled(bool enabled) override final
        {
            // MediatorからButtonの有効/無効を指示される
            setEnabled(enabled);
        }
    };
}
#endif