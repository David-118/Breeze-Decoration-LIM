/*
 * Copyright (C) 2018 Vlad Zagorodniy <vladzzag@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// own
#include "Button.h"

// KDecoration
#include <KDecoration2/DecoratedClient>

// Qt
#include <QPainter>

namespace Material
{

class MaximizeButton
{

public:
    static void init(Button *button, KDecoration2::DecoratedClient *decoratedClient) {
        QObject::connect(decoratedClient, &KDecoration2::DecoratedClient::maximizeableChanged,
                button, &Button::setVisible);

        button->setVisible(decoratedClient->isMaximizeable());
    }
    static void paintIcon(Button *button, QPainter *painter, const QRectF &iconRect, qreal gridUnit) {

           painter->setRenderHints(QPainter::Antialiasing, true);

        button->setPenWidth(painter, gridUnit, 1.10);
        
        QPointF center = iconRect.center();


                    if( button->isChecked() )
                    {


                        painter->drawPolygon( QVector<QPointF>{
                            QPointF(iconRect.left(), center.y()),
                            QPointF(center.x(), iconRect.top()),
                            QPointF(iconRect.right(), center.y()),
                            QPointF(center.x(), iconRect.bottom()),
                        });
                    } else {
                        float top = (iconRect.top() + center.y()) / 2; 
                        float bottom = (iconRect.bottom() + center.y()) / 2; 
                        painter->drawPolyline( QVector<QPointF>{
                            QPointF(iconRect.left(), bottom),
                            QPointF(center.x(), top),
                            QPointF(iconRect.right(), bottom),
                        });
                    }
    }
};

} // namespace Material
