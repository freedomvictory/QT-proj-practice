#include <QJsonDocument>
#include <QJsonObject> 
#include <QJsonValue>
#include <QObject> 
#include <QtTest/QtTest> 
#include <QDebug> 
#include <QIODevice> 


class TestJson : public QObject 
{
    Q_OBJECT
private slots:
    void initTestCase(){

    };

    void TestReadJsonFile(); 
    void TestWriteJsonFile(); 
    void TestReadModeInfoJson();
    void TestWriteModeInfoJson(); 
};
/* test.json 
{
    "appDesc": {
        "description": "SomeDescription",
        "message": "SomeMessage"
    },
    "appName": {
        "description": "WRITE IT!",
        "imp": [
            "awesome",
            "best",
            "good"
        ],
        "message": "Welcome"
    }
}
*/
void TestJson::TestReadJsonFile() 
{
    QString val; 
    QFile file; 
    file.setFileName("test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll(); 
    file.close(); 

    qWarning() << val; 
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object(); 
    QJsonValue value = sett2.value(QString("appName"));
    qWarning() << tr("value of [apppName]") << value; 
    QJsonObject item = value.toObject(); 
    qWarning() << tr("QJsonObejct of description:") << item; 

    qWarning() << tr("QJsonObject[appName] of description: ") << item["description"];
    QJsonValue subobj = item["description"];
    qWarning() << subobj.toString(); 

}




void TestJson::TestWriteJsonFile()
{
    QFile file("test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonParseError JsonParseError; 
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    file.close(); 

    QJsonObject RootObject = JsonDocument.object(); 
    QJsonValueRef ref = RootObject.find("appName").value();

    QJsonObject m_addvalue = ref.toObject(); 
    m_addvalue.insert("description", "WRITE IT!");
    ref = m_addvalue; 

    JsonDocument.setObject(RootObject); 

    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(JsonDocument.toJson());
    file.close(); 
}
/* ModeInfo.json 
{
    "AirPurgeArg": {
        "mode": 0,
        "time": 5
    },
    "BasicFlows": {
        "CarrierGas": 16,
        "air": 220,
        "hydrogen": 45
    },
    "BasicTempratures": {
        "catalyticConverter": 180,
        "decetor": 180
    },
    "CatalyticActivation": {
        "temprature": 240,
        "time": 180
    },
    "Fire": {
        "NumOfAttempts": 6,
        "threshold": 8
    },
    "sampleAnalysisEvents": [
        {
            "action": "on",
            "dev": "bigPump",
            "time": 0.02
        },
        {
            "action": "off",
            "dev": "smallPump",
            "time": 0.04
        }
    ]
}
*/
void TestJson::TestReadModeInfoJson()
{
    QFile file("ModeInfo.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonParseError JsonParseError; 
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    file.close();

    QJsonObject RootObject = JsonDocument.object(); 
    //use [] operator access data item 
    auto array = RootObject["sampleAnalysisEvents"].toArray();
    for(int i = 0; i < array.size(); i++)
    {
        QJsonObject events_obj = array[i].toObject();
        auto dev = events_obj["dev"].toString();
        auto time = events_obj["time"].toDouble(); 
        auto action = events_obj["action"].toString(); 
        qDebug() << "by [] dev, time, action :" << dev << "," << time << "," << action; 
    }

    //use iterator traverse data item (object, bool, array, int, string, double)
    for(auto p = RootObject.begin(); p != RootObject.end(); p++)
    {
        //qDebug() << "ModeInfo-object.type:" << p.value().type();
        if(p.value().type() == QJsonValue::Array)
        {
            //do something 
        }
    } 
}

void TestJson::TestWriteModeInfoJson()
{
    QFile file("ModeInfo.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonParseError JsonParseError; 
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    file.close();
    QJsonObject RootObject = JsonDocument.object(); 
    //read the fire obj , and change the data of fire obj  
    QJsonObject fire_obj =  RootObject["Fire"].toObject();
    fire_obj["threshold"] = 8;
    //change the root obj [fire] item 
    RootObject["Fire"] = fire_obj;

    JsonDocument.setObject(RootObject); 

    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(JsonDocument.toJson());
    file.close(); 

}

QTEST_MAIN(TestJson)

#include "testjson.moc"