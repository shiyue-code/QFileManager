#ifndef MESSAGEHANDLE_H
#define MESSAGEHANDLE_H


#include <QObject>
#include <QJsonObject>

class MessageHandle : public QObject
{
    Q_OBJECT
public:
    explicit MessageHandle();


public slots:
    QJsonObject send(const QJsonObject& array);
    QJsonObject post(const QJsonObject& array);
};

#endif // MESSAGEHANDLE_H
