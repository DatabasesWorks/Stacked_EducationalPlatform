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
    ClientSocket(sf::IpAddress host);
    ~ClientSocket();
    bool connect(unsigned int port);
    bool authenticate(QString username, QString payload);
    QString waitForResponse();
    void sendPayload(QString payload);
    void close();
private:
    unsigned int sessionId = -1;
    unsigned int portnumber = 0;
    sf::IpAddress host;
    sf::TcpListener listener;
    sf::TcpSocket *socket;//so the socket can be disposable
    boolean isConnected = false;
    boolean authenticated = false;
};

#endif // CLIENTSOCKET_H

