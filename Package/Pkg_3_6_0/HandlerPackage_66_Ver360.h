#ifndef HANDLERPACKAGE_66_VER360_H
#define HANDLERPACKAGE_66_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_66_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_66_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_nidTsr;

protected:
    void loadPkg() override;
private slots:


private:
    void showVariable();
    qint16 m_currCol;
    qint16 m_row ;


};
}

#endif // HANDLERPACKAGE_2_VER360_H
