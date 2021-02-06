#ifndef COMMAND_DRAW_COMMAND_HPP
#define COMMAND_DRAW_COMMAND_HPP

#include "../common.hpp"
#include "command.hpp"

#include <memory>

#include <Qt>
#include <QPen>
#include <QPointF>
// #include <QRectF>
#include <QGraphicsEllipseItem>

namespace Is
{
    using std::shared_ptr;

    class DP_API DrawCommand : public Command
    {
    protected:
        QGraphicsScene* drawable_;

    private:
        QGraphicsEllipseItem* ellipse_item_{nullptr};
        QPointF pos_;
        qreal radius_;

    public:
        DrawCommand(QGraphicsScene* drawable, QPointF pos, qreal radius = 10.0)
            : drawable_(drawable), pos_(pos), radius_(radius)
        {
            // ellipse_item_ = new QGraphicsEllipseItem(pos_.x(), pos_.y(), radius_, radius_);
        }
        
        virtual ~DrawCommand() 
        {
            delete ellipse_item_;
            ellipse_item_ = nullptr;
        }

        virtual void execute()
        {
            // drawable_->addItem(ellipse_item_);

            qreal cx = pos_.x() - radius_;
            qreal cy = pos_.y() - radius_;
            drawable_->addEllipse(cx, cy, radius_, radius_, QPen(Qt::black));
        }
    };
}
#endif