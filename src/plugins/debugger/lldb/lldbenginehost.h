/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://qt.nokia.com/contact.
**
**************************************************************************/

#ifndef DEBUGGER_LLDBENGINE_HOST_H
#define DEBUGGER_LLDBENGINE_HOST_H

#include "ipcenginehost.h"

#include <QtCore/QProcess>

namespace Debugger {
namespace Internal {

class LldbEngineHost : public IPCEngineHost
{
    Q_OBJECT

public:
    explicit LldbEngineHost(const DebuggerStartParameters &startParameters);
    ~LldbEngineHost();

private:
    QProcess *m_guestProcess;

private slots:
    void finished(int, QProcess::ExitStatus);
};

} // namespace Internal
} // namespace Debugger

#endif // DEBUGGER_LLDBENGINE_HOST_H
