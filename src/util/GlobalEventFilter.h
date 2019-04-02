#ifndef GLOBALEVENTFILTER_H
#define GLOBALEVENTFILTER_H

#include <QObject>

class GlobalEventFilter : public QObject
{
    Q_OBJECT

public:
    explicit GlobalEventFilter();
    ~GlobalEventFilter();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void sigMouseChanged();

};

#endif // GLOBALEVENTFILTER_H
