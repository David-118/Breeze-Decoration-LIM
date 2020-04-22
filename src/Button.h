/*
 * Copyright (C) 2020 Chris Holland <zrenfire@gmail.com>
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

// KDecoration
#include <KDecoration2/Decoration>
#include <KDecoration2/DecorationButton>

namespace Material
{

class Decoration;

class Button : public KDecoration2::DecorationButton
{
    Q_OBJECT

public:
    Button(KDecoration2::DecorationButtonType type, Decoration *decoration, QObject *parent = nullptr);
    ~Button() override;

    // Passed to DecorationButtonGroup in Decoration
    static KDecoration2::DecorationButton *create(KDecoration2::DecorationButtonType type, KDecoration2::Decoration *decoration, QObject *parent = nullptr);

    // This is called by:
    // registerPlugin<Material::Button>(QStringLiteral("button"))
    // It is needed to create buttons for applet-window-buttons.
    explicit Button(QObject *parent, const QVariantList &args);

    void paint(QPainter *painter, const QRect &repaintRegion) override;
    virtual void paintIcon(QPainter *painter, const QRectF &iconRect);

    virtual void setHeight(int titleBarHeight);

    virtual QColor backgroundColor() const;
    virtual QColor foregroundColor() const;
};

} // namespace Material
