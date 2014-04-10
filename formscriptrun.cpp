#include "formscriptrun.h"
#include "ui_formscriptrun.h"

#include <QDebug>
#include <QDateTime>
#include "Script/scriptengine.h"

FormScriptRun::FormScriptRun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormScriptRun)
{
    ui->setupUi(this);
    ui->splitter->setSizes( QList < int > () << INT_MAX );
}

FormScriptRun::~FormScriptRun()
{
    delete ui;
}

void FormScriptRun::on_tButtonRunScript_clicked()
{
    const QString & script = ui->textEditScript->toPlainText();
    const QString & log = Script::ScriptEngine::instance()->evaluate( script ).toString();

    ui->textEditLog->append( QDateTime::currentDateTime().toString() );
    ui->textEditLog->append( log );
}
