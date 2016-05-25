#pragma once
#include <memory>
#include <QString>
#include <QMap>
#include <QVector>

namespace persistence {

struct impl_t;
class Game;
class Hand;
class Participant;
class User;

class DBHandler
{
    std::unique_ptr<impl_t> impl;

    DBHandler();
    ~DBHandler();

public:
    User selectUser(const QString& login);
    bool updateUser(const User& u, const QString& login = "");
    bool addUser(const User& u);
    bool deleteUser(const User& u);
    QMap<QString, User> getUsers();

    Game selectGame (unsigned long gameId);
    bool updateGame(const Game& g);
    bool addGame(const Game& g);
    bool deleteGame(const Game& g);
    QMap<unsigned long, Game> getGames();

    bool updateParticipant(const Participant& p);
    QVector <Participant> getParticipant(QString &login);
    QVector<QString> getPlayers(unsigned long gameId);

    bool updateHand(const Hand& h);
    bool addHand(const Hand& h);
    bool deleteHand(const Hand& h);
    QMap<unsigned long, persistence::Hand> getHands(unsigned long gameId = 0);

    QSet<QString> getLimits();

public:
    static DBHandler* instance();

    void load(const QString& path = default_path());
    void save(const QString& path = default_path());

    static QString default_path() { return "persistence/"; }

    // delete copy and move constructors and assign operators
    DBHandler(DBHandler const&) = delete;             // Copy construct
    DBHandler(DBHandler&&) = delete;                  // Move construct
    DBHandler& operator=(DBHandler const&) = delete;  // Copy assign
    DBHandler& operator=(DBHandler &&) = delete;      // Move assign
};

} //persistence
