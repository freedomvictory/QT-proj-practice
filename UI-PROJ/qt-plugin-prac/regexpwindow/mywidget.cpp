#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPluginLoader>
#include <QMessageBox>
#include <QDir>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    if (! loadPlugin())
    {
        QMessageBox::information(this, "Error", "Could not load the plugin");
        ui->lineEdit->setEnabled(false);
        ui->pushButton->setEnabled(false);
    }
}

myWidget::~myWidget()
{
    delete ui;
}

bool myWidget::loadPlugin()
{
    QDir pluginsDir("../plugins");
    foreach(QString fileName, pluginsDir.entryList(QDir::Files)){
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if(plugin){
            regexpInterface = qobject_cast<RegExpInterface *>(plugin);
            if(regexpInterface)
                return true;
        }
    }
    return false;
}

void myWidget::on_pushButton_clicked()
{
    QString str = regexpInterface->regexp(ui->lineEdit->text());
    ui->labelNum->setText(str);
}
