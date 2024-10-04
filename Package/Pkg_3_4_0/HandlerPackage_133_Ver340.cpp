#include "HandlerPackage_133_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_133_Ver340::HandlerPackage_133_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;

    m_qScaleVar = nullptr;
    m_qRiuVar = nullptr;
    m_nidC_1_Var = nullptr;
    m_nidRiuVar = nullptr;
    m_nidRadioVar = nullptr;
    m_dInfillVar = nullptr;
    m_nidC_2_Var = nullptr;
    m_nidBgVar = nullptr;


    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg = 133;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_133_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    bool ret=false;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 133 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(153,153);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );

        m_qScaleVar =  new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );

        m_qRiuVar =  new package::GraphicVariablePkg ;
        m_qRiuVar->set_Q_RIU();
        m_VariableVect.push_back(m_qRiuVar);
        connect (m_qRiuVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );

        m_nidC_1_Var =  new package::GraphicVariablePkg ;
        m_nidC_1_Var->set_NID_C();
        m_nidC_1_Var->setNameVariable("NID_C_1");
        m_VariableVect.push_back(m_nidC_1_Var);
        connect (m_nidC_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );

        m_nidRiuVar =  new package::GraphicVariablePkg ;
        m_nidRiuVar->set_NID_RIU();
        m_VariableVect.push_back(m_nidRiuVar);
        connect (m_nidRiuVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );

        m_nidRadioVar =  new package::GraphicVariablePkg ;
        m_nidRadioVar->set_NID_RADIO();
        m_VariableVect.push_back(m_nidRadioVar);
        connect (m_nidRadioVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );

        m_dInfillVar =  new package::GraphicVariablePkg ;
        m_dInfillVar->set_D_INFILL();
        m_VariableVect.push_back(m_dInfillVar);
        connect (m_dInfillVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );

        m_nidC_2_Var =  new package::GraphicVariablePkg ;
        m_nidC_2_Var->set_NID_C();
        m_nidC_2_Var->setNameVariable("NID_C_2");
        m_VariableVect.push_back(m_nidC_2_Var);
        connect (m_nidC_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );

        m_nidBgVar =  new package::GraphicVariablePkg ;
        m_nidBgVar->set_NID_BG();
        m_VariableVect.push_back(m_nidBgVar);
        connect (m_nidBgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_133_Ver340::saveData );



        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();
        ret=saveData();

    }
    return ret;

}

void HandlerPackage_133_Ver340::loadPkg()
{
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    QString var;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);

        if (dataList.size() >= m_VariableVect.size())
        {
            for (int idx = 0; idx < m_VariableVect.size(); idx++) {
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                if (nullptr != p_variable){
                    var = dataList.at(idx);
                    if (var != EMPTY_VALUE){
                        p_variable->setDefaultValue(var.toInt());
                        p_variable->setTobeVisible(true);
                    } else {
                        p_variable->setTobeVisible(false);
                    }
                }
            }
        }

    }

}


void HandlerPackage_133_Ver340::showVariable()
{
    m_row=1;
    m_currCol=0;

    qint16 actualPktSize = this->countPacketBitSize();
    m_lenPkgVar->setDefaultValue(actualPktSize);

    removeSpacer();
    qint16 totVar = m_VariableVect.size();
    for (qint16 i =0; i < totVar;i++)
    {
        if (qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i))->tobeVisible()){
            m_layOutPkg->addWidget(m_VariableVect.at(i),m_row,m_currCol);
            m_VariableVect.at(i)->setVisible(true);
            if (m_currCol >m_maxColumnVariable )
            {
                m_currCol=0;
                m_row++;
            } else {
                m_currCol++;

            }
        } else {
            m_VariableVect.at(i)->setVisible(false);

        }
    }
    m_spaced = new QSpacerItem (40,80,QSizePolicy::Expanding,QSizePolicy::Expanding) ;
    m_layOutPkg->addItem(m_spaced, m_row+1,m_maxColumnVariable+1);

}


bool HandlerPackage_133_Ver340::saveData()
{

    QString data;
    package::GraphicVariablePkg * p_variable = nullptr;

    for (int idx = 0; idx < this->m_VariableVect.size(); idx++)
    {
        p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
        if (p_variable->tobeVisible()){
            data += p_variable->valueOfVariable();
        } else {
            data += EMPTY_VALUE;
        }
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
    }

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;

    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;

}

void HandlerPackage_133_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}



}
