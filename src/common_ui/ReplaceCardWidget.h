#ifndef REPLACECARDWIDGET_H
#define REPLACECARDWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include "structData.h"

namespace Ui {
class ReplaceCardWidget;
}

class ReplaceCardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReplaceCardWidget(QWidget *parent = 0);
    ~ReplaceCardWidget();

    void initData();
    void setMemRegInfo( const MemRegisterInfo_s &stMemRegInfo );
    void setMemTypeInfo(  QMap<int, MemTypeInfo_s>  mapMemTypeInfo );
    QLineEdit *getCardIdEdit();
    QString getCardId();
signals:
    void sig_replaceMemCard( QString strOldCardId, QString strNewCardId );
    void sig_replaceQuest();
public slots:
    void slot_replaceMemCard( int nCode, QString strMsg, QString strOldCardId, QString strNewCardId );
private:
    void initConnect();
private:
    Ui::ReplaceCardWidget *ui;

    MemRegisterInfo_s m_stMemRegInfo;
    QMap<int, MemTypeInfo_s>  m_mapMemTypeInfo;
};

#endif // REPLACECARDWIDGET_H
