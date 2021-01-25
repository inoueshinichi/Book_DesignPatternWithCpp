#ifndef MEDIATOR_COLLEAQUE_TEXTFIELD_HPP
#define MEDIATOR_COLLEAQUE_TEXTFIELD_HPP

#include "../common.hpp"
#include "colleague.hpp"
#include "mediator.hpp"

#include <string>

#include <Qt>
#include <QString>
#include <QLineEdit>
#include <QPalette>

#include <QWidget>

namespace Is
{
    using std::string;

    class DP_API ColleagueTextField : public QLineEdit, public Colleague
    {
        Q_OBJECT

        Mediator* mediator_{nullptr};

    public:
        ColleagueTextField(QWidget* parent = nullptr)
            : QLineEdit(parent)
        {
            // Signal/Slot
            connect(this, &QLineEdit::textChanged, this, &ColleagueTextField::textValueChanged);
        }

        virtual ~ColleagueTextField() {}

        virtual void setMediator(Mediator* mediator) override final
        {
            mediator_ = mediator;
        }

        virtual void setColleagueEnabled(bool enabled) override final
        {
            // MediatorからButtonの有効/無効を指示される
            setEnabled(enabled);

            QPalette pal(palette());
            if (enabled)
                pal.setColor(QPalette::Background, Qt::white);
            else
                pal.setColor(QPalette::Background, Qt::lightGray);

            setPalette(pal);
        }

    public slots:
        void textValueChanged()
        {
            // 文字列が変化したらMediatorに通知する
            mediator_->colleagueChanged();
        }
    };
}
#endif