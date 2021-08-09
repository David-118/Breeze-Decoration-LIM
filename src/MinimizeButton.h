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

class MinimizeButton
{

public:
    static void init(Button *button, KDecoration2::DecoratedClient *decoratedClient) {
        QObject::connect(decoratedClient, &KDecoration2::DecoratedClient::minimizeableChanged,
                button, &Button::setVisible);

        button->setVisible(decoratedClient->isMinimizeable());
    }
    static void paintIcon(Button *button, QPainter *painter, const QRectF &iconRect, const qreal gridUnit) {
        Q_UNUSED(button)
        Q_UNUSED(gridUnit)

        const QPointF origin= iconRect.topLeft() - QPointF(5,5);
        painter->drawPolyline( QVector<QPointF>{
            origin + QPointF( 4, 7 ),
            origin + QPointF( 9, 12 ),
            origin + QPointF( 14, 7 ) });
        
    }
};

} // namespace Material
