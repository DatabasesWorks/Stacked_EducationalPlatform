#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <QString>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <QObject>

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    ClientSocket(QString host, int portnumber);
    ~ClientSocket();
    QString authenticate(QString username, QString payload);
    QString sendPayload(QString payload);
private:
    unsigned int sessionId = 0;
    unsigned int portnumber = 0;
    sf::IpAddress host;
    bool authenticated = false;
    QString waitForResponse();
};

#endif // CLIENTSOCKET_H

