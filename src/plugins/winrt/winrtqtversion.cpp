/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#include "winrtqtversion.h"

#include "winrtconstants.h"

#include <coreplugin/featureprovider.h>
#include <qtsupport/qtsupportconstants.h>

namespace WinRt {
namespace Internal {

WinRtQtVersion::WinRtQtVersion()
{
}

WinRtQtVersion::WinRtQtVersion(const Utils::FileName &path, bool isAutodetected,
        const QString &autodetectionSource)
    : BaseQtVersion(path, isAutodetected, autodetectionSource)
{
    setUnexpandedDisplayName(defaultUnexpandedDisplayName(path, false));
}

QtSupport::BaseQtVersion *WinRtQtVersion::clone() const
{
    return new WinRtQtVersion(*this);
}

QString WinRtQtVersion::type() const
{
    return QLatin1String(Constants::WINRT_WINRTQT);
}

QString WinRtQtVersion::description() const
{
    return tr("Windows Runtime");
}

Core::FeatureSet WinRtQtVersion::availableFeatures() const
{
    Core::FeatureSet features = QtSupport::BaseQtVersion::availableFeatures();
    features |= Core::FeatureSet(QtSupport::Constants::FEATURE_MOBILE);
    features.remove(Core::Feature(QtSupport::Constants::FEATURE_QT_CONSOLE));
    features.remove(Core::Feature(QtSupport::Constants::FEATURE_QT_QUICK_1));
    features.remove(Core::Feature(QtSupport::Constants::FEATURE_QT_WEBKIT));
    return features;
}

QString WinRtQtVersion::platformName() const
{
    return QLatin1String(QtSupport::Constants::WINDOWS_RT_PLATFORM);
}

QString WinRtQtVersion::platformDisplayName() const
{
    return QLatin1String(QtSupport::Constants::WINDOWS_RT_PLATFORM_TR);
}

QList<ProjectExplorer::Abi> WinRtQtVersion::detectQtAbis() const
{
    return qtAbisFromLibrary(qtCorePaths(versionInfo(), qtVersionString()));
}

} // Internal
} // WinRt
