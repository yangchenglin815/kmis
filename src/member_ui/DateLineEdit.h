#ifndef DATELINEEDIT_H
#define DATELINEEDIT_H

#include <QLineEdit>

class DateLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit DateLineEdit(QWidget *parent = 0);

    void initData();
    void deleteValue();
    void addValue( QString strText );
protected:
    void keyPressEvent( QKeyEvent *event );
public slots:
    void slot_enter();
private slots:
    void slot_cursorPosChanged(int nOldPos, int nNewPos);
private:
    void initCtrl();
    void initConnect();

    bool updateYear(QString strText);
    bool updateMonth(QString strText);
    bool updateDay(QString strText);
    void modifyDayFromMonth();
    int firstPointPos();
    int secondPointPos();
private:
    QString m_sDate;
};

#endif // DATELINEEDIT_H
