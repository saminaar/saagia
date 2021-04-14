#include "database_handler.h"
#include "data_structures.h"

#include <QCborMap>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>

Database_handler::Database_handler(std::shared_ptr<Data_structures> data_structures) :
    data_structures_{ data_structures }
{

}

// This is copied from savegame example, has to be modified further for our use

bool Database_handler::load_data()
{
    QFile loadFile(QStringLiteral("save.json"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    read(loadDoc.object());

    QTextStream(stdout) << "Loaded save for "
                        << loadDoc["player"]["name"].toString()
                        << " using "
                        << "JSON" << "...\n";
    return true;
}

bool Database_handler::save_data(QString start_time, int data_type) const
{
    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject gameObject;
    write(gameObject);
    saveFile.write(QJsonDocument(gameObject).toJson());

    return true;
}

void Database_handler::read(const QJsonObject &json)
{

}

void Database_handler::write(QJsonObject &json) const
{

}
