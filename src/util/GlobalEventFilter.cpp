#include "GlobalEventFilter.h"
#include <QEvent>

GlobalEventFilter::GlobalEventFilter()
{

}

GlobalEventFilter::~GlobalEventFilter()
{

}

bool GlobalEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    switch( event->type() ) {
    case QEvent::MouseButtonPress:
        emit sigMouseChanged();
        break;
    case QEvent::MouseMove:
        emit sigMouseChanged();
        break;
    default:
        break;
    }
    return QObject::eventFilter(obj,event);
}
