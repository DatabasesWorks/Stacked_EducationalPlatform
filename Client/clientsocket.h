#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <QString>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    ClientSocket(sf::IpAddress host, int portnumber);
    ~ClientSocket();
    bool connect(unsigned int port);
    bool authenticate(QString username, QString payload);
     void sendPayload(QString payload);
private:
    unsigned int sessionId = 0;
    unsigned int portnumber = 0;
    sf::IpAddress host;
    boolean authenticated = false;
    QString waitForResponse();
};

#endif // CLIENTSOCKET_H

