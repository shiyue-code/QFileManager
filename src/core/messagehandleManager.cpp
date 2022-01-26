#include "messagehandle.h"

MessageHandle::MessageHandle()
{

}

QJsonObject MessageHandle::send(const QJsonObject &obj)
{
    qDebug() << obj;
        return QJsonObject();
}

QJsonObject MessageHandle::post(const QJsonObject &obj)
{
    qDebug() << obj;
    return QJsonObject();
}
