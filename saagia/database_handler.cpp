#include "database_handler.h"
#include "data_structures.h"
#include <fstream>
#include <sstream>
#include <iostream>

#include <QCborMap>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>

Database_handler::Database_handler(std::shared_ptr<Data_structures> data_structures) :
    data_structures_{ data_structures }
{
}

QString Database_handler::load_data(QString file)
{
    const QString path_start =
    #ifdef _WIN32
        "";
    #else
        "/"; // MacOS requires this
    #endif

    QString path = path_start + file;
    qDebug() << path;

    QFile loadFile(path);

    if ( !loadFile.open(QIODevice::ReadOnly) ) {
        qWarning("Couldn't load file.");
        return "false";
    }

    QString data1 = loadFile.readAll();
    loadFile.close();

    return data1;
}

bool Database_handler::save_data(QString savefile, QString parsedData) const
{
    savefile = savefile.remove(0,8);
    qDebug() << savefile;

    const QString path_start =
    #ifdef _WIN32
        "";
    #else
        "/"; // MacOS requires this
    #endif

    QString file_extension = ".txt";
    QString path = path_start + savefile + file_extension;

    qDebug() << path;

    QFile saveFile(path);

    if ( !saveFile.open(QIODevice::WriteOnly) ) {
        qWarning("Couldn't open save file.");
        return false;
    }
    else {
        saveFile.write(parsedData.toUtf8());
        saveFile.close();
    }

    return true;
}

std::vector<std::string> Database_handler::read_municipalities(){

    QString data;

    QFile file(DEFAULT_MUNICIPALITIES_FILE);
    if ( !file.open(QIODevice::ReadOnly) ) {
        qDebug() << "file not opened";
    }
    else {
        qDebug() << "file opened";
        data = file.readAll();
    }

    file.close();

    QStringList data_splitted = data.split( "," );

    std::vector<std::string> municipalities;

    for( auto& str : data_splitted ) {
        municipalities.push_back(str.toStdString());
    }

    return municipalities;
}
