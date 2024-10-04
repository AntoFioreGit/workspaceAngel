#ifndef GRAPHICBTNPACKAGE_BL_3_6_0
#define GRAPHICBTNPACKAGE_BL_3_6_0

#include "GraphicBtnPackage.h"

namespace pkg{

const QColor defaultColorBL_3_6_0 (0,0,0);
const QColor defaultBackColorBL_3_6_0 (204,255,204);
class GraphicBtnPackage_BL_3_6_0 : public GraphicBtnPackage
{
    Q_OBJECT

public:
    explicit GraphicBtnPackage_BL_3_6_0(QObject *parent = nullptr);
   void init(QWidget *parent=nullptr);
   void addAction(QString text, int actBtnId);


protected slots:
    void handleActionToggled_SL(int idAction, bool checked) override;
    void handleActionPush_SL (int idAction) override ;
private:




};
}
#endif // GRAPHICBTNPACKAGE_BL_3_6_0
