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

// This is copied from savegame example, has to be modified further for our use

QString Database_handler::load_data(QString file)
{
    QFile loadFile(file);

    if ( !loadFile.open(QIODevice::ReadOnly) ) {
        qWarning("Couldn't open save file.");
        return "false";
    }

    QString data1 = loadFile.readAll();

    return data1;
}

bool Database_handler::save_data(QString savefile, QString parsedData) const
{
    savefile = savefile.remove(0,8);
    qDebug() << savefile;
    // Nimi tulee qml:puolelta muodossa file:///.../filename

    QFile saveFile(savefile);

    if ( !saveFile.open(QIODevice::WriteOnly) ) {
        qWarning("Couldn't open save file.");
        return false;
    }
    else
    {
        saveFile.write(parsedData.toUtf8());
        saveFile.close();
    }


    return true;
}

void Database_handler::read(const QJsonObject &json)
{

}

void Database_handler::write(QJsonObject &json) const
{

}

std::vector<std::string> Database_handler::read_municipalities(){

    QString data;
    //QString fileName(":/settings/municipalities.txt");

    QFile file(DEFAULT_MUNICIPALITIES_FILE);
    if( !file.open(QIODevice::ReadOnly) ) {
        qDebug()<<"file not opened";
    }
    else
    {
        qDebug()<<"file opened";
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

