#ifndef SALEAGENT_H
#define SALEAGENT_H

#include <QObject>

class SaleAgent : public QObject
{
    Q_OBJECT
public:
    explicit SaleAgent(QObject *parent = 0);

signals:

public slots:
};

#endif // SALEAGENT_H
