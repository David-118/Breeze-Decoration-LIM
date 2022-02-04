/*
 * Copyright (C) 2020 Chris Holland <zrenfire@gmail.com>
 * Copyright (C) 2012 Martin Gräßlin <mgraesslin@kde.org>
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

// KF
#include <KCModule>

// Qt
#include <QColor>
#include <QWidget>

namespace Material
{

class ConfigurationModule : public KCModule
{
    Q_OBJECT
public:
    ConfigurationModule(QWidget *parent, const QVariantList &args);

private:
    void init();

    int m_titleAlignment;
    int m_buttonSize;
    double m_activeOpacity;
    double m_inactiveOpacity;
    bool m_menuAlwaysShow;
    int m_menuButtonHorzPadding;
    bool m_animationsEnabled;
    int m_animationsDuration;
    int m_shadowSize;
    int m_shadowStrength;
    QColor m_shadowColor;
    bool m_circleClose;
};

} // namespace Material
